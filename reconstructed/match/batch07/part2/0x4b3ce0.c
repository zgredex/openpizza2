/* CompanyOverview_Save (0x4b3ce0, 49 bytes).  Build: /O2 /TP.
   Writes the company overview fields to the save stream. */
extern int DAT_0056a7d4;
extern int DAT_0057d69c;
extern char DAT_0056a734;

struct CRT {
    void Ostream_Write(void *source, int size);
};

extern "C" void CompanyOverview_Save(void *stream)
{
    ((CRT *)stream)->Ostream_Write(&DAT_0056a7d4, 4);
    ((CRT *)stream)->Ostream_Write(&DAT_0057d69c, 4);
    ((CRT *)stream)->Ostream_Write(&DAT_0056a734, 9);
}
