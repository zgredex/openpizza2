/* CityCompanyList_Save: writes the two list fields to a stream (0x498130). */
struct Stream {
    int Write(void *buffer, int size);
};

extern int DAT_0057c9fc;
extern int DAT_0057ca00;

void __cdecl CityCompanyList_Save(Stream *stream)
{
    stream->Write(&DAT_0057c9fc, 4);
    stream->Write(&DAT_0057ca00, 4);
}
