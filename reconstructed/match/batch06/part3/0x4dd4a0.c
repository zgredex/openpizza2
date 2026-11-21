/* GameClock_Reset: resets the clock fields and reloads the start year from the
   global settings block (0x4dd4a0).  Build: /O2 /TP. */
struct GameClock {
    char pad[4];
    unsigned short year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned short minute;
    int seconds;
    int field10;
    int pad2;
    unsigned char field18;
    unsigned char field19;
    void Reset();
};

void GameClock::Reset()
{
    field10 = 0;
    month = 0;
    day = 0;
    hour = 0;
    field18 = 0;
    year = *(unsigned short *)0x57dfbc;
    minute = 0;
    field10 = 0;
    seconds = 0;
    field19 = 0;
}
