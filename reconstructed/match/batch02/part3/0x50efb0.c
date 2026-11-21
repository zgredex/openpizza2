struct Object { char pad[8]; int field; void SetField8(int value); };

void Object::SetField8(int value)
{
    field = value;
}
