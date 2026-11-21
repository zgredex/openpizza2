/* Non-matching candidate.
   First difference: offset 0x6, 110 bytes differ.
   original keeps the clamped start in ebp and window in ebx; candidate spills the start and uses ebp for the window.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057cdb4;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Window {
    void Text_SetText(int id, void *text);
    void Text_SetTextColor(int id, int color);
    void SetObjectTextByKey(int id, void *text);
};

extern "C" void SaveGameMenu_UpdateSlotRows(void *window, int offset)
{
    int count = *(int *)((char *)DAT_0057cdb4 + 0x14);
    int start;
    if (count <= 13) {
        start = 0;
    } else {
        start = offset;
        count = 13;
    }
    if (count > 0) {
        int id = 0x453;
        do {
            int *record = (int *)((IDMap *)DAT_0057cdb4)
                              ->Lookup(id - 0x453 + start, 0);
            ((Window *)window)->Text_SetText(id, (char *)record + 4);
            ((Window *)window)->Text_SetTextColor(
                id, *(int *)((char *)record + 0x54));
            if (*(char **)((char *)record + 0x44) != 0)
                ((Window *)window)->SetObjectTextByKey(
                    id - 0xf, *(char **)((char *)record + 0x44));
            id++;
        } while (id - 0x453 < count);
    }
}
