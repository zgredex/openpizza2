/* Stream_GetStatus: reports 0 while either stream state is set, otherwise
   maps the virtual status -1 to -1 and anything else to 1 (0x54dc89). */
struct Stream {
    int field4;
    int field8;
    int fieldC;
    int field10;
    virtual int Unused0();
    virtual int Unused1();
    virtual int Unused2();
    virtual int Unused3();
    virtual int Unused4();
    virtual int Unused5();
    virtual int Unused6();
    virtual int Unused7();
    virtual int Unused8();
    virtual int Unused9();
    virtual int GetVirtualStatus();
    int GetStatus();
};

int Stream::GetStatus()
{
    if (field8 != 0 || field10 != 0)
        return 0;
    return GetVirtualStatus() == -1 ? -1 : 1;
}
