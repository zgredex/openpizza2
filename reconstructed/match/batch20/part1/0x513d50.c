/* Storage::LoadRecord (0x513d50). */
extern "C" void *operator_new(unsigned int size);
extern "C" void *g_Game;

class IStream {
public:
    void Read(void *buffer, int size);
};

struct IDMapHelper {
    void *Lookup(int key, int *index);
};

struct List {
    void Add(void *item);
};

struct Storage {
    void LoadRecord(IStream *stream);
};

void Storage::LoadRecord(IStream *stream)
{
    int cityId;
    int count;
    int key;
    int i;
    void *record;
    void *map;
    void *city;

    stream->Read((char *)this + 4, 0x1e);
    stream->Read((char *)this + 0x24, 4);
    stream->Read((char *)this + 0x28, 4);
    stream->Read((char *)this + 0x2c, 4);
    stream->Read((char *)this + 0x38, 4);
    stream->Read((char *)this + 0x3c, 1);
    stream->Read((char *)this + 0x40, 4);
    stream->Read((char *)this + 0x30, 4);
    stream->Read(&cityId, 4);

    map = g_Game;
    key = *(int *)((char *)this + 0x28);
    city = ((IDMapHelper *)((char *)map + 4))->Lookup(key, 0);
    *(void **)((char *)this + 0x34) =
        ((IDMapHelper *)((char *)city + 0xfac))->Lookup(cityId, 0);

    stream->Read(&count, 4);
    for (i = 0; i < count; i++) {
        record = operator_new(0x20);
        stream->Read(record, 0x20);
        ((List *)((char *)this + 0x44))->Add(record);
    }
    stream->Read((char *)this + 0x60, 0xf0);
}
