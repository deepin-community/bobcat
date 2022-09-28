template <typename StreamType>
StreamType Exception::factory(std::string const &name, 
                              std::ios::openmode mode1,
                              std::ios::openmode mode2)
{
    StreamType ret{ name, mode1 };

    if (not ret)
    {
        ret.clear();
        ret.open(name, mode2);
    }

    if (!ret)
        throw Exception{} << "Can't open `" << name << '\'';

    return ret;
}
