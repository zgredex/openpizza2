struct Game {
    char pad0[0x94];
    unsigned char *city;
    char pad1[0x23c - 0x98];
    int lock1;
    int lock2;
    char pad2[0x254 - 0x244];
    volatile int flag254;
    char pad3[0x340 - 0x258];
    int frameCounter;
    char pad4[0x1508 - 0x344];
    int paused;
    void UpdateWorldObjects(int phase);
    void UpdateIdleCars();
    void RunSimulationFrame();
};

struct Sound {
    void UpdateCityAmbience(int volume, int pan);
};

extern Sound *DAT_0057ba0c;
extern int DAT_0057c68c;

void __fastcall CS_Enter(int section);
void __fastcall CS_Leave(int section);

void Game::RunSimulationFrame()
{
    if (*(int *)((char *)this + 0x1508) == 0) {
        CS_Enter(*(int *)((char *)this + 0x23c));
        flag254 = 1;
        CS_Leave(*(int *)((char *)this + 0x23c));
        CS_Enter(*(int *)((char *)this + 0x240));
        UpdateWorldObjects(DAT_0057c68c);
        *(int *)((char *)this + 0x340) = *(int *)((char *)this + 0x340) + 1;
        if (DAT_0057c68c == 0)
            UpdateIdleCars();
        unsigned char *city = *(unsigned char **)((char *)this + 0x94);
        DAT_0057ba0c->UpdateCityAmbience(city[7], city[6] * 5);
        CS_Leave(*(int *)((char *)this + 0x240));
        flag254 = 0;
        DAT_0057c68c = DAT_0057c68c + 1;
        if (4 < DAT_0057c68c)
            DAT_0057c68c = 0;
    }
}
