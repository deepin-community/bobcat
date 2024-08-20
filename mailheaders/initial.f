inline bool FBB::MailHeaders::const_hdr_iterator::initial(
                                    std::string const &hdr, std::string const &key)
{
    return hdr.substr(0, hdr.find(':')).find(key) == 0;
}
