inline std::string const *FBB::MailHeaders::const_hdr_iterator::operator->() const
{
    return &*d_current;
}
