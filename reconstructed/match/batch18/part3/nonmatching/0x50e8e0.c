/* Player_Construct: constructs a player object (0x50e8e0). */
extern "C" void __cdecl List_Construct(void *list, int zero);

struct Player {
    char pad[0x84];
    int field84;
    int field88;
    char rest[0xa8];
    int fielda8;
    int fieldac;
    Player *Construct(int *stream);
    void Load(int *stream);
};

Player *Player::Construct(int *stream)
{
    List_Construct((char *)this + 0x8c, 0);
    *(void **)this = (void *)0x55c684;
    if (stream != 0) {
        Load(stream);
        return this;
    }
    *(int *)((char *)this + 0x84) = 1;
    *(int *)((char *)this + 0x88) = 1;
    *(int *)((char *)this + 8) = -1;
    *(int *)((char *)this + 0x3c) = 0;
    *(int *)((char *)this + 0x40) = 0;
    *(int *)((char *)this + 0x44) = 0;
    *(int *)((char *)this + 0x48) = 0;
    *(int *)((char *)this + 0x4c) = 0;
    *(int *)((char *)this + 0x50) = 0;
    *(int *)((char *)this + 0x54) = 0;
    *(int *)((char *)this + 0x58) = 0;
    *(int *)((char *)this + 0x5c) = 0;
    *(int *)((char *)this + 0x60) = 0;
    *(int *)((char *)this + 0x64) = 0;
    *(int *)((char *)this + 0x68) = 0;
    *(int *)((char *)this + 0x2c) = 0;
    *(int *)((char *)this + 0x30) = 0;
    {
        int i;
        int *p = (int *)((char *)this + 0x6c);

        for (i = 0; i < 6; i++) {
            *p = 0;
            p = p + 1;
        }
    }
    *(int *)((char *)this + 0x34) = 0;
    *(int *)((char *)this + 0x38) = 0;
    *(int *)((char *)this + 0xa8) = 0;
    *(int *)((char *)this + 0xac) = 0;
    return this;
}
