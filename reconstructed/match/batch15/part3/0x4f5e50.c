struct CRT_Istream {
    int Read(void *dst, int size);
};

struct Player {
    void MissionState_Load(void *stream);
};

void Player::MissionState_Load(void *stream)
{
    CRT_Istream *s = (CRT_Istream *)stream;
    s->Read((char *)this + 4, 0xc);
    s->Read((char *)this + 0x10, 0xb0);
    s->Read((char *)this + 0xc0, 4);
    s->Read((char *)this + 0xc4, 3);
    s->Read((char *)this + 0xc8, 4);
    s->Read((char *)this + 0xcc, 1);
    s->Read((char *)this + 0xd0, 4);
    s->Read((char *)this + 0xd4, 4);
}
