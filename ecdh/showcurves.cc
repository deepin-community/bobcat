
#include "ecdh.ih"

// static
ostream &ECDH::showCurves(ostream &out)
{
    TableLines tablelines;
    tablelines << 0 << "  ";

    Table tab(tablelines, 3, Table::ROWWISE);

    tab << Align{ 2, left} <<
           "curve name" << ' ' << "comment" <<
           Align{ 0, 2, center };

    tablelines << TableLines::HLine(1, 0, 3);

    for (auto const &curve : supportedCurves())
        curveInfo(tab, curve.second);

    out << tab;

    return out;
}
