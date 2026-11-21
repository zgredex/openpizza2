/* Object_SetChildField2C - 0x50e4c0, 20 bytes */
struct Child
{
    char pad[0x2c];
    int field;
};

struct Object
{
    char pad[0xc8];
    Child *child;

    void SetChildField2C(int value);
};

void Object::SetChildField2C(int value)
{
    if (child != 0)
        child->field = value;
}
