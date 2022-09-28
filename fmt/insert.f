inline std::ostream &FMT::insert(std::ostream &out) const
{
    return out << "align: " << s_align[d_align] << 
                 ", width: " << d_width <<
                 ", precision: " << static_cast<int>(d_precision) <<
                 ", nCols: " << d_nCols;
}
