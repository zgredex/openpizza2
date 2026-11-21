void __fastcall Object_SetChildShort(char *this_)
{
    char *child = *(char **)(this_ + 0xc8);
    if (child != 0)
        *(short *)(child + 8) = -1;
}
