struct Object { char pad[0x168]; int field; void SetField168(int value); };

void Object::SetField168(int value)
{
    field = value;
}
