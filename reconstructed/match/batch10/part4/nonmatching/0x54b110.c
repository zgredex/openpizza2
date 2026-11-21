/* MessageList_FindKeyByValue (0x54b110): finds the message whose value field
   matches and returns its key. */
struct Entry {
    char pad[8];
    int value;
};

struct IDMap {
    Entry *Lookup(int index, int *value);
};

struct MessageList {
    char pad[4];
    IDMap map;
    char pad2[0x18 - 0x8];
    int count;
    Entry *FindKeyByValue(int value, int *key);
};

Entry *MessageList::FindKeyByValue(int value, int *key)
{
    int count = this->count;
    int i = 0;
    int wanted;

    if (count <= 0)
        return 0;
    wanted = value;
    do {
        Entry *entry = map.Lookup(i, &value);
        if (entry != 0 && entry->value == wanted) { *key = value; return entry; }
        i++;
    } while (i < count);
    return 0;
}
