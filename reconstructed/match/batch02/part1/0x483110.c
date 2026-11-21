/* Object_SetField280: stores a value at object offset 0x280 (0x483110). */
struct Object {
    char pad[0x280];
    int field280;
    void SetField280(int value);
};

void Object::SetField280(int value)
{
    field280 = value;
}
