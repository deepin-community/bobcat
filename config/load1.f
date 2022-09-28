inline void Config::load(std::string const &fname)
{
    load(FBB::Exception::factory<std::ifstream>(fname), 1);
}
