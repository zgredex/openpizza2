/* PC2 byte-match candidate: MessageList_SetField34 (0x54b2c0, 29 bytes).
   Build: /O2 /TP.  Writes field 0x34 of the record found by key. */
struct IDMap {
    int Lookup(int key, int *out);
};

struct MessageList {
    int pad_000;
    IDMap map;
    void SetField34(int key, int value);
};

void MessageList::SetField34(int key, int value)
{
    int record = map.Lookup(key, 0);
    if (record != 0)
        *(int *)(record + 0x34) = value;
}
