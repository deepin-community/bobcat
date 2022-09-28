inline Config::Config(std::istream  &stream, uint16_t lineNr,
                      Casing sType, Comment cType)
:
    d_ptr(new CF_Pimpl(stream, lineNr, sType, cType))
{}


