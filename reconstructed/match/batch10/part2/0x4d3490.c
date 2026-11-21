/* CarList_Save: write the car list entry id, its field and the car record
   to a stream (0x4d3490). */
extern "C" int DAT_0057c5cc;

struct Game {
    void *RemoveIDMapEntry(int id);
};

struct CRT {
    void Ostream_Write(void *data, int size);
};

struct Car {
    void Save(struct CRT *stream);
};

struct CarList {
    void Save(struct CRT *stream);
};

void CarList::Save(struct CRT *stream)
{
    void *value;

    value = ((struct Game *)DAT_0057c5cc)->RemoveIDMapEntry(
        *(int *)((char *)this + 4));
    stream->Ostream_Write(&value, 4);
    stream->Ostream_Write((char *)this + 0xc, 4);
    ((struct Car *)this)->Save(stream);
}
