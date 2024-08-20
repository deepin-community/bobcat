inline std::ostream &operator<<(std::ostream &out, FBB::mlm const &idt)
{
    return idt.modify(out);
}
