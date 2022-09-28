inline Config::Config(std::string const &fname, Casing sType, Comment cType)
:
    Config(FBB::Exception::factory<std::ifstream>(fname), 
            sType, cType)
{}
