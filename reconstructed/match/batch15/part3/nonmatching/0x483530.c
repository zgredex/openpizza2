/* Non-matching candidate.
   First difference: offset 0x1, 107 bytes differ.
   original keeps this in edi and the index in esi; candidate uses esi for this and edi for the index.
   Kept for evidence; not part of the strict match set. */
extern int g_CityOverviewDialog_FillRows_RData[];

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Window {
    void Button_SetState(int id, int state);
    void Text_SetText(int id, void *text);
};

struct CityOverviewDialog {
    char pad0[0x268];
    Window *window;
    char pad1[0x27c - 0x26c];
    IDMap *map;
    char pad2[0x284 - 0x280];
    int highlight;
    void FillRows(int start);
};

void CityOverviewDialog::FillRows(int start)
{
    int count = *(int *)((char *)map + 0x14);
    int index;

    if (count < 6) {
        index = 0;
    } else {
        count = 5;
        index = start;
    }
    if (count > 0) {
        int *values = g_CityOverviewDialog_FillRows_RData;
        int text_id = 0x3f0 - index;
        int remaining = count;
        do {
            if (index == highlight)
                window->Button_SetState(*values, 1);
            else
                window->Button_SetState(*values, 0);
            void *record = map->Lookup(index, 0);
            window->Text_SetText(index + text_id, (char *)record + 4);
            values++;
            index++;
            remaining--;
        } while (remaining != 0);
    }
}
