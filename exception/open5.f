template <typename StreamType>
void Exception::open(StreamType &stream, std::string const &name,
                     std::ios::openmode mode1, std::ios::openmode mode2)
{
    if (stream.is_open())
        stream.close();

    stream.open(name, mode1);
    if (!stream)
    {
        stream.clear();
        stream.open(name, mode2);
    }

    if (!stream)
        throw Exception{} << "Can't open `" << name << '\'';
}
