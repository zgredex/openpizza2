/* Person_WatchTVProgram: marks a person as watching the current TV program
   (0x50e4e0). */
struct Game {
    void GetTimeByMode(int mode);
};

void __fastcall Person_SetRandomResidentialTarget(void *person);

struct Person {
    char pad[0x4c];
    int field4c;
    int field50;
    int field54;
    char pad2[0x1c];
    int field74;
    char pad3[0x90];
    int state108;
    void WatchTVProgram();
};

void Person::WatchTVProgram()
{
    state108 = 10;
    if (field74 == 0) {
        ((Game *)this)->GetTimeByMode(0);
        field4c = 0;
        field54 = 0;
        Person_SetRandomResidentialTarget(this);
    }
}
