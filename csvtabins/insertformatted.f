template <typename Type>
void CSVTabIns::insertFormatted(FMT const &fmt, Type const &value)
{
    if (d_idx == d_format.size())           // beyond the last column:
    {
        unsigned width = d_out->width();    // get the current width
                                            // insert 'value' as-is
        *d_out << std::setw(0) << d_sep << std::setw(width) << value;
        return;
    }

                    // before the last column

    unsigned fieldWidth = width(fmt);       // determine the field width

                                            // when centering: plain insertion
    if (fmt.align() == FMT::CENTER)         // because centered fills the full
        *d_out << centered(fmt, fieldWidth, value); // field width

    else
    {
        *d_out << (fmt.align() == FMT::RIGHT ? std::right : std::left);

        if (fmt.precision() < fieldWidth)
            d_out->precision(fmt.precision());

        *d_out <<  std::setw(fieldWidth) << value;
    }

    d_idx += fmt.nCols();

    if (d_idx != d_format.size())
        *d_out << d_sep;
}


