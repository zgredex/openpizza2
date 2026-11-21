/* PC2 byte-match candidate: StreamBuffer_Reset (0x53f820, 29 bytes).
   Build: /O2 /TP.  Zeroes the four stream buffer fields and succeeds. */
struct StreamBuffer {
    int fields[4];
};

int __stdcall StreamBuffer_Reset(StreamBuffer *buffer)
{
    int i;
    for (i = 0; i < 4; i++)
        buffer->fields[i] = 0;
    buffer->fields[0] = 0;
    return 1;
}
