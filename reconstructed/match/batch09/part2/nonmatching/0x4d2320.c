/* Game_GetObjectCenterY: centre Y of the map object's cell (0x4d2320). */
struct IDMap {
    int *Lookup(int key, int *out);
};

extern int DAT_0057c670;

int __fastcall Game_GetObjectCenterY(int object)
{
    int result = -1;
    int *record = ((struct IDMap *)(DAT_0057c670 + 4))->Lookup(*(int *)(object + 0x28), 0);
    int map = *(int *)((char *)record + 0xfa8);

    if (map != 0)
        result = *(int *)(*(int *)(map + 0x4c) + *(int *)(object + 0x24) * 0xc)
                 + (*(int *)(map + 0xc) >> 1);
    return result;
}
