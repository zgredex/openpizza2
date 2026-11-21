/* Object_FindRecordAtOffset: finds a record at a translated tile offset
   (0x4f0bd0). */
struct Object {
    char pad[0x24];
    int offsetX;
    int offsetY;

    void GetBufferPair(int value, void **buffer, int *out, int *arg4, int *arg5);
    int FindRecordAtOffset(int *param, int x, int y);
};

int Object::FindRecordAtOffset(int *param, int x, int y)
{
    void *local[2];
    int *countPtr;
    int *records;
    int count;
    int i;

    GetBufferPair((int)param, local, (int *)&param, 0, 0);
    countPtr = (int *)param;
    i = 0;
    count = *countPtr;
    if (count > 0) {
        local[1] = *(void **)local[0];
        records = (int *)local[1];
        records = records + 4;
        do {
            if (records[-1] - offsetX == x && records[0] - offsetY == y) {
                return (int)((int *)local[1] + i * 10);
            }
            i++;
            records += 10;
        } while (i < count);
    }
    return 0;
}
