/* First attempt for 0x4b0d60 - does not match (dummy edx argument). */
extern void __fastcall CRT_Ostream_Write(void *stream, int unused, void *src,
                                         int size);
extern char DAT_0056a6d8;

void Personnel_Save(void *stream)
{
    CRT_Ostream_Write(stream, 0, &DAT_0056a6d8, 4);
}
