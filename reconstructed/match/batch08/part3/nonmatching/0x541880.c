/* Parser_ResetTokenState: resets the stream and the parser token flags
   (0x541880). */
struct StreamBuffer {
    void Reset(void *state);
};

struct Parser {
    int flags;                 /* 0x0 */
    int token;                 /* 0x4 */
    int streamState;           /* 0x8 */
    char pad[0x14 - 0xc];
    int saved;                 /* 0x14 */
    void ResetTokenState(StreamBuffer *stream);
};

void Parser::ResetTokenState(StreamBuffer *stream)
{
    stream->Reset((char *)this + 8);
    if (*(int *)((char *)this + 8) == 0)
        *(int *)this = 1;
    if (*(int *)((char *)this + 4) == 0) {
        *(int *)this |= 2;
        return;
    }
    *(int *)((char *)this + 4) = *(int *)((char *)this + 0x14);
}
