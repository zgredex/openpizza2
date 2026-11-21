/* StatisticsBranchBalance_Load (0x4ac3c0, 49 bytes).  Build: /O2 /TP.
   Reads the three branch-balance fields from the save stream. */
extern int DAT_0056951c;
extern int DAT_0057d62c;
extern int DAT_0057d630;

struct CRT {
    void Istream_Read(void *destination, int size);
};

extern "C" void StatisticsBranchBalance_Load(void *stream)
{
    ((CRT *)stream)->Istream_Read(&DAT_0056951c, 4);
    ((CRT *)stream)->Istream_Read(&DAT_0057d62c, 4);
    ((CRT *)stream)->Istream_Read(&DAT_0057d630, 4);
}
