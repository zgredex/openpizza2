struct Object { char pad[0xfc]; int field; void SetFieldFC(int value); };

void Object::SetFieldFC(int value)
{
    field = value;
}
