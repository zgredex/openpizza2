/* Object_IsIdIn840Range: true for object ids 0x840..0x84b (0x4d2e60). */
int __fastcall Object_IsIdIn840Range(int *object)
{
    int id = object[8];

    if (id < 0x840 || id > 0x84b)
        return 0;
    return 1;
}
