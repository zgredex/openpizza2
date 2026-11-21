/* Object_FindRecordByKey28: finds a variable-size record by its leading
   key (0x4f0c60). */
struct Object {
    void GetBufferPair(int *list, int **base, int **count, int *first, int *second);
    int FindRecordByKey28(int *list, unsigned key);
};
int Object::FindRecordByKey28(int *list, unsigned key)
{
    int *base;
    int count;
    int i;
    GetBufferPair(list, &base, &list, 0, 0);
    count = *list;
    for (i = 0; i < count; i++) {
        unsigned short *entry = (unsigned short *)(*base + 2 + i * 0x28);
        if (*entry == key) {
            return *base + i * 0x28;
        }
    }
    return 0;
}
