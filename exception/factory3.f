template <typename StreamType>
StreamType Exception::factory(std::string const &name, 
                             std::ios::openmode mode)
{
    StreamType stream{ name, mode };

    if (!stream)
        throw Exception{} << "Can't open `" << name << '\'';

    return stream;
}











