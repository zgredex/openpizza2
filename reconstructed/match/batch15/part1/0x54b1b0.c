/* UI_BriefingList_Save: writes the briefing list to a stream (0x54b1b0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Stream {
    void Write(void *data, int size);
};

struct UI {
    void Save(Stream *stream);
};

void UI::Save(Stream *stream)
{
    int count = *(int *)((char *)this + 0x18);
    int index;
    int i;

    stream->Write(&count, 4);
    for (i = 0; i < count; i++) {
        int *record = (int *)((struct IDMap *)((char *)this + 4))
                          ->Lookup(i, &index);
        int length = record[0];

        stream->Write(&index, 4);
        stream->Write(&length, 4);
        stream->Write(record, length);
    }
}
