/* Object_GetClampedLevel: clamps the level field to 1..3 (0x50e810). */
int __fastcall Object_GetClampedLevel(int object)
{
    int level = *(int *)(object + 0x10c);

    if (level < 1 || level > 3)
        *(int *)(object + 0x10c) = 1;
    return *(int *)(object + 0x10c);
}
