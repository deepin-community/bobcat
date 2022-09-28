template <typename Type>
std::string CSVTabIns::centered(FMT const &fmt,
                                unsigned fieldWidth, Type const &value)
{
    using namespace std;

    ostringstream stream;                  // format value in 'stream'

    stream.copyfmt(*d_out);                     // xfer d_out's format to 
    stream.fill(d_out->fill());                 // stream

    if (fmt.d_precision < fieldWidth)           // maybe set the precision
        stream.precision(fmt.d_precision);

    stream << setw(fieldWidth) << value;        // convert value to string

    string ret = String::trim(stream.str()); // remove surrounding spaces

                                                // extra spaces needed
    if (unsigned length = ret.length();  length < fieldWidth)
    {                                           
                                                // prefix this #spaces 
        ret.insert(ret.begin(), (fieldWidth - length) / 2, ' '); 
        ret.resize(fieldWidth, ' ');
    }


    return ret;
}




