unsigned long CRT_GetVaArg(char **cursor)
{
    *cursor += 4;
    return *(unsigned long *)(*cursor - 4);
}
