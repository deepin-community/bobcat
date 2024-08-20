inline FBB::MailHeaders::const_hdr_iterator
&FBB::MailHeaders::const_hdr_iterator::operator++()
{
    d_current = lookup(++d_current);
    return *this;
}
