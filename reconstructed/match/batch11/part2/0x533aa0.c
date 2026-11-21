/* Record_SelectVariant: selects and applies a render-record variant
   (0x533aa0). */
struct RecordEntry {
    int field0;
    char pad[0x3a];
    char field3e;
};

struct RecordHelper {
    void AssignVariant(int index, int variant);
    int ApplyVariantState(int index, int a, int b);
};

struct Record {
    char pad[0x4c];
    RecordEntry *entries;

    int SelectVariant(int index, int variant);
};

int Record::SelectVariant(int index, int variant)
{
    RecordEntry *entry = (RecordEntry *)((char *)entries + index * 0x48);

    if (entry->field3e == 1 && variant == entry->field0)
        return 1;
    if (variant != -1)
        ((RecordHelper *)this)->AssignVariant(index, variant);
    return ((RecordHelper *)this)->ApplyVariantState(index, 0, 0) != 0; 
}
