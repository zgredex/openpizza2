/* UI_SetImageFromTemplate: composes the overlay window image from the
   template argument block (0x4cb860). */
struct TemplateArgs {
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    int field10;
    int field11;
    int field12;
    int field13;
    int field14;
    int field15;
    int field16;
    int field17;
    int field18;
    int field19;
    int field20;
    int field21;
    int field22;
    int field23;
    int field24;
    int field25;
    int field26;
    int field27;
    int field28;
    int field29;
    int field30;
    int field31;
    int field32;
    int field33;
    int field34;
    int field35;
    int field36;
    int field37;
    int field38;
    int field39;
    int field40;
    int field41;
    int field42;
    int field43;
    int field44;
    int field45;
    int field46;
    int field47;
    int field48;
    int field49;
};

struct UI {
    void ComposeOverlayWindow(int a1, int a2, int a3, int a4, int a5, int a6,
                              int a7);
};

void __cdecl UI_SetImageFromTemplate(struct TemplateArgs args)
{
    ((struct UI *)*(void **)0x57c5ec)->ComposeOverlayWindow(
        args.field0, args.field49, args.field41, args.field45, args.field43,
        args.field42, args.field44);
}
