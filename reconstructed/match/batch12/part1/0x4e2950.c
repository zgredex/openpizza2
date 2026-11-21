/* Game_RefreshBuildingCondition: ages buildings and restores grade for
   construction orders (0x4e2950). */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Record {
    int object;
    int kind;
};

extern "C" void __fastcall Game_RefreshBuildingCondition(void *game)
{
    int i = 0;

    *(volatile int *)((char *)game + 0x68) =
        *(int *)((char *)game + 0x68) + 1;
    {
        for (; i < *(int *)((char *)game + 0x1cc); i++) {
            struct Record *record = (struct Record *)
                ((struct IDMap *)((char *)game + 0x1b8))->Lookup(i, 0);

            if (record->kind == 0x1e) {
                void *object = ((struct IDMap *)((char *)DAT_0057c670 + 0x3c))
                    ->Lookup(record->object, 0);
                *(int *)((char *)object + 0xa8) = 100;
            }
        }
    }
}
