/* Stream_RequestBlock (0x5418c0). */
struct Stream {
    unsigned int flags;     /* 0x00 */
    int count;              /* 0x04 */
    char pad0[4];
    unsigned int capacity;  /* 0x0c */
    unsigned int position;  /* 0x10 */
    int initialCount;       /* 0x14 */

    int RequestBlock(int start, int size, int *outStart, unsigned int *outEnd);
};

int Stream::RequestBlock(int start, int size, int *outStart,
                         unsigned int *outEnd)
{
    *outStart = size;
    *outEnd = start + size;
    if ((flags & 1) != 0)
        return 1;
    if (start + size >= position) {
        int countValue;

        *outStart = position - start;
        *outEnd = capacity;
        if ((flags & 2) == 0) {
            countValue = --count;
            if (countValue == 0) {
                flags |= 1;
                count = initialCount;
            }
        }
    } else {
        return 0;
    }
    return 2;
}
