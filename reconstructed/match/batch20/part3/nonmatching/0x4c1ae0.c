extern int DAT_0057c670;
extern int DAT_0057d724;
extern int DAT_0057d72c;
extern char DAT_00568834[];
extern char DAT_0056ad74[];

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Window {
    void GadgetNotify_Text_SetText(int id, char *text);
    void GadgetNotify_Text_SetTextColor(int id, int color);
    void GadgetNotify_Button_SetState(int id, int state);
};

struct LookupTable {
    bool HasKey(int key);
};

struct Storage {
    int GetSlotShare(int key);
};

extern "C" void Gadget_SetTextf(void *gadget, int id, char *format, ...);

void __cdecl DeliveryMenu_FillProductRows(void *param_1, int param_2)
{
    int recordSet = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int count = *(int *)(recordSet + 0x15c);

    if (count > 8)
        count = 8;
    else
        param_2 = 0;
    if (count > 0) {
        int offset = param_2 * 4;
        int button = 0x4b0;
        do {
            int *record = (int *)((IDMap *)(recordSet + 0x148))->Lookup(
                *(int *)(DAT_0057d72c + offset), 0);
            ((Window *)param_1)->GadgetNotify_Text_SetText(button, (char *)(record + 1));
            if (((LookupTable *)DAT_0057d724)->HasKey(record[0xf])) {
                ((Window *)param_1)->GadgetNotify_Text_SetTextColor(button, 0);
                ((Window *)param_1)->GadgetNotify_Button_SetState(button - 0x7a, 1);
                Gadget_SetTextf(param_1, button + 0x64, DAT_00568834,
                                ((Storage *)DAT_0057d724)->GetSlotShare(record[0xf]));
            } else {
                ((Window *)param_1)->GadgetNotify_Text_SetTextColor(button, 0xff);
                ((Window *)param_1)->GadgetNotify_Button_SetState(button - 0x7a, 0);
                Gadget_SetTextf(param_1, button + 0x64, DAT_0056ad74);
            }
            offset += 4;
            button++;
        } while (button - 0x4b0 < count);
    }
}
