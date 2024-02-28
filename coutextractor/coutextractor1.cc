#include "coutextractor.ih"

CoutExtractor::CoutExtractor(size_t bufSize)
:
    IUO::ExtractorBase(bufSize),
    d_modeFun(noClose)              // Exec: no actions: don't close pipes
{}
