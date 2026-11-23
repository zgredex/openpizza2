/* Storage::Storage (0x513c90). */
extern "C" void *memset(void *dst, int value, unsigned int size);
extern "C" char DAT_0055c700[];
struct IStream;

struct List {
    int data[7];
    List(int capacity);
    ~List();
    void Add(void *item);
};

struct Storage {
    char pad[0x24];
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    char field3c;
    char pad3d[3];
    int field40;
    List list;
    int array[0x3c];

    Storage(IStream *stream);
    void LoadRecord(IStream *stream);
};

Storage::Storage(IStream *stream) : list(0)
{
    *(void **)this = DAT_0055c700;
    if (stream != 0) {
        LoadRecord(stream);
        return;
    }
    field24 = -1;
    field28 = -1;
    field2c = 1;
    field38 = 0;
    field34 = 0;
    field3c = 1;
    field40 = 0;
    field30 = -1;
    memset(array, 0, sizeof(array));
}
