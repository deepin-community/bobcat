template <typename StreamType>
StreamType Exception::factory(std::string const &name)
{
    StreamType stream{ name };

    if (!stream)
        throw Exception{} << "Can't open `" << name << '\'';

    return stream;
}











