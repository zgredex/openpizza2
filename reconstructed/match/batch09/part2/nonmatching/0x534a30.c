/* Record_SetSlot6_98: writes a 6-byte slot of a 0x98-byte record (0x534a30). */
struct Slot6 {
    int value;
    short extra;
};

struct Record {
    void SetSlot6_98(int first, int second, struct Slot6 *slot);
};

void Record::SetSlot6_98(int first, int second, struct Slot6 *value)
{
    if (first >= 0 && first < *(int *)((char *)this + 100)
        && second >= 0 && second < 0x10) {
        *(struct Slot6 *)(*(int *)((char *)this + 0x50) + first * 0x98
                          + second * 6) = *value;
    }
}
