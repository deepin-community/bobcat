inline CF_Types::CIVectIteratorPair CF_Pimpl::beginEndRE(std::string const &re)
{
    return beginEnd(re, &CF_Pimpl::findRE);
}

inline Config::CIVectIteratorPair Config::beginEndRE(
                                                std::string const &re) const
{
    return d_ptr->beginEndRE(re);
}
