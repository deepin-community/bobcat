inline Config::Config(Config const &rhs)
:
    d_ptr(new CF_Pimpl(*rhs.d_ptr))
{}
