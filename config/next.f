inline size_t CF_Line::next(size_t pos) const
{
    return d_line.find_first_of(" \t\r", pos);  // first ws sep from 'pos'
}
