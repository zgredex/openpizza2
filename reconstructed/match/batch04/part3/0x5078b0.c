/* Object_SetChildShort8: updates the selected child's short field (0x5078b0). */
struct ObjectChild {
    char pad[8];
    short value;
};

struct Object {
    char pad[0xc8];
    ObjectChild *child;
    void SetChildShort8(int value);
};

void Object::SetChildShort8(int value)
{
    ObjectChild *selected = child;

    if (selected != 0 && selected->value != value) {
        selected->value = (short)value;
    }
}
