/* PC2 byte-match candidate: Stream_ValidateRange (0x54dc72, 23 bytes).
   Build: /O1 /TP.  Returns -1 when either stream range is inverted. */
int __fastcall Stream_ValidateRange(int stream)
{
    if (*(unsigned int *)(stream + 0x28) < *(unsigned int *)(stream + 0x2c) ||
        *(unsigned int *)(stream + 0x1c) > *(unsigned int *)(stream + 0x18))
        return -1;
    return 0;
}
