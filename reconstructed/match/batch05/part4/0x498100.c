/* CityCompanyList_Load: reads the two list fields from a stream (0x498100). */
struct Stream {
    int Read(void *buffer, int size);
};

extern int DAT_0057c9fc;
extern int DAT_0057ca00;

void __cdecl CityCompanyList_Load(Stream *stream)
{
    stream->Read(&DAT_0057c9fc, 4);
    stream->Read(&DAT_0057ca00, 4);
}
