inline FBB::MailHeaders::const_hdr_iterator FBB::MailHeaders::beginh() const
{
    return const_hdr_iterator(this, begin());
                                        // returns iterator over all headers
                                        // matching d_hdr by the d_match type
}
