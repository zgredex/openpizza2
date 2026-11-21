/* Player_Event_Load: reads the event fields from the save stream (0x501a70). */
struct CRT_Istream {
    void Read(void *dest, int size);
};

struct Player_Event {
    int pad0;
    int field4;
    short field8;
    void Load(CRT_Istream *stream);
};

void Player_Event::Load(CRT_Istream *stream)
{
    stream->Read((char *)this + 4, 4);
    stream->Read((char *)this + 8, 2);
}
