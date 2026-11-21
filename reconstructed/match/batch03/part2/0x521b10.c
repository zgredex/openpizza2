/* Object_GetActiveValue - 0x521b10, 23 bytes */
unsigned int __fastcall Object_GetActiveValue(void *this_)
{
    unsigned int value = *(unsigned int *)((char *)this_ + 0x6c);

    if (value != 0)
        return *(int *)((char *)this_ + 0x78) != 0 ? 0 : value;
    return *(unsigned int *)((char *)this_ + 0x68);
}
