/* Object_IsKnownId: classifies a map object id range (0x4f2a20). */
int __stdcall Object_IsKnownId(int id)
{
    if (id == -1)
        return 1;
    if (id >= 0x356 && id <= 0x602)
        return 1;
    if (id < 0x19 || id > 0x20)
        return 0;
    return 1;
}
