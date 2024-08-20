inline FBB::MailHeaders::const_hdr_iterator FBB::MailHeaders::endh() const
{
                                        // returns address of the sentinel
    return const_hdr_iterator(this, end());
}
