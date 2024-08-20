inline bool FBB::MailHeaders::const_hdr_iterator::partial(
                                    std::string const &hdr, std::string const &key)
{
    return hdr.substr(0, hdr.find(':')).find(key) != std::string::npos;
}
