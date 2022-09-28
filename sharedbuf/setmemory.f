inline void SharedBuf::setMemory(SharedMemory &&tmp)
{
    d_memory = std::move(tmp);
}
