/* Object_GetPair68 - 0x4e4160, 21 bytes */
struct Object
{
    char pad[0x68];
    int first;
    int second;

    void GetPair68(int *outFirst, int *outSecond);
};

void Object::GetPair68(int *outFirst, int *outSecond)
{
    *outFirst = first;
    *outSecond = second;
}
