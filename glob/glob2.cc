#include "glob.ih"

Glob::Glob(Type type, string const &pattern, int flags, Dots dots)
:
    Glob(fillSet(type), pattern, flags, dots)
{}
