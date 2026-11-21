/* ListDialog_FillRows (0x4cb520): fills up to 19 list rows with button states
   and text records. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct UIGlobal {
    void Button_SetState(int id, int state);
    void Text_SetText(int id, char *text);
};

extern IDMap *DAT_0057de68;
extern UIGlobal *DAT_0057de30;
extern int DAT_0057de54;

extern "C" void ListDialog_FillRows(int start)
{
    int count = DAT_0057de68->count;
    int baseA;
    int baseB;

    if (0x13 < count)
        count = 0x13;
    else
        start = 0;
    if (0 < count) {
        int i = count;
        baseA = 2000 - start;
        baseB = 3000 - start;
        do {
            if (start == DAT_0057de54)
                DAT_0057de30->Button_SetState(baseA + start, 1);
            else
                DAT_0057de30->Button_SetState(baseA + start, 0);
            char *text = (char *)DAT_0057de68->Lookup(start, 0);
            DAT_0057de30->Text_SetText(baseB + start, text + 4);
            start++;
            i--;
        } while (i != 0);
    }
}
