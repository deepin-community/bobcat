inline Config::Config(Casing sType, Comment cType)
:
    d_ptr(new CF_Pimpl(sType, cType))
{}

