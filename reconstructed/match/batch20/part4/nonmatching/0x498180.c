extern int DAT_0057c670;
extern int DAT_0057ca08[];
extern int DAT_0057c9fc;
extern int DAT_00568890[];
extern char DAT_005688b0[];

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
    void GadgetNotify_Text_SetText(int id, char *text);
};

extern "C" int String_Format(char *buffer, char *format, ...);
float __fastcall Get_Float44(int record);

void __cdecl BranchList_UpdateRows(void *param_1, int param_2)
{
    int recordSet = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int count = *(int *)(recordSet + 0x124);
    char buffer[36];

    if (count > 8)
        count = 8;
    else
        param_2 = 0;
    if (count > 0) {
        int offset = param_2 * 4;
        int *ids = DAT_00568890;
        int i;
        for (i = 0; i < count; i++) {
            int key = *(int *)(offset + (int)DAT_0057ca08);
            ((Window *)param_1)->GadgetNotify_Button_SetState(
                0x461 + i, key == DAT_0057c9fc);
            int *record = (int *)((IDMap *)(recordSet + 0x110))->Lookup(key, 0);
            ((Window *)param_1)->GadgetNotify_Text_SetText(*ids, (char *)(record + 1));
            String_Format(buffer, DAT_005688b0, Get_Float44((int)record));
            ((Window *)param_1)->GadgetNotify_Text_SetText(0x461 + i + 0xa4, buffer);
            offset += 4;
            ids++;
        }
    }
}
