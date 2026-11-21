extern int DAT_0057d5cc;
extern int DAT_0057d5c8;
extern int DAT_00582f6c;
extern int DAT_00582fc0[];
extern int DAT_00569354;
extern int DAT_00582ce0;
extern char DAT_005694e0[];
extern char DAT_005682ec[];

struct Gadget {
    void SetText(int id, void *text);
};

extern "C" int String_Format(char *buffer, const char *format, ...);

extern "C" void StatisticsBalance_UpdateHeader(void *page)
{
    Gadget *gadget = (Gadget *)page;
    if (DAT_0057d5cc == -1)
        gadget->SetText(0x4b4, (void *)DAT_00582f6c);
    else
        gadget->SetText(0x4b4, (void *)DAT_00582fc0[DAT_0057d5cc]);
    char buffer[0x40];
    if (DAT_0057d5c8 > 0) {
        String_Format(buffer, DAT_005682ec, DAT_0057d5c8, DAT_00582ce0,
                      DAT_00569354 % 100);
    } else {
        String_Format(buffer, DAT_005694e0, DAT_00569354);
    }
    gadget->SetText(0x4b7, buffer);
}
