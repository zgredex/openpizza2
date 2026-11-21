/* Branch_RefreshConstructionButtons: refreshes the construction buttons
   according to the branch state (0x47fb70). */
extern "C" int *DAT_0057c670;

struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct MapHelper {
    void ClearObjectFlags(void *object, int flags);
};

struct GameHelper {
    void ClearObjectFlag20();
    void ToggleObjectFlag2();
    void UpdateObjectList2();
    void CheckObjectUpgrade();
};

extern "C" void __fastcall Branch_RefreshConstructionButtons(char *this_)
{
    if (*(int *)(this_ + 0x2c) == 7) {
        char *game = (char *)DAT_0057c670;
        char *record =
            (char *)((IDMapHelper *)(game + 4))
                ->Lookup(*(int *)(game + 0x2f4), 0);

        ((MapHelper *)*(void **)(this_ + 0x16f0))
            ->ClearObjectFlags(*(void **)(record + 0xfa8), -1);
        return;
    }
    ((GameHelper *)this_)->ClearObjectFlag20();
    ((GameHelper *)this_)->ToggleObjectFlag2();
    ((GameHelper *)this_)->UpdateObjectList2();
    ((GameHelper *)this_)->CheckObjectUpgrade();
}
