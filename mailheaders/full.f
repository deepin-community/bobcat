inline bool FBB::MailHeaders::const_hdr_iterator::full(
                                    std::string const &hdr, std::string const &key)
{
    return hdr.substr(0, hdr.find(':')) == key;
}
