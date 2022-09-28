#include "main.ih"

int main()
try
{
//    CSVTable tab;
    CSVTable tab("table");

//    tab.fmt() << "case" << right("length", 2) << right("weight", 1) <<
//                           right("length", 2) << right("weight", 1);


    tab.fmt() << "case";
    tab.fmt(1) << right("length", 2) << right("weight", 1) <<
                           right("length", 2) << right("weight", 1);

    tab.sep("  ");

    tab << hline();

//    tab << "" << join(4, FMT::CENTER) << "Gender";
    tab.row(1) << join(4, FMT::CENTER) << "Gender";

    tab.row(1) << hline();

    tab.more(1) << join(2, FMT::CENTER) << "Female"; 
    tab.row()   << join(2, FMT::CENTER) << "Male";


    tab.row(1) << hline(2) << hline(2);

    tab << "Case" << "Length" << "Weight" << "Length" << "Weight";
    tab << hline();

    tab.sep(", ");

    tab << 1 << 1.744 << 55.345 << 1.7244 << 64.801;
    tab << 2 << 1.58  << 57.545 << 1.8174 << 81.451;
    tab << 3 << 1.674 << 62.125 << 1.8244 << 80.201;

    tab << hline();

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}
