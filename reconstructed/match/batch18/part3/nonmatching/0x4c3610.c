extern int DAT_0057d738;
extern int DAT_0057d734;
extern void *DAT_0057d73c;
extern char *DAT_0057c670;
extern char DAT_004c32f0;
extern char STR_0056ae18[];

extern "C" void OvenPage_FillStatistics(void *page);
extern "C" void String_Format(char *buffer, char *format, char *argument);

/* FurnitureMenu_InitOvenPage: initializes the oven furniture submenu page
   (0x4c3610). */
struct Branch {
    void *CollectOrdersByCategory(int category);
};

struct IDMap {
    void *Lookup(int index, int *unused);
};

struct UI {
    void SetPosition(void *position, int index);
    void SetButtonSpriteByName(int id, char *name);
};

extern "C" void UI_InitOvenPage(UI *ui)
{
    int i;
    int record;

    DAT_0057d738 = 0;
    char local_100[256];
    DAT_0057d734 = *(int *)(DAT_0057c670 + 0x220);
    DAT_0057d73c = ((Branch *)(*(void **)(DAT_0057c670 + 0x9c)))->CollectOrdersByCategory(5);
    i = 0;
    if (0 < *(int *)((char *)DAT_0057d73c + 0x14)) {
        do {
            record = (int)((IDMap *)DAT_0057d73c)->Lookup(i, 0);
            if (record == DAT_0057d734) {
                DAT_0057d738 = i;
            }
            i = i + 1;
        } while (i < *(int *)((char *)DAT_0057d73c + 0x14));
    }
    ui->SetPosition(&DAT_004c32f0, 0);
    if (DAT_0057d734 != 0) {
        OvenPage_FillStatistics(ui);
        record = (int)((IDMap *)(DAT_0057c670 + 0x74))->Lookup(*(int *)(DAT_0057d734 + 4), 0);
        String_Format(local_100, STR_0056ae18, (char *)record + 0x40);
        ui->SetButtonSpriteByName(0x1f41, local_100);
    }
}
