/* Object_CountMatchingSlots: counts eight state slots matching a value (0x50e200). */
struct Object {
    char pad[0xd4];
    int slots[8];
    int CountMatchingSlots(int value);
};

int Object::CountMatchingSlots(int value)
{
    int count = 0;
    int *slot = slots;
    int remaining = 8;

    do {
        if (*slot == value)
            count++;
        slot++;
    } while (--remaining != 0);
    return count;
}
