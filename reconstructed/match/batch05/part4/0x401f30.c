/* Pak_DecodeIndex: decodes a pak index buffer in place (0x401f30). */
void __stdcall Pak_DecodeIndex(char *data, int count)
{
    int i;

    for (i = 0; i < count; i++)
        data[i] = (data[i] - (char)i) ^ 0xaa;
}
