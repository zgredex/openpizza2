
/* SoundOptions_Init: initializes the sound option sliders from the current
   global settings (0x4a1170). */
extern char *DAT_0057ba0c;

struct Options {
    void GetGlobalSettings(int *settings);
};

struct Window {
    void GadgetNotify_Slider_SetRange(int id, int min, int max, int flag);
    void GadgetNotify_Slider_SetValue(int id, int value, int flag);
    void GadgetNotify_Slider_SetChangeNotify(int id, int flag);
    void GadgetNotify_Button_SetState(int id, int state);
};

extern "C" void SoundOptions_Init(Window *ui)
{
    int settings[4];

    ((Options *)DAT_0057ba0c)->GetGlobalSettings(settings);
    ui->GadgetNotify_Slider_SetRange(0x43a, 0, 10000, 0);
    ui->GadgetNotify_Slider_SetValue(0x43a, settings[1], 0);
    ui->GadgetNotify_Slider_SetChangeNotify(0x43a, 1);
    ui->GadgetNotify_Slider_SetRange(0x43b, 0, 10000, 0);
    ui->GadgetNotify_Slider_SetValue(0x43b, settings[2], 0);
    ui->GadgetNotify_Slider_SetChangeNotify(0x43b, 1);
    ui->GadgetNotify_Slider_SetRange(0x43c, 0, 10000, 0);
    ui->GadgetNotify_Slider_SetValue(0x43c, settings[3], 0);
    ui->GadgetNotify_Slider_SetChangeNotify(0x43c, 1);
    ui->GadgetNotify_Button_SetState(0x1f53, *((char *)settings + 1) == 0);
}
