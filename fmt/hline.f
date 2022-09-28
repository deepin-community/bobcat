inline FMT hline(unsigned nCols = ~0U)

{
    return { FMT::HLINE,  0, ~0U, nCols == 0 ? 1 : nCols };
}
