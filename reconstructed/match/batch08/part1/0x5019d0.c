/* Player_Event_StreamConstruct: constructor that binds the vtable and loads
   the event when a stream is supplied (0x5019d0). */
struct CRT_Istream {
    void Read(void *dest, int size);
};

extern int DAT_0057c670;

struct Player_Event {
    void *vtable;
    int field4;
    short field8;
    void Load(struct CRT_Istream *stream);
    struct Player_Event *StreamConstruct(struct CRT_Istream *stream);
};

Player_Event *Player_Event::StreamConstruct(struct CRT_Istream *stream)
{
    vtable = (void *)0x55c660;
    if (stream != 0) {
        Load(stream);
        return this;
    }
    field8 = *(short *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    return this;
}
