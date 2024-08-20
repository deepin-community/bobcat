#include "proc.ih"

void Proc::Activator::add(Proc &proc)
{
    if (not d_procPtr.empty())
    {
        if (
            find(d_procPtr.begin(), d_procPtr.end(), &proc) 
            != 
            d_procPtr.end()
        )
            throw Exception{} << 
                    "All Proc objects in 'proc1 | proc2' must be different";

        if (
            not (d_procPtr.back()->d_mode & (COUT | MERGE_COUT_CERR))
            or
            not (proc.d_mode & CIN)
        )
            throw Exception{} <<
            "At 'proc1 | proc2' COUT is required for proc1 and CIN for proc2";

        Proc &back = *d_procPtr.back();         // see the proc header file
        back.d_mode |= COUT;
//        back.d_mode &= ~(IGNORE_COUT | CERR | IGNORE_CERR | MERGE_COUT_CERR);
    }

//    proc.d_mode &= ~(IGNORE_COUT | CERR | IGNORE_CERR | MERGE_COUT_CERR);
    d_procPtr.push_back(&proc);        // store the Proc objects in sequence

    size_t nPipes = d_pipesPtr->size() + 2;
    d_pipesPtr->resize(nPipes);         // add two new pipes
    proc.pipes(d_pipesPtr, nPipes);     // set proc's pipes
}




