inline std::ostream &operator<<(std::ostream &out, FBB::lm const &idt)
{
    return idt.modify(out);
}
