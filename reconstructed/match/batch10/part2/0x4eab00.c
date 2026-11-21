/* World_LoadNameIndexTable: read name records and store their index in the
   world table (0x4eab00). */
struct CRT {
    void Istream_Read(void *buffer, int size);
};

struct Map {
    int FindNameIndex(void *name);
};

struct World {
    void LoadNameIndexTable(struct CRT *stream);
};

void World::LoadNameIndexTable(struct CRT *stream)
{
    unsigned char name[100];
    unsigned short *entry = (unsigned short *)((char *)this + 0x2e4f4);
    int count = 0x9c4;

    do {
        int index;

        stream->Istream_Read(name, 0x32);
        index = ((struct Map *)this)->FindNameIndex(name);
        if (index != -1)
            *entry = (unsigned short)index;
        entry++;
        count--;
    } while (count != 0);
}
