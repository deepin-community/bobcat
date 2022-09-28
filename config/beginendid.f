inline CF_Types::CIVectIteratorPair CF_Pimpl::beginEndID(std::string const &re)
{
    return beginEnd(re, &CF_Pimpl::findID);
}

inline Config::CIVectIteratorPair Config::beginEndID(
                                                std::string const &id) const
{
    return d_ptr->beginEndID(id);
}
