/* Stream_SetBuffer (0x54d921, 47 bytes).  Build: /O1 /TP (size-optimized:
   the original uses memory-form flag updates and a branch to the OR path). */
struct StreamObject {
    virtual void Close(int immediate);
};

struct Stream {
    int pad_00;
    StreamObject *buffer;      /* +4 */
    int flags;                 /* +8 */
    char pad_0c[0x10];
    int field_1c;              /* +0x1c */
    void SetBuffer(int newBuffer);
};

void Stream::SetBuffer(int newBuffer)
{
    if (field_1c != 0 && buffer != 0)
        buffer->Close(1);
    buffer = (StreamObject *)newBuffer;
    if (newBuffer != 0)
        flags &= ~4;
    else
        flags |= 4;
}
