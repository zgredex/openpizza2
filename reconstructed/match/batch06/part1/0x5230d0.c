/* Array_IndexOfInt: linear search of an integer array (0x5230d0). */
struct Array {
    int pad0;
    int *items;
    int count;
    int IndexOfInt(int value);
};

int Array::IndexOfInt(int value)
{
    int index = 0;

    if (count > 0) {
        int *item = items;
        while (index < count) {
            if (*item == value) {
                return index;
            }
            index++;
            item++;
        }
    }
    return -1;
}
