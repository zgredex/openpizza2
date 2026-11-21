/* Array_GetBoundsByKey (0x5314f0): looks up a pair record by key and fills
   the four bounds derived from its source rectangle. */
struct Array {
    char pad[0xe8];
    int **pairs;

    int BinarySearch8(int key, int flag);
    int GetBoundsByKey(int key, int *bounds);
};

int Array::GetBoundsByKey(int key, int *bounds)
{
    int index = BinarySearch8(key, 0);

    if (index == -1)
        return 0;
    bounds[0] = pairs[index * 2][0x28 / 4];
    bounds[1] = pairs[index * 2][0x2c / 4];
    bounds[2] = (pairs[index * 2][0x30 / 4] - pairs[index * 2][0x28 / 4])
                + bounds[0];
    bounds[3] = (pairs[index * 2][0x34 / 4] - pairs[index * 2][0x2c / 4])
                + bounds[1];
    return 1;
}
