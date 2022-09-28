inline void CF_Pimpl::setCasing(Casing type)
{
    d_caseSensitive = type == UseCase;
}

inline void Config::setCasing(Casing type)
{
    d_ptr->setCasing(type);
}

