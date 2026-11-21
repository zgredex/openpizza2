/* File_WriteBytes: writes a byte block through the buffered or virtual write
   path and returns the number of bytes written (0x54db85). */
struct File {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int WriteByte(int value);

    char pad[4];
    int field8;
    char pad2[0x10];
    unsigned char *cursor;
    unsigned char *limit;

    int WriteBytes(unsigned char *data, int count);
};

int File::WriteBytes(unsigned char *data, int count)
{
    int written;

    written = 0;
    while (count--) {
        if (field8 == 0 && cursor < limit) {
            *cursor++ = *data;
        } else {
            if (WriteByte(*data) == -1) {
                return written;
            }
        }
        data++;
        written++;
    }
    return written;
}
