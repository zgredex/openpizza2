// GameCalendar_Save @ 0x4dd4f0 (157 bytes)
// Serializes the calendar fields to the save stream in the shipped order.

class OStream {
public:
    void Write(void *data, int size);
};

class GameCalendar {
public:
    char pad00[4];
    char field04[4];
    char field08[1];
    char field09[1];
    char field0a[2];
    char field0c[4];
    char field10[4];
    char field14[4];
    char field18[1];
    char field19[1];
    char rest[6];

    void Save(OStream *stream);
};

extern char DAT_0057dfbc[];

void GameCalendar::Save(OStream *stream)
{
    stream->Write((char *)this + 7, 1);
    stream->Write((char *)this + 6, 1);
    stream->Write((char *)this + 8, 1);
    stream->Write((char *)this + 4, 2);
    stream->Write((char *)this + 10, 2);
    stream->Write((char *)this + 12, 4);
    stream->Write((char *)this + 0x19, 1);
    stream->Write((char *)this + 0x18, 1);
    stream->Write((char *)this + 0x14, 4);
    stream->Write((char *)this + 0x10, 4);
    stream->Write(DAT_0057dfbc, 4);
}
