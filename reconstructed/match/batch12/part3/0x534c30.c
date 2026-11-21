/* UI_SetListEntryPosition (0x534c30). */

struct WeaponEntry {
    char pad[0x90];
    unsigned char field90;
    char pad2[152 - 0x91];
};

struct ListEntry {
    int recordIndex;
    char pad0[0x28 - 4];
    double value28;
    char pad1[0x3a - 0x30];
    short value3a;
    char pad2[0x48 - 0x3c];
};

struct UI {
    void SetListEntryPosition(int index, double value);
};

void UI::SetListEntryPosition(int index, double value)
{
    if (index >= 0 || index < *(int *)((char *)this + 0x48)) {
        struct ListEntry *entry;
        int recordIndex;
        unsigned char byte;
        double product;

        *(double *)((char *)*(void **)((char *)this + 0x4c)
                    + index * 0x48 + 0x28) = value;
        entry = (struct ListEntry *)((char *)*(void **)((char *)this + 0x4c)
                                     + index * 0x48);
        recordIndex = *(int *)((char *)*(void **)((char *)this + 0x4c)
                               + index * 0x48);
        byte = ((struct WeaponEntry *)*(void **)((char *)this + 0x50))
                   [recordIndex].field90;
        product = (double)byte * entry->value28;
        entry->value3a = (short)(int)(1000.0
            / (product * *(double *)((char *)this + 0x90)));
    }
}
