#include "proc.ih"

Proc::ExecContext Proc::analyzeCmd() const
{
                                // split the elements in d_cmd
    String::Type type;
    vector<string> elements(String::split(&type, d_cmd));

    if (type != String::NORMAL)
        throw Exception{} << "Proc: " << d_cmd << ": ill-formed";

    ExecContext ec = {0, new char const *[elements.size() + 1]};

    for (auto str: elements)    // copy the elements to ec.args
        ec.argv[ec.argc++] = 
            (new string(str))->c_str();
        // the allocated memory is never returned, but that's OK as the
        // program's execution ends and the args are passed over to the child
        // proc. 

    ec.argv[ec.argc] = 0;   // terminate in a null ptr
     
    return ec;
}




