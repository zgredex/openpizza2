/* Stream_PutByte: writes one byte to a stream buffer or its slow path (0x54cc09). */
struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned int PutSlow(unsigned int value);
    char pad[0x1c - 4];
    unsigned char *cursor;
    unsigned char *limit;
    unsigned int PutByte(unsigned int value);
};

unsigned int Stream::PutByte(unsigned int value)
{
    if (cursor < limit) {
        *cursor = (unsigned char)value;
        cursor++;
        return (unsigned char)value;
    }
    return PutSlow(value);
}
