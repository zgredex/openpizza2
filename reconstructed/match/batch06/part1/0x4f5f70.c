/* Array_SetSlot: writes the value of the first matching key slot (0x4f5f70). */
struct Array {
    int pad0;
    int keys[3];
    int values[1];
    void SetSlot(int key, int value);
};

void Array::SetSlot(int key, int value)
{
    int remaining = 3;
    int *slot = keys;

    do {
        if (*slot == key) {
            values[key] = value;
        }
        slot++;
        remaining--;
    } while (remaining != 0);
}
