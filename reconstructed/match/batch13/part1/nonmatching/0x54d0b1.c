/* Stream_TryAttachBuffer (0x54d0b1). */
struct Stream {
    char pad0[8];
    int state;              /* 0x08 */
    char pad1[8];           /* to 0x14 */
    int attached;           /* 0x14 */
    char pad2[0x18];        /* to 0x30 */
    int lockCount;          /* 0x30 */
    char lock[0x18];        /* 0x34 */
    int block;              /* 0x4c */

    void *TryAttachBuffer(int buffer, int size);
    void AttachBuffer(int start, int end, int flag);
};

extern void CS_EnterRaw(void *cs);
extern void CS_LeaveRaw(void *cs);

void *Stream::TryAttachBuffer(int buffer, int size)
{
    Stream *result = this;

    if (block == -1 || attached == 0) {
        if (buffer == 0 || size < 1) {
            state = 1;
        } else {
            if (lockCount < 0)
                CS_EnterRaw(lock);
            AttachBuffer(buffer, buffer + size, 0);
            if (lockCount < 0)
                CS_LeaveRaw(lock);
        }
    } else {
        result = 0;
    }
    return result;
}
