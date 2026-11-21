short __fastcall Counter_IncrementShortBA(char *this_)
{
    ++*(short *)(this_ + 0xba);
    return *(short *)(this_ + 0xba);
}
