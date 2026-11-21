/* MapObject_ReadRenderRecord: reads a map object's optional render-sprite
   record (0x505340). */
extern int *DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Stream {
    void Read(void *data, int size);
};

struct MapActor {
    void ReadFromStream(Stream *stream, void *value);
};

struct MapObject {
    char pad0[0x30];
    int type;
    char pad1[0x1c];
    int id;
    char pad2[0x70];
    MapActor *actor;
    void *value;

    void InitRenderRecord(void *param, int type, int index);
    void ReadRenderRecord(void *param, Stream *stream);
};

void MapObject::ReadRenderRecord(void *param, Stream *stream)
{
    unsigned int index;
    int tag;

    if (type == 0x10) {
        int *record = (int *)((struct IDMap *)((char *)DAT_0057c670 + 0x20))
                          ->Lookup(id, 0);

        index = *(unsigned char *)((char *)record + 0x824);
    } else {
        index = -1;
    }
    InitRenderRecord(param, type, index);
    stream->Read(&tag, 4);
    if (tag == 1) {
        actor->ReadFromStream(stream, value);
        return;
    }
    value = 0;
}
