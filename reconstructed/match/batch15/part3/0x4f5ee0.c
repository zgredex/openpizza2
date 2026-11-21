struct CRT_Ostream {
    void Write(void *src, int size);
};

struct Player {
    void MissionState_Save(void *stream);
};

void Player::MissionState_Save(void *stream)
{
    CRT_Ostream *s = (CRT_Ostream *)stream;
    s->Write((char *)this + 4, 0xc);
    s->Write((char *)this + 0x10, 0xb0);
    s->Write((char *)this + 0xc0, 4);
    s->Write((char *)this + 0xc4, 3);
    s->Write((char *)this + 0xc8, 4);
    s->Write((char *)this + 0xcc, 1);
    s->Write((char *)this + 0xd0, 4);
    s->Write((char *)this + 0xd4, 4);
}
