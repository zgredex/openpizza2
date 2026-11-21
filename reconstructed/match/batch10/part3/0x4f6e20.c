/* AI_CompanySlots_Save: write the AI company-slot table to a stream. */
struct OStream {
    void Write(void *data, int size);
};

struct AI {
    void CompanySlots_Save(OStream *stream);
};

void AI::CompanySlots_Save(OStream *stream)
{
    int size = 0x168;
    int i;

    stream->Write(&size, 4);
    for (i = 0; i < 6; i++)
        stream->Write((char *)this + 0x3c + i * 0x168, 0x168);
}
