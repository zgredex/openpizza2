/* Array_SearchSet: marks hits of a value across three entries
   (0x4f5fa0). */
struct Array {
    char pad[4];
    int entry[3];
    void SearchSet(int value);
};

void Array::SearchSet(int value)
{
    int *entry = this->entry;
    int count = 3;
    do {
        if (*entry == value)
            (*(int *)((char *)this + 0x10 + value * 4))++;
        entry++;
        count--;
    } while (count != 0);
}
