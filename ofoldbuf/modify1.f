inline std::ostream &lm::modify(std::ostream &out) const
{
    dynamic_cast<OFoldBuf &>(*out.rdbuf()).setIndent(d_value);
    return out;
}        
