unsigned short CRT_ReadArg16(char **cursor)
{
    *cursor += 4;
    return *(unsigned short *)(*cursor - 4);
}
