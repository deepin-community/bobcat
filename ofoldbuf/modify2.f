inline std::ostream &mlm::modify(std::ostream &out) const
{
    dynamic_cast<OFoldBuf &>(*out.rdbuf()).modifyIndent(d_value);
    return out;
}        
