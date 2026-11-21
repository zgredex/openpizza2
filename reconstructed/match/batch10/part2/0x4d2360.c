/* Game_GetObjectBottom: bottom edge of a map object's sprite cell
   (0x4d2360). */
extern "C" int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

extern "C" int __fastcall Game_GetObjectBottom(int object)
{
    int bottom = -1;
    char *record = (char *)((struct IDMap *)(DAT_0057c670 + 4))->Lookup(
        *(int *)(object + 0x28), 0);
    char *info = *(char **)(record + 0xfa8);

    if (info != 0) {
        int index = *(int *)(object + 0x24);
        int height = *(int *)(info + 0x10);
        int *cells = *(int **)(info + 0x4c);

        bottom = cells[index * 3 + 1] + (height >> 1) + height;
    }
    return bottom;
}
