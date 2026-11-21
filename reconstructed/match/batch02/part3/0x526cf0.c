struct Object { char pad[0x228]; int field; void SetField228(int value); };

void Object::SetField228(int value)
{
    field = value;
}
