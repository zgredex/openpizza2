int __fastcall Object_GetChildField2C(char *this_)
{
    char *child = *(char **)(this_ + 0xc8);
    if (child != 0)
        return *(int *)(child + 0x2c);
    return 0;
}
