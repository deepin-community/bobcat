inline FBB::MailHeaders::const_hdr_iterator
FBB::MailHeaders::const_hdr_iterator::operator++(int)
{
    return const_hdr_iterator(d_mh, d_current++);
}
