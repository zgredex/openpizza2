struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
    void GadgetNotify_Text_SetText(int id, char *text);
    void GadgetNotify_Text_SetTextColor(int id, int color);
};

struct UI {
    void SetObjectTextByKey(int id, char *text);
};

struct IDMap {
    char *Lookup(int index, int *out);
};

struct IngredientDialog {
    char pad0[0x268];
    Window *window;
    char pad1[0x27c - 0x26c];
    IDMap *map;
    char pad2[0x28c - 0x280];
    int selected;
    void FillRows(int base);
};

void IngredientDialog::FillRows(int base)
{
    int limit = *(int *)((char *)map + 0x14);
    int count = 0xd;
    if (limit <= 0xd)
        count = limit;
    if (0 < count) {
        int key = 0x451;
        int index;
        do {
            index = base - 0x451 + key;
            window->GadgetNotify_Button_SetState(key - 0xd, index == selected ? 1 : 0);
            char *record = map->Lookup(index, 0);
            window->GadgetNotify_Text_SetText(key, record + 4);
            window->GadgetNotify_Text_SetTextColor(key, *(int *)(record + 0x54));
            if (*(char **)(record + 0x44) != 0)
                ((UI *)window)->SetObjectTextByKey(key - 0xd, *(char **)(record + 0x44));
            index = key - 0x450;
            key++;
        } while (index < count);
    }
}
