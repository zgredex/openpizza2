struct Object { char pad[0x28]; short field; void SetShort28(short value); };

void Object::SetShort28(short value)
{
    field = value;
}
