/* Object_SetIndex171C: stores an index and clears the two trailing fields
   (0x47c7b0). */
struct Object {
    char pad[0x171c];
    int index;
    int field1720;
    int field1724;
    void SetIndex171C(int value);
};

void Object::SetIndex171C(int value)
{
    index = value;
    field1724 = 0;
    field1720 = 0;
}
