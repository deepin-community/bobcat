#include "proc.ih"

void Proc::output(Out &out)
{
    struct Variables
    {
        IOMode useBits;
        unsigned threadBit;
        size_t pipeIdx;             // read or write pipe idx
        IOMode ignoreBit;           // if set, info goes to s_ignored
        unsigned setBit;            // d_admin's bit to check
        ostream &stdOut;            // default ostream to use
        thread &thr;                // thread running threadFun
        void (Proc::*threadFun)();  // thread fun handling the output
    };

    Variables vars = 
        &out == &d_out ?
            Variables{ 
                        COUT | MERGE_COUT_CERR | IGNORE_COUT,   // useBits  
                        THREAD_OUT,                             // threadBit
                        d_writeOut,                             // pipeIdx  
                        IGNORE_COUT,                            // ignoreBit
                        USE_OUT,                                // setBit   
                        cout,                                   // stdOut   
                        d_outThread,                            // thr      
                        &Proc::toOut }                          // threadFun
        :
            Variables{ 
                        CERR | IGNORE_CERR,                     // useBits  
                        THREAD_ERR,                             // threadBit
                        d_writeErr,                             // pipeIdx  
                        IGNORE_CERR,                            // ignoreBit
                        USE_ERR,                                // setBit   
                        cerr,                                   // stdOut   
                        d_errThread,                            // thr      
                        &Proc::toErr };                         // threadFun


    if (not (d_mode & vars.useBits))
    {
        d_admin &= ~vars.threadBit;
        closePipe(vars.pipeIdx);
        return;
    }

    d_admin |= vars.threadBit;      // cout is used, so start its thread

    if (d_mode & vars.ignoreBit)    // when ignored: output to s_ignore
        out = Out{ &s_ignored }; 
    else if (not (d_admin & vars.setBit))   // or use the default, unless
        out = Out{ &vars.stdOut };          // already specified

    vars.thr =  thread{ vars.threadFun, this }; 
}





