inline bool FBB::MailHeaders::const_hdr_iterator::caseInitial(
                                    std::string const &hdr, std::string const &key)
{
    return String::lc(hdr.substr(0, hdr.find(':'))).find(key) == 0;
}
