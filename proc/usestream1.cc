#include "proc.ih"

                                        // bit is set in d_mode
void Proc::useStream(std::ostream &str, IOMode bit) 
{
    use(bit) = Out{ &str };
}






