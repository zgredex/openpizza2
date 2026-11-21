int __fastcall Storage_GetCapacity(char *this_)
{
    return *(int *)(this_ + 0x2c) * 0xf + 0x24;
}
