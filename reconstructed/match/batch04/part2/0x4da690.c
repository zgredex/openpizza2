/* Array_FindIndexStride60: index of an element pointer, 4 if absent (0x4da690). */
struct Array {
    int FindIndexStride60(int *target);
};

int Array::FindIndexStride60(int *target)
{
    int index;
    int *record;

    index = 0;
    record = (int *)((char *)this + 0xdc8);
    while (index < 4) {
        if (record == target)
            break;
        index++;
        record += 0x18;
    }
    return index;
}
