/* Object_GetBufferCount: queries a buffer pair and returns its count (0x4f1250). */
struct Object {
    void GetBufferPair(int first, int *second, int *third, int fourth, int fifth);
    int GetBufferCount(int *count);
};

int Object::GetBufferCount(int *count)
{
    int local;

    GetBufferPair((int)count, &local, (int *)&count, 0, 0);
    return *count;
}
