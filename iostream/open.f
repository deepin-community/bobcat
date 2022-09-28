inline void IOStream::open(std::istream &in, std::ostream &out)
{
    IOBuf::reset(in, out);
}
