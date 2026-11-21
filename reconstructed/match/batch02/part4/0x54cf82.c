/* PC2 byte-match candidate: Stream_GetAvailable (0x54cf82, 16 bytes).
   Build: /O2 /TP; entry _Stream_GetAvailable. */
extern "C" int __fastcall Stream_GetAvailable(char *stream)
{
    unsigned int position = *(unsigned int *)(stream + 0x28);
    unsigned int total = *(unsigned int *)(stream + 0x2c);

    if (position < total)
        return total - position;
    return 0;
}
