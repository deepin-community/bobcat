#include "proc.ih"

void Proc::useStream(std::string const &fname, IOMode bit) 
{
    use(bit) = 
        Out{ new ofstream{ Exception::factory<ofstream>(fname) }, true };
}
