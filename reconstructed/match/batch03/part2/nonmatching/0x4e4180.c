/* Superseded first attempt for 0x4e4180 (Array_FindEmptySlot8).
 * The do/while form was unrolled by VC6 into a 32-byte two-way loop.
 * First difference: offset 0, original 0x33 (xor eax,eax) vs 0x8d (lea).
 */
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
    int index = 0;
    Slot *slot = &slots[0];

    do
    {
        if (slot->id == -1)
            return;
        index++;
        slot++;
    } while (index < 8);
}
