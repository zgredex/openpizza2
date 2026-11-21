/* Record_SetSlot6_98: writes a 6-byte slot of a 0x98-byte record (0x534a30). */
struct Record {
    void SetSlot6_98(int first, int second, int *value);
};

void Record::SetSlot6_98(int first, int second, int *value)
{
    if (first >= 0 && first < *(int *)((char *)this + 100)
        && second >= 0 && second < 0x10) {
        int *slot = (int *)(*(int *)((char *)this + 0x50) + first * 0x98
                            + second * 6);

        *slot = *value;
        *(short *)((char *)slot + 4) = *(short *)((char *)value + 4);
    }
}
