#include "datetime.ih"

// static
pair<string, string> DateTime::Zone::dstFromVector(StringVector const &vs)
{
    if (vs.size() <= 3)             // no, std or time-shift DST:
        return {};                  // return empty DST strings

    auto iter = find(vs.begin(), vs.end(), "until");

    if (iter == vs.end())           // info beyond dst, but 'until' not
        throw 1;                    // specified 

    return {
                dstConcatenate(vs.begin() + 3, iter),
                dstConcatenate(iter + 1, vs.end())
           };
}
