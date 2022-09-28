template <typename StreamType>
StreamType Exception::factory(int errnoValue, std::string const &name, 
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
        throw Exception{errnoValue} << "Can't open `" << name << '\'';

    return ret;
}
