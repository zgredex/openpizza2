/* Array_FindPair: finds the first active key/value pair (0x5140b0). */
struct Array {
    char pad[0x60];
    int values[20];
    int keys[20];
    int FindPair(int key);
};

int Array::FindPair(int key)
{
    int index = 0;
    int *pair = (int *)((char *)this + 0x64);

    do {
        if (pair[-1] != 0 && *pair == key) {
            return index;
        }
        index++;
        pair += 3;
    } while (index < 0x14);
    return -1;
}
