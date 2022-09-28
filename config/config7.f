inline Config::Config(Config &&tmp)
:
    d_ptr( new CF_Pimpl(std::move(*tmp.d_ptr) ))
{}
