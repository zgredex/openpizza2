struct Object { char pad[0x8304]; int field; void SetWindowProc(int value); };

void Object::SetWindowProc(int value)
{
    field = value;
}
