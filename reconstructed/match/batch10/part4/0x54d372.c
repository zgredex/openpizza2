/* Stream_GetChar (0x54d372): returns the next character from the stream,
   refilling the internal buffer when needed. */
struct Stream {
    virtual int Slot0();
    virtual int Slot1();
    virtual int Slot2();
    virtual int Slot3();
    virtual int Slot4();
    virtual int Slot5();
    virtual int Slot6();
    virtual int Slot7();
    virtual int Refill();

    char pad[4];
    int mode;
    int cachedChar;
    char pad2[0x28 - 0x10];
    unsigned int position;
    unsigned int limit;

    int GetChar();
};

int Stream::GetChar()
{
    if (mode != 0) {
        if (cachedChar == -1)
            Refill();
        cachedChar = Refill();
        return cachedChar;
    }
    if (limit == 0 || position >= limit)
        Refill();
    ++position;
    if (position < limit)
        return *(unsigned char *)(unsigned int)position;
    return Refill();
}
