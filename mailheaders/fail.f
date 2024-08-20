inline bool FBB::MailHeaders::const_hdr_iterator::fail(
                                    std::string const &hdr, std::string const &key)
{
    throw Exception(1) << "MailHeaders: setHeaderIterator() not called";
    return false;       // not reached
}
