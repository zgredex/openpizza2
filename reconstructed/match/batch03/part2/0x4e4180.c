/* Array_FindEmptySlot8 - 0x4e4180, 21 bytes */
struct Slot
{
    short id;
    char rest[10];
};

struct Array8
{
    char pad[0x78];
    Slot slots[8];

    void FindEmptySlot8();
};

void Array8::FindEmptySlot8()
{
    for (int index = 0; index < 8; index++)
        if (slots[index].id == -1)
            return;
}
