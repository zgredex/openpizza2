/* Stream_Seek: moves the stream position with origin 0/1/2 and clamps it to
   the stream length (0x540000). */
void __stdcall Stream_Seek(int offset, int stream, int origin)
{
    switch (origin) {
    case 0:
        *(int *)(stream + 0x10) = offset;
        break;
    case 1:
        *(int *)(stream + 0x10) = *(int *)(stream + 0x10) + offset;
        break;
    case 2:
        *(int *)(stream + 0x10) = *(int *)(stream + 8) - offset;
        break;
    }
    if (*(unsigned int *)(stream + 0x10) > *(unsigned int *)(stream + 8))
        *(int *)(stream + 0x10) = *(int *)(stream + 8);
}
