/* UI_GetCenteredRectForRecord: centers a record of the current player's
   company (0x4d31b0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct UI {
    char pad[0x24];
    int index;
    char pad2[0x24];
    int *records;
    void GetRecordCenteredRect(int index, int *left, int *top);
    void GetCenteredRectForRecord(int *left, int *top);
};

extern int DAT_0057c670;

void UI::GetCenteredRectForRecord(int *left, int *top)
{
    void *record = ((struct IDMap *)(DAT_0057c670 + 4))
                       ->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);

    ((struct UI *)*(int *)((int)record + 0xfa8))
        ->GetRecordCenteredRect(*(int *)((char *)this + 0x24), left, top);
}
