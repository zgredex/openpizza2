/* Record_GetTypeIndex48: validates an index and looks up its type byte
   (0x534a80). */
struct RecordTable {
    char pad[0x48];
    int count;
    int *indices;
    unsigned char *types;
    int GetTypeIndex48(int index);
};

int RecordTable::GetTypeIndex48(int index)
{
    int id;
    char type;

    if (index < 0 || index >= count)
        return -1;
    id = indices[index * 0x12];
    type = types[0x80 + id * 0x98];
    if (type == 0)
        return -1;
    return id;
}
