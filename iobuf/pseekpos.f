inline IOBuf::pos_type IOBuf::pSeekpos(pos_type offset, 
                         std::ios::openmode mode)
{
    return seekoff(offset, std::ios::beg, mode);
}
