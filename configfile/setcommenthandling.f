inline void ConfigFile_::setCommentHandling(Comment type)
{
    d_rmComment = type == RemoveComment;
}
