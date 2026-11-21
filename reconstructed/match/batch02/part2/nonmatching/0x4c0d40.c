/* First attempt for 0x4c0d40 - does not match (dummy edx argument). */
extern void __fastcall CRT_Istream_Read(void *stream, int unused, void *dest,
                                        int size);
extern char DAT_0057d714;

void WarehouseProduct_Load(void *stream)
{
    CRT_Istream_Read(stream, 0, &DAT_0057d714, 4);
}
