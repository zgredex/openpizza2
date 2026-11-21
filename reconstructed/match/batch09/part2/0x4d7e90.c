/* Array_FindIndexByPtr: index of the record matching a pointer (0x4d7e90). */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Array {
    int FindIndexByPtr(int record);
};

int Array::FindIndexByPtr(int record)
{
    int count = *(int *)((char *)this + 0xfc0);
    int index;

    for (index = 0; index < count; index++) {
        if (record == ((struct IDMap *)((char *)this + 0xfac))->Lookup(index, 0))
            return index;
    }
    return -1;
}
