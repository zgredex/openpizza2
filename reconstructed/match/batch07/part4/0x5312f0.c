/* Array_GetPair8: returns the two dwords of an index pair (0x5312f0). */
struct Array {
    char pad[0xec];
    char *pairs;
    int count;
    int GetPair8(int index, int *out);
};

int Array::GetPair8(int index, int *out)
{
    if (index < 0 || index >= count)
        return 0;
    *out = *(int *)(pairs + index * 8 + 4);
    return *(int *)(pairs + index * 8);
}
