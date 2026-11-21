/* Map_ApplyRandomTileVariant: selects the tile variant for a map object
   (0x4d22c0). */
extern int DAT_0057c670;
int __cdecl Random_RangeFast(int low, int high);

struct IDMap {
    char *Lookup(int key, int *out);
};

struct RecordArray {
    void GetRecord28(int index, int value);
};

struct TileObject {
    char pad[0x28];
    int id;
};

extern "C" void __fastcall Map_ApplyRandomTileVariant(void *object)
{
    RecordArray *array;
    char *record;
    int index;

    record = ((IDMap *)(DAT_0057c670 + 4))->Lookup(
        *(int *)((char *)object + 0x28), 0);
    array = *(RecordArray **)(record + 0xfa8);
    if (*(int *)((char *)object + 0x6c) == 0) {
        array->GetRecord28(1, *(int *)((char *)object + 0x54));
        return;
    }
    index = Random_RangeFast(0, *(int *)((char *)object + 0x6c) - 1);
    index = (int)((IDMap *)((char *)object + 0x58))->Lookup(index, 0);
    array->GetRecord28(1, index);
}
