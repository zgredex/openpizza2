/* Stats_Report_ConstructEmpty: initialises an empty statistics report
   (0x4010f0). */
extern char DAT_0055c2e0;
extern char *DAT_00582e4c;
extern "C" int __cdecl String_Format(char *buffer, char *format);

struct StatsReport {
    StatsReport *ConstructEmpty(int first, int second);
};

StatsReport *StatsReport::ConstructEmpty(int first, int second)
{
    int *cursor;
    char *text;
    int i;

    *(void **)this = &DAT_0055c2e0;
    cursor = (int *)((char *)this + 0x78);
    for (i = 0x19; i != 0; i--) {
        *cursor = 0;
        cursor++;
    }
    cursor = (int *)((char *)this + 0x10);
    for (i = 0x1a; i != 0; i--) {
        *cursor = 0;
        cursor++;
    }
    text = (char *)this + 0xdc;
    i = 0x14;
    do {
        String_Format(text, DAT_00582e4c);
        text += 0x20;
        i--;
    } while (i != 0);
    *(int *)((char *)this + 0xc) = -1;
    *(int *)((char *)this + 4) = first;
    *(int *)((char *)this + 8) = second;
    return this;
}
