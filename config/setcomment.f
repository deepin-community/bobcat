inline void CF_Pimpl::setComment(Comment type)
{
    d_rmComment = type == NoComment;
}

inline void Config::setComment(Comment type)
{
    d_ptr->setComment(type);
}

