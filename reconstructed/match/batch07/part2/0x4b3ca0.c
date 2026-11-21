/* CompanyOverview_Load (0x4b3ca0, 49 bytes).  Build: /O2 /TP.
   Reads the company overview fields from the save stream. */
extern int DAT_0056a7d4;
extern int DAT_0057d69c;
extern char DAT_0056a734;

struct CRT {
    void Istream_Read(void *destination, int size);
};

extern "C" void CompanyOverview_Load(void *stream)
{
    ((CRT *)stream)->Istream_Read(&DAT_0056a7d4, 4);
    ((CRT *)stream)->Istream_Read(&DAT_0057d69c, 4);
    ((CRT *)stream)->Istream_Read(&DAT_0056a734, 9);
}
