struct Object { char pad[0x104]; char field; void SetFlag104(char value); };

void Object::SetFlag104(char value)
{
    field = value;
}
