/* Glossary_ShowIngredientDetail (0x4af2f0): fills the glossary ingredient
   detail fields from the current language strings. */
extern int DAT_0057d654;
extern int DAT_00583910[];
extern int DAT_00569f94[];

struct Window_GadgetNotify_Text {
    void SetText(int id, char *text);
};

struct UI {
    void SetButtonRecordVariant(int id, int variant);
};

struct GlossaryEntry {
    int name;
    int description;
    int effect;
};

void __cdecl Glossary_ShowIngredientDetail(void *param_1)
{
    ((Window_GadgetNotify_Text *)param_1)
        ->SetText(0x3fd,
                  (char *)((GlossaryEntry *)&DAT_00583910[DAT_0057d654 * 3])
                      ->name);
    ((Window_GadgetNotify_Text *)param_1)
        ->SetText(0x3fe,
                  (char *)((GlossaryEntry *)&DAT_00583910[DAT_0057d654 * 3])
                      ->description);
    ((Window_GadgetNotify_Text *)param_1)
        ->SetText(0x400,
                  (char *)((GlossaryEntry *)&DAT_00583910[DAT_0057d654 * 3])
                      ->effect);
    ((UI *)param_1)->SetButtonRecordVariant(0x1f55,
                                            DAT_00569f94[DAT_0057d654]);
}
