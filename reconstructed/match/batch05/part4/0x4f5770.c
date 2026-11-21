/* Record_SetField2D0C: stores a byte into a child record selected by index (0x4f5770). */
struct Child {
    char pad[0x2d];
    char field2d;
};

struct Entry {
    char pad[8];
    Child *child;
};

struct Record {
    char pad[0x4c];
    Entry *entries;
    void SetField2D0C(int index, char value);
};

void Record::SetField2D0C(int index, char value)
{
    Entry *entry = &entries[index];

    if (entry != 0 && entry->child != 0)
        entry->child->field2d = value;
}
