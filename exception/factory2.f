template <typename StreamType>
StreamType Exception::factory(int errnoValue, std::string const &name)
{
    StreamType stream{ name };

    if (!stream)
        throw Exception{errnoValue} << "Can't open `" << name << '\'';

    return stream;
}











