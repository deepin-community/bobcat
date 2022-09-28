inline OMutexStream::Out::Out(Out &&tmp)
:
    std::ostream(tmp.rdbuf())
{}
