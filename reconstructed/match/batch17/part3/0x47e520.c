struct Game {
    char pad0[0x16f5];
    char closed;
    char pad1[0x1a08 - 0x16f6];
    char hours[0x18];
    int CountOperatingObjectsByType(int type);
    void GetDateFields(unsigned *hour, unsigned *minute);
    int IsBuildingOpenAtHour(int index);
};

extern Game *DAT_0057c670;

int Game::IsBuildingOpenAtHour(int index)
{
    if (*(char *)((char *)this + 0x16f5) != 0)
        return 0;
    if (CountOperatingObjectsByType(0) == 0)
        return 0;
    unsigned hour;
    unsigned minute;
    DAT_0057c670->GetDateFields(&hour, &minute);
    if (*(unsigned char *)((char *)this + 0x1a08 + hour) != 0)
        return 1;
    if (0x3b < (int)minute) {
        unsigned carry = minute / 0x3c;
        minute = minute - carry * 0x3c;
        hour = hour + carry;
    }
    if (0x17 < (int)hour) {
        unsigned days = hour / 0x18;
        hour = hour - days * 0x18;
    }
    return *(unsigned char *)((char *)this + 0x1a08 + hour);
}
