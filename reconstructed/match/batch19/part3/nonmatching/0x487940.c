/* SaveGame_SerializeRuntimeList (0x487940). */

extern char *DAT_0057c5cc;

struct OStream {
    void Write(void *data, int size);
};

struct RecordList {
    char pad0[0x48];
    int count;                  /* 0x48 */
    char *records;              /* 0x4c */
};

struct Record {
    void GetTwoFloats48(int index, int *out1, int *out2);
    int GetTypeIndex48(int index);
};

struct SaveGame {
    char pad0[0x36c];
    int values[6];              /* 0x36c */

    void SerializeRuntimeList(OStream *stream);
};

void SaveGame::SerializeRuntimeList(OStream *stream)
{
    RecordList *records = *(RecordList **)(DAT_0057c5cc + 0x2c3d4);
    int value;
    int offset = 0x2c41c;

    do {
        int index = *(int *)(DAT_0057c5cc + offset);
        int enabled = *(unsigned char *)(records->records + 0x3e +
                                         index * 0x48);
        int valid = 1;

        if (index < 0 || index >= records->count || enabled == 0)
            valid = 0;
        if (valid) {
            int local_c;
            int local_8;

            value = 1;
            stream->Write(&value, 4);
            ((Record *)records)->GetTwoFloats48(index, &local_c, &local_8);
            stream->Write(&local_c, 4);
            stream->Write(&local_8, 4);
            value = ((Record *)records)->GetTypeIndex48(index);
            stream->Write(&value, 4);
            value = *(int *)((char *)this + offset - 0x2c0b0);
        } else {
            value = 0;
        }
        stream->Write(&value, 4);
        offset += 4;
    } while (offset < 0x2c434);
}
