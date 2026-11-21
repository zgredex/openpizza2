/* Record_GetFlag3E48: reads the active record's byte flag at 0x3e (0x4d3530). */
struct Sub {
    int index;
    char pad[0x58 - 4];
    char *table;
};

struct Record {
    char pad[8];
    Sub *sub;
    int GetFlag3E48();
};

int Record::GetFlag3E48()
{
    Sub *sub = this->sub;

    if (sub != 0) {
        int index = sub->index;
        char *table = sub->table;

        if (index >= 0 && index < *(int *)(table + 0x48)) {
            return *(unsigned char *)(*(int *)(table + 0x4c) + index * 0x48 + 0x3e);
        }
    }
    return 0;
}
