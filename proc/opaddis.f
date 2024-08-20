inline Proc &Proc::operator+=(std::string const &txt)
{
    d_cmd += txt;
    return *this;
}
