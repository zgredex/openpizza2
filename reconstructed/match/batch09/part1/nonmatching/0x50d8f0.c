/* Object_SyncScreenY: copies the screen-space Y coordinate of the object's
   record (0x50d8f0). */
struct Record {
    void GetTwoFloats48(int index, int *first, int *second);
};

void __fastcall Object_SyncScreenY(int object)
{
    int *record = *(int **)(object + 0xc8);
    int index;
    int local_4;
    int local_8;

    index = record == 0 ? -1 : *record;
    ((struct Record *)(record == 0 ? 0 : (void *)record[0x16]))
        ->GetTwoFloats48(index, &local_4, &local_8);
    *(int *)(object + 0x98) = local_8;
}
