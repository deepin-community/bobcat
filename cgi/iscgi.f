inline int FBB::CGIFSA::iscgi(int ch)
{
    return s_cgi.find(ch) != std::string::npos;
}
