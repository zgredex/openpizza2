/* Stream_PeekChar: peeks the next buffered character (0x54d3be). */
struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int ReadChar();
    int field4;
    int field8;
    int fieldC;
    int PeekChar();
};

int Stream::PeekChar()
{
    if (field8 != 0) {
        if (fieldC == -1) {
            fieldC = ReadChar();
        }
        return fieldC;
    }
    return ReadChar();
}
