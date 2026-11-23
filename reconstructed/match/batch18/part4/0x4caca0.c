extern int DAT_005812b8;
extern int DAT_005812cc;
extern int DAT_00581674;
extern int DAT_0058167c;
extern int DAT_00581684;
extern int DAT_00581688;
extern int DAT_00581690;
extern int DAT_005816a0;
extern int DAT_005816ac;
extern int DAT_005821f0;

extern "C" void UI_SetMultipleLabels(void *ui, int *labels);

/* UI_ShowPanel: labels the panel controls with the current building names
   (0x4caca0). */
extern "C" void UI_ShowPanel(void *ui)
{
    int labels[22];

    labels[0] = 0x5a5;
    labels[1] = DAT_005812cc;
    labels[2] = 0x4ac;
    labels[3] = DAT_005812b8;
    labels[4] = 0x5a7;
    labels[5] = DAT_0058167c;
    labels[6] = 0x4ae;
    labels[7] = DAT_00581674;
    labels[8] = 0x4ab;
    labels[9] = DAT_00581688;
    labels[10] = 0x4b0;
    labels[11] = DAT_00581684;
    labels[12] = 0x4b1;
    labels[13] = DAT_005816a0;
    labels[14] = 0x4af;
    labels[15] = DAT_00581690;
    labels[16] = 0x4aa;
    labels[17] = DAT_005816ac;
    labels[18] = 0x4d0;
    labels[19] = DAT_005821f0;
    labels[20] = -1;
    labels[21] = 0;
    UI_SetMultipleLabels(ui, labels);
}
