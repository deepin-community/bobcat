template <typename Type>
CSVTabIns &CSVTabIns::insert(Type const &value)
{
                                            // beyond the table: insert as-is
    if (d_idx == d_format.size())           // but width a separator
        *d_out << d_sep << value;

    else                                    // value is needed for centering
        insertFormatted(d_useExtraFMT ? d_extraFMT : d_format[d_idx], 
                        value);             // also: updates d_idx

    d_useExtraFMT = false;
    return *this;    
}
