
#include "ecdh.ih"

// static
ECDH::CurveMap const &ECDH::supportedCurves()
try
{
    if (s_curves.size() > 0)
        return s_curves;

    ERR_clear_error();

    size_t count = EC_get_builtin_curves(0, 0);
    if (count == 0) 
        throw "EC_get_builtin_curves";

    auto buffer = make_unique<EC_builtin_curve[]>(count);
    if (EC_get_builtin_curves(buffer.get(), count) != count) 
        throw "EC_get_builtin_curves";

    for (size_t idx = 0; idx != count; ++idx) 
    {
        if (char const *curveName = OBJ_nid2sn(buffer[idx].nid); curveName)
        {
            if (string name{ curveName }; name.length() > 0)
            {
                char const *comment = buffer[idx].comment;
                s_curves[name] = CurveInfo{ buffer[idx].nid, name, 
                                            comment ? comment : "" };
            }
        }
    }
    return s_curves;
}
catch (char const *what)
{
    s_curves = CurveMap{};
    throw Exception{} << "supportedCurves: " << what << " failed " <<
                lastErrorString();
}
