/* Game_HandleMapClickCloseSubmenu (0x4c3000). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct UI {
    int IsClickOccluded(void *view, void *input);
};
struct MapObject {
    void RemoveFromMap(void *input);
};
struct Game {
    char pad00[0x344];
    int field344;
};
extern "C" char *DAT_0057c670;

extern "C" void __cdecl Game_HandleMapClickCloseSubmenu(int *input)
{
    char *view = *(char **)(DAT_0057c670 + 0x9c);
    int field = *(int *)(view + 0x14e0);
    void *record = ((struct IDMap *)(DAT_0057c670 + 0x74))
                       ->Lookup(input[1], 0);

    if ((*(int *)((char *)record + 8) == 1 ||
         *(int *)((char *)record + 8) == 2) &&
        ((struct UI *)DAT_0057c670)->IsClickOccluded(view, input) != 0) {
        return;
    }
    ((struct Game *)DAT_0057c670)->field344 = -1;
    *(int *)(field + 0x60) = 0;
    ((struct MapObject *)view)->RemoveFromMap(input);
    *(int *)(field + 0xf4) = 1;
}
