template <typename StreamType>
StreamType Exception::factory(int errnoValue, std::string const &name, 
                             std::ios::openmode mode)
{
    StreamType stream{ name, mode };

    if (!stream)
        throw Exception{errnoValue} << "Can't open `" << name << '\'';

    return stream;
}











