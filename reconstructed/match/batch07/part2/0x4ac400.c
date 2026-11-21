/* StatisticsBranchBalance_Save (0x4ac400, 49 bytes).  Build: /O2 /TP.
   Writes the three branch-balance fields to the save stream. */
extern int DAT_0056951c;
extern int DAT_0057d62c;
extern int DAT_0057d630;

struct CRT {
    void Ostream_Write(void *source, int size);
};

extern "C" void StatisticsBranchBalance_Save(void *stream)
{
    ((CRT *)stream)->Ostream_Write(&DAT_0056951c, 4);
    ((CRT *)stream)->Ostream_Write(&DAT_0057d62c, 4);
    ((CRT *)stream)->Ostream_Write(&DAT_0057d630, 4);
}
