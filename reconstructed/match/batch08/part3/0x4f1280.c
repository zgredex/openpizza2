/* Array_GetRandomRecord28B: returns a random 0x28-byte record from the array
   (0x4f1280). */
struct Object {
    void GetBufferPair(int value, int *base, int *ioValue, int *zero1,
                       int *zero2);
};

extern "C" int __cdecl Random_RangeFast(int min, int max);

struct Array {
    int GetRandomRecord28B(int *count);
};

int Array::GetRandomRecord28B(int *count)
{
    int *base;

    ((Object *)this)->GetBufferPair((int)count, (int *)&base, (int *)&count, 0, 0);
    int index = Random_RangeFast(0, *count - 1);
    return *base + index * 0x28;
}
