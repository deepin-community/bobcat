inline void FBB::ConfigFile_::setCommentHandling(Comment type)
{
    d_rmComment = type == RemoveComment;
}
