/* AI_CompanySlots_Load: clears and then reloads the six AI company slots from
   a stream (0x4f6dd0). */
struct IStream {
    void Read(void *destination, int size);
};

struct AISlots {
    void CompanySlots_Load(void *stream);
};

void AISlots::CompanySlots_Load(void *stream)
{
    char *self = (char *)this;
    void *saved = stream;
    int *slot = (int *)(self + 0x3c);
    int size;
    int count;

    for (count = 0x21c; count != 0; count--)
        *slot++ = 0;
    ((IStream *)saved)->Read(&size, 4);
    slot = (int *)(self + 0x3c);
    count = 6;
    do {
        ((IStream *)saved)->Read(slot, size);
        slot += 0x5a;
        count--;
    } while (count != 0);
}
