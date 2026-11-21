/* PriceMenu_Init: initialise the price slider and recipe details
   (0x4c0b30). */
extern "C" int DAT_0057d70c;
extern "C" char DAT_00568834;

extern "C" void MenuPage_FillRecipeDetails(void *menu);

struct Window_GadgetNotify_Slider {
    void SetChangeNotify(int id, int enable);
    void SetValue(int id, int value, int flag);
    void AttachValueText(int id, int textId, char *format);
};

extern "C" void PriceMenu_Init(void *menu)
{
    struct Window_GadgetNotify_Slider *slider =
        (struct Window_GadgetNotify_Slider *)menu;

    slider->SetChangeNotify(0x1f4f, 1);
    slider->SetValue(0x1f4f, DAT_0057d70c, 0);
    slider->AttachValueText(0x1f4f, 0x1f51, &DAT_00568834);
    MenuPage_FillRecipeDetails(menu);
}
