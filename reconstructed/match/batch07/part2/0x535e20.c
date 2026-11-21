/* Palette_WriteToStream (0x535e20, 48 bytes).  Build: /O2 /TP.
   Writes the 0x300-byte palette to the stream, creating the default palette
   first when none is loaded. */
extern char DAT_00574618;
extern "C" void NoOp_Stub(void *value);
extern "C" int CRT_FwriteLocked(void *buffer, int size, int count, int *stream);

struct Palette {
    void WriteToStream(int *stream);
};

void Palette::WriteToStream(int *stream)
{
    if (*(int *)this == 0)
        NoOp_Stub(&DAT_00574618);
    CRT_FwriteLocked(*(void **)this, 1, 0x300, stream);
}
