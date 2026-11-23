// SubMenu_BuildAdvertisingCampaign: ported from Pizza Connection 2 at 0x46ac80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46ac80
#include "pc2_port.h"


void * __cdecl SubMenu_BuildAdvertisingCampaign(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the advertising campaign page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c5e00);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x46a,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x46b,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x46c,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x46d,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x46e,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x46f,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x470,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x471,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x472,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x473,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x474,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x475,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x476,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x477,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x478,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x479,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x47a,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x47b,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x47c,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x47d,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x47e,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x47f,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x480,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x481,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x482,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x483,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x484,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x485,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x486,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x487,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x488,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x489,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x48a,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x48b,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x48c,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x48d,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x48e,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x48f,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x490,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x491,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x492,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x493,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x494,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x495,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x496,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x497,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x498,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x499,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x49a,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x49b,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x49c,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x49d,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x49e,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x49f,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4a0,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4a1,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4a2,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4a3,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4a4,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4a5,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4a6,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4a7,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4a8,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4a9,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4aa,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4ab,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4ac,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4ad,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x42d,0x34,0x148,s_BLASENICONS_00_spr_00566c6c);
  UI_AddSprite(self,0x42e,0x66,0x146,s_BLASENICONS_01_spr_00566c58);
  UI_AddSprite(self,0x42f,0x98,0x148,s_BLASENICONS_02_spr_00566c44);
  UI_AddSprite(self,0x430,0xc9,0x147,s_BLASENICONS_03_spr_00566c30);
  UI_AddSprite(self,0x431,0x2f,0x83,s_TAB06_00_spr_00566c20);
  UI_AddSprite(self,0x408,0x27,0x147,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x439,0x96,0x12e,s_ZUTATICONS_00_spr_0056548c);
  UI_AddSprite(self,0x43a,0x36,0x12f,s_ZUTATICONS_01_spr_00565478);
  UI_AddSprite(self,0x43b,0x57,0x12f,s_ZUTATICONS_02_spr_00565464);
  UI_AddSprite(self,0x43c,0x77,0x12f,s_ZUTATICONS_03_spr_00565450);
  UI_AddSprite(self,0x43d,0xb5,0x12e,s_ZUTATICONS_04_spr_0056543c);
  UI_AddSprite(self,0x43e,0xd0,0x12e,s_ZUTATICONS_05_spr_00565428);
  UI_AddSprite(self,0x43f,0x96,0x12e,s_ZUTATICONS_06_spr_00565414);
  UI_AddSprite(self,0x440,0x36,0x12f,s_ZUTATICONS_07_spr_00565400);
  UI_AddSprite(self,0x441,0x57,0x12f,s_ZUTATICONS_08_spr_005653ec);
  UI_AddSprite(self,0x442,0x77,0x12f,s_ZUTATICONS_09_spr_005653d8);
  UI_AddSprite(self,0x443,0xb6,0x12e,s_ZUTATICONS_10_spr_005653c4);
  UI_AddSprite(self,0x444,0xd0,0x12f,s_ZUTATICONS_11_spr_005653b0);
  UI_AddSprite(self,0x445,0x96,0x12e,s_ZUTATICONS_12_spr_0056539c);
  UI_AddSprite(self,0x446,0x36,0x12f,s_ZUTATICONS_13_spr_00565388);
  UI_AddSprite(self,0x447,0x57,0x12f,s_ZUTATICONS_14_spr_00565374);
  UI_AddSprite(self,0x448,0x77,0x12f,s_ZUTATICONS_15_spr_00565360);
  UI_AddSprite(self,0x449,0xb6,0x12e,s_ZUTATICONS_16_spr_0056534c);
  UI_AddSprite(self,0x44a,0xd0,0x12f,s_ZUTATICONS_17_spr_00565338);
  value1 = UI_AddText(self,0x463,0x2f,0x114,s_VERDANA8_fnt_00563e98,DAT_005823bc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x463,0);
    Window_GadgetNotify_Text_SetLayout(self,0x463,0,0x37,0,0);
  }
  value1 = UI_AddText(self,0x464,0x2f,0x121,s_VERDANA8_fnt_00563e98,DAT_00582b48);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x464,0);
    Window_GadgetNotify_Text_SetLayout(self,0x464,0,0x55,0,0);
  }
  value1 = UI_AddText(self,0x465,0x4c,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582f70);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x465,0);
    Window_GadgetNotify_Text_SetLayout(self,0x465,0,0,0,0);
  }
  value1 = UI_AddText(self,0x466,0x72,0x82,s_VERDANA7_fnt_00563ec8,DAT_00580e88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x466,0);
    Window_GadgetNotify_Text_SetLayout(self,0x466,0,0,0,0);
  }
  value1 = UI_AddText(self,0x467,0xb0,0x82,s_VERDANA7_fnt_00563ec8,DAT_00582ac8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x467,0);
    Window_GadgetNotify_Text_SetLayout(self,0x467,0,0,0,0);
  }
  value1 = UI_AddText(self,0x469,0x2c,6,s_TIMESFONT_fnt_00563ea8,DAT_00580b5c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x469,0);
    Window_GadgetNotify_Text_SetLayout(self,0x469,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x4b0,0x51,0x93,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b0,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b1,0x76,0x93,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b1,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b1,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b2,0x76,0xa9,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b2,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b2,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b3,0x51,0xa9,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b3,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b4,0x76,0xd5,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b4,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b5,0x51,0xd5,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b5,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b6,0x51,0xbf,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b6,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b7,0x76,0xbf,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b7,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b8,0x51,0xeb,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b8,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4b9,0x76,0xeb,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4b9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4b9,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4ba,0x51,0x101,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ba,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ba,2,0x1e,0,0);
  }
  value1 = UI_AddText(self,0x4bb,0x76,0x101,s_VERDANA10_fnt_00563e64,&DAT_00566c1c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4bb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4bb,2,0x1e,0,0);
  }
  UI_AddSprite(self,0x4bd,0xc2,0x45,s_DUMMY_REST_08_spr_00566c08);
  value1 = UI_AddText(self,0x4bf,0x60,0x114,s_VERDANA8_fnt_00563e98,s__Billy_the_kid_00566bf8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4bf,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4bf,0,0x82,0xffff,0);
  }
  value1 = UI_CreateSlider(self,0x4c0,0xa3,0x97,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c0,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c1,0xc4,0x97,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c1,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c2,0xa3,0xad,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c2,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c3,0xc4,0xad,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c3,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c4,0xa3,0xc3,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c4,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c5,0xc4,0xc3,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c5,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c6,0xa3,0xd9,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c6,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c7,0xc4,0xd9,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c7,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c8,0xa3,0xef,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c8,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c9,0xc4,0xef,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c9,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4ca,0xa3,0x105,0x26,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4ca,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4cb,0xc4,0x105,0x26,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xef00;
    local_c = 0xef00;
    local_8 = 0xef00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4cb,&local_10);
  }
  value1 = UI_AddText(self,0x4cc,0x7b,0x25,s_VERDANA7_fnt_00563ec8,DAT_00582a44);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4cc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4cc,2,0x3c,0,0);
  }
  value1 = UI_CreateSlider(self,0x4cd,0x97,0x37,0x4b,s_SCVERTICAL00_00_spr_00566be4,1,1);
  if (value1 != 0) {
    local_10 = 0xe300;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4cd,&local_10);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f49,0x2f,0x89,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(self,0x1f4a,0x2f,0x9f,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(self,0x1f4b,0x30,0xb5,s_LOGOS__03_spr_005650d8);
  UI_AddSprite(self,0x1f4c,0x30,0xcc,s_LOGOS__04_spr_005664bc);
  UI_AddSprite(self,0x1f4d,0x2e,0xe1,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(self,0x1f4e,0x2f,0xf7,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(self,0x1f4f,0xb2,0x23,s_M_H_HQ_F3_0_spr_00566bd4);
  UI_AddSprite(self,0x1f50,0xb3,0x5c,s_M_H_KIRCHE_0_spr_00566bc0);
  UI_AddSprite(self,0x1f51,0x2d,0x21,s_M_TEEN_M01_spr_00566bb0);
  return self;
}
