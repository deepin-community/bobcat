inline Config::Config(std::istream  &&stream, Casing sType, Comment cType)
:
    Config(stream, 1, sType, cType)
{}


