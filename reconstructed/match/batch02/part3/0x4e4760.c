struct Object { char pad[0xc]; int field; void SetField0C(int value); };

void Object::SetField0C(int value)
{
    field = value;
}
