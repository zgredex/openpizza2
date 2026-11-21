/* Player_Event_Save: writes the event fields to the save stream (0x501a40). */
struct CRT_Ostream {
    void Write(void *source, int size);
};

struct Player_Event {
    int pad0;
    int field4;
    short field8;
    void Save(CRT_Ostream *stream);
};

void Player_Event::Save(CRT_Ostream *stream)
{
    stream->Write((char *)this + 4, 4);
    stream->Write((char *)this + 8, 2);
}
