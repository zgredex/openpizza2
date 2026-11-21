/* Array_GetPairByKey (0x5314a0): binary-searches the pair array and returns
   the two int fields at +0x38/+0x3c of the matched record. */
struct Pair {
    int *value;
    int unused;
};

struct Array {
    char pad[0xe8];
    Pair *pairs;

    int BinarySearch8(int key, int flag);
    int GetPairByKey(int key, int *first, int *second);
};

int Array::GetPairByKey(int key, int *first, int *second)
{
    int index = BinarySearch8(key, 0);

    if (index == -1)
        return 0;
    *first = *(int *)((char *)pairs[index].value + 0x38);
    *second = *(int *)((char *)pairs[index].value + 0x3c);
    return 1;
}
