/* Stream_PutBackChar: pushes one character back into the stream (0x54d574). */
struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int WriteChar(int value);
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    unsigned int field24;
    unsigned int field28;
    int PutBackChar(char value);
};

int Stream::PutBackChar(char value)
{
    if (field24 < field28) {
        char *position = (char *)(field28 - 1);
        field28 = (unsigned int)position;
        *position = value;
        return value;
    }
    return WriteChar(value);
}
