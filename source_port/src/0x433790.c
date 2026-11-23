// Window_BuildStatisticsBranchBalancePage: ported from Pizza Connection 2 at 0x433790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x433790
#include "pc2_port.h"


void * __cdecl Window_BuildStatisticsBranchBalancePage(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the branch-balance statistics page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_STATISTIKFILIALBILANZ_spr_00565b30,&LAB_004adc80);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_CreateBitmapGadget(self,0x88e,0x178,0x55,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x88f,0x178,0x6e,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x890,0x178,0xa1,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x891,0x178,0x87,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x892,0x178,0xb9,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x893,0x178,0xd2,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x894,0x178,0xeb,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x895,0x178,0x104,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x896,0x178,0x11d,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x897,0x178,0x136,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x898,0x1a2,0x55,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x899,0x1a2,0x6e,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89a,0x1a2,0x87,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89b,0x1a2,0xa1,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89c,0x1a2,0xb9,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89d,0x1a2,0xd2,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89e,0x1a2,0xeb,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x89f,0x1a2,0x104,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a0,0x1a2,0x11d,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a1,0x1a2,0x136,0x25,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a2,0x1cf,0x55,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a3,0x1cf,0x6e,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a4,0x1cf,0x87,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a5,0x1cf,0xa1,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a6,0x1cf,0xb9,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a7,0x1cf,0xd2,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a8,0x1cf,0xeb,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8a9,0x1cf,0x104,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8aa,0x1cf,0x11d,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x8ab,0x1cf,0x136,0x5f,0x10,0x10);
  UI_CreateBitmapGadget(self,0x86b,0xc1,0x167,0x15e,0xa0,0x10);
  value1 = UI_AddText(self,1000,0x25d,0xdf,s_TIMESFONT_fnt_00563ea8,DAT_00582740);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,1000,0);
    Window_GadgetNotify_Text_SetLayout(self,1000,2,0xbe,0xffff,0);
  }
  UI_AddImage(self,0x3e9,0x263,0x116,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ea,0x263,0x135,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3eb,0x263,0x14a,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ec,0x263,0x15f,s_TABPB01__00_spr_00564670,0,0);
  UI_AddImage(self,0x3ed,0x263,0x174,s_TABPB01__00_spr_00564670,0,0);
  value1 = UI_CreateSlider(self,0x3f2,0x30e,0x13c,0x60,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x3f2,&local_10);
  }
  UI_AddSprite(self,0x3f3,600,0x1a8,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x3fb,0x29d,0x11b,s_VERDANA7_fnt_00563ec8,s___1_00_000_000__005658b0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fb,1,100,0xffff,0);
  }
  value1 = UI_AddText(self,0x3f8,0x266,0x11a,s_VERDANA7_fnt_00563ec8,DAT_00581874);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f8,0,0x3c,0xffff,0);
  }
  value1 = UI_AddText(self,0x3f9,0x266,0x13a,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3f9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3f9,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fa,0x2b8,0x13a,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fa,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fa,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fc,0x266,0x14f,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fc,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fd,0x2b8,0x14f,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fd,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fd,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x3fe,0x266,0x164,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3fe,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3fe,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x3ff,0x2b8,0x164,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3ff,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3ff,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x400,0x266,0x179,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x400,0);
    Window_GadgetNotify_Text_SetLayout(self,0x400,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x401,0x2b8,0x179,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x401,0);
    Window_GadgetNotify_Text_SetLayout(self,0x401,1,0x48,0xffff,0);
  }
  value1 = UI_AddText(self,0x40a,0x261,0x1b9,s_VERDANA8_fnt_00563e98,DAT_00582d08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40a,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x40b,0x261,0x102,s_VERDANA8_fnt_00563e98,DAT_005829c4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40b,0,0xaa,0xffff,0);
  }
  value1 = UI_AddText(self,0x40c,0x288,0x1cf,s_VERDANA7_fnt_00563ec8,DAT_00582b40);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40c,2,0x69,0xffff,0);
  }
  UI_AddImage(self,0x4b3,0x268,0x1e1,s_SKFILIALPERSONAL_00_spr_00565b18,1,0);
  UI_AddImage(self,0x4b4,0x2aa,0x1e1,s_SKFILIALMONEY_00_spr_00565b00,1,0);
  UI_AddImage(self,0x4b5,0x2ec,0x1e1,s_SKFILIALAUSLASTUNG_00_spr_00565ae4,1,0);
  UI_AddImage(self,0x4b8,0x2ec,0x227,s_SKBILANZ_00_spr_00565ad4,1,0);
  UI_AddImage(self,0x4b9,0x263,0x189,s_TABPB01__00_spr_00564670,0,0);
  value1 = UI_AddText(self,0x4ba,0x266,0x18e,s_VERDANA7_fnt_00563ec8,s__Filialname_005644d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ba,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ba,0,0x55,0xffff,0);
  }
  value1 = UI_AddText(self,0x4bb,0x2b8,0x18e,s_VERDANA7_fnt_00563ec8,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4bb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4bb,1,0x48,0xffff,0);
  }
  value1 = UI_CreateSlider(self,0x4be,0x24,0xb7,0x46,s_SCSPEZIAL1_00_spr_00565ac0,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xaa00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4be,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4bf,0x65,0xb7,0x46,s_SCSPEZIAL2_00_spr_00565aac,1,0);
  if (value1 != 0) {
    local_10 = 0xaa00;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4bf,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c0,0x25,0xda,0x89,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf000;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c0,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c1,0x25,0xfa,0x89,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf000;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c1,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c2,0x25,0x13a,0x89,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf000;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c2,&local_10);
  }
  value1 = UI_CreateSlider(self,0x4c3,0x25,0x11a,0x89,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xf000;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x4c3,&local_10);
  }
  UI_AddSprite(self,0x4c4,0xf5,0x4f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4c5,0xf5,0x4f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4c6,0xf5,0x4f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4c7,0xf5,0x4f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4c8,0xf5,0x4f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4c9,0xf5,0x4f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4ca,0xf5,0x4f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4cb,0xf5,0x4f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4cc,0xf5,0x4f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4cd,0xf5,0x4f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4ce,0xf5,0x4f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4cf,0xf5,0x4f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4d0,0xf5,0x4f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4d1,0xf5,0x4f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4d2,0xf5,0x4f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4d3,0xf5,0x4f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4d4,0xf5,0x4f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4d5,0x10f,0x4f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4d6,0x10f,0x4f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4d7,0x10f,0x4f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4d8,0x10f,0x4f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4d9,0x10f,0x4f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4da,0x10f,0x4f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4db,0x10f,0x4f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4dc,0x10f,0x4f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4dd,0x10f,0x4f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4de,0x10f,0x4f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4df,0x10f,0x4f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4e0,0x10f,0x4f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4e1,0x10f,0x4f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4e2,0x10f,0x4f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4e3,0x10f,0x4f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4e4,0x10f,0x4f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4e5,0x10f,0x4f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4e6,0x129,0x4f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4e7,0x129,0x4f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4e8,0x129,0x4f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4e9,0x129,0x4f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4ea,0x129,0x4f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4eb,0x129,0x4f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4ec,0x129,0x4f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4ed,0x129,0x4f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4ee,0x129,0x4f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4ef,0x129,0x4f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4f0,0x129,0x4f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4f1,0x129,0x4f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4f2,0x129,0x4f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4f3,0x129,0x4f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4f4,0x129,0x4f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4f5,0x129,0x4f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4f6,0x129,0x4f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4f7,0x143,0x4f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4f8,0x143,0x4f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4f9,0x143,0x4f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4fa,0x143,0x4f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4fb,0x143,0x4f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4fc,0x143,0x4f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4fd,0x143,0x4f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4fe,0x143,0x4f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4ff,0x143,0x4f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x500,0x143,0x4f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x501,0x143,0x4f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x502,0x143,0x4f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x503,0x143,0x4f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x504,0x143,0x4f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x505,0x143,0x4f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x506,0x143,0x4f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x507,0x143,0x4f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x508,0x15d,0x4f,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x509,0x15d,0x4f,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x50a,0x15d,0x4f,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x50b,0x15d,0x4f,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x50c,0x15d,0x4f,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x50d,0x15d,0x4f,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x50e,0x15d,0x4f,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x50f,0x15d,0x4f,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x510,0x15d,0x4f,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x511,0x15d,0x4f,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x512,0x15d,0x4f,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x513,0x15d,0x4f,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x514,0x15d,0x4f,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x515,0x15d,0x4f,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x516,0x15d,0x4f,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x517,0x15d,0x4f,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x518,0x15d,0x4f,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x52a,0xf5,0x68,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x52b,0xf5,0x68,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x52c,0xf5,0x68,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x52d,0xf5,0x68,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x52e,0xf5,0x68,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x52f,0xf5,0x68,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x530,0xf5,0x68,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x531,0xf5,0x68,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x532,0xf5,0x68,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x533,0xf5,0x68,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x534,0xf5,0x68,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x535,0xf5,0x68,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x536,0xf5,0x68,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x537,0xf5,0x68,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x538,0xf5,0x68,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x539,0xf5,0x68,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x53a,0xf5,0x68,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x53b,0x10f,0x68,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x53c,0x10f,0x68,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x53d,0x10f,0x68,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x53e,0x10f,0x68,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x53f,0x10f,0x68,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x540,0x10f,0x68,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x541,0x10f,0x68,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x542,0x10f,0x68,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x543,0x10f,0x68,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x544,0x10f,0x68,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x545,0x10f,0x68,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x546,0x10f,0x68,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x547,0x10f,0x68,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x548,0x10f,0x68,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x549,0x10f,0x68,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x54a,0x10f,0x68,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x54b,0x10f,0x68,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x54c,0x129,0x68,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x54d,0x129,0x68,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x54e,0x129,0x68,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x54f,0x129,0x68,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x550,0x129,0x68,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x551,0x129,0x68,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x552,0x129,0x68,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x553,0x129,0x68,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x554,0x129,0x68,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x555,0x129,0x68,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x556,0x129,0x68,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x557,0x129,0x68,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x558,0x129,0x68,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x559,0x129,0x68,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x55a,0x129,0x68,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x55b,0x129,0x68,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x55c,0x129,0x68,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x55d,0x143,0x68,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x55e,0x143,0x68,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x55f,0x143,0x68,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x560,0x143,0x68,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x561,0x143,0x68,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x562,0x143,0x68,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x563,0x143,0x68,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x564,0x143,0x68,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x565,0x143,0x68,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x566,0x143,0x68,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x567,0x143,0x68,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x568,0x143,0x68,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x569,0x143,0x68,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x56a,0x143,0x68,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x56b,0x143,0x68,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x56c,0x143,0x68,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x56d,0x143,0x68,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x56e,0x15d,0x68,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x56f,0x15d,0x68,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x570,0x15d,0x68,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x571,0x15d,0x68,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x572,0x15d,0x68,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x573,0x15d,0x68,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x574,0x15d,0x68,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x575,0x15d,0x68,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x576,0x15d,0x68,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x577,0x15d,0x68,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x578,0x15d,0x68,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x579,0x15d,0x68,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x57a,0x15d,0x68,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x57b,0x15d,0x68,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x57c,0x15d,0x68,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x57d,0x15d,0x68,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x57e,0x15d,0x68,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x57f,0xf5,0x81,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x580,0xf5,0x81,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x581,0xf5,0x81,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x582,0xf5,0x81,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x583,0xf5,0x81,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x584,0xf5,0x81,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x585,0xf5,0x81,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x586,0xf5,0x81,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x587,0xf5,0x81,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x588,0xf5,0x81,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x589,0xf5,0x81,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x58a,0xf5,0x81,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x58b,0xf5,0x81,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x58c,0xf5,0x81,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x58d,0xf5,0x81,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x58e,0xf5,0x81,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x58f,0xf5,0x81,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x590,0x10f,0x81,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x591,0x10f,0x81,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x592,0x10f,0x81,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x593,0x10f,0x81,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x594,0x10f,0x81,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x595,0x10f,0x81,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x596,0x10f,0x81,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x597,0x10f,0x81,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x598,0x10f,0x81,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x599,0x10f,0x81,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x59a,0x10f,0x81,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x59b,0x10f,0x81,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x59c,0x10f,0x81,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x59d,0x10f,0x81,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x59e,0x10f,0x81,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x59f,0x10f,0x81,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5a0,0x10f,0x81,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5a1,0x129,0x81,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5a2,0x129,0x81,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5a3,0x129,0x81,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5a4,0x129,0x81,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5a5,0x129,0x81,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5a6,0x129,0x81,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5a7,0x129,0x81,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5a8,0x129,0x81,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5a9,0x129,0x81,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5aa,0x129,0x81,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5ab,0x129,0x81,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5ac,0x129,0x81,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5ad,0x129,0x81,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5ae,0x129,0x81,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5af,0x129,0x81,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5b0,0x129,0x81,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5b1,0x129,0x81,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5b2,0x143,0x81,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5b3,0x143,0x81,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5b4,0x143,0x81,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5b5,0x143,0x81,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5b6,0x143,0x81,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5b7,0x143,0x81,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5b8,0x143,0x81,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5b9,0x143,0x81,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5ba,0x143,0x81,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5bb,0x143,0x81,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5bc,0x143,0x81,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5bd,0x143,0x81,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5be,0x143,0x81,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5bf,0x143,0x81,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5c0,0x143,0x81,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5c1,0x143,0x81,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5c2,0x143,0x81,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5c3,0x15d,0x81,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5c4,0x15d,0x81,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5c5,0x15d,0x81,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5c6,0x15d,0x81,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5c7,0x15d,0x81,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5c8,0x15d,0x81,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5c9,0x15d,0x81,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5ca,0x15d,0x81,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5cb,0x15d,0x81,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5cc,0x15d,0x81,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5cd,0x15d,0x81,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5ce,0x15d,0x81,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5cf,0x15d,0x81,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5d0,0x15d,0x81,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5d1,0x15d,0x81,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5d2,0x15d,0x81,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5d3,0x15d,0x81,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5d4,0xf5,0x9a,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5d5,0xf5,0x9a,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5d6,0xf5,0x9a,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5d7,0xf5,0x9a,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5d8,0xf5,0x9a,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5d9,0xf5,0x9a,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5da,0xf5,0x9a,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5db,0xf5,0x9a,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5dc,0xf5,0x9a,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5dd,0xf5,0x9a,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5de,0xf5,0x9a,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5df,0xf5,0x9a,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5e0,0xf5,0x9a,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5e1,0xf5,0x9a,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5e2,0xf5,0x9a,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5e3,0xf5,0x9a,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5e4,0xf5,0x9a,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5e5,0x10f,0x9a,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5e6,0x10f,0x9a,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5e7,0x10f,0x9a,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5e8,0x10f,0x9a,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5e9,0x10f,0x9a,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5ea,0x10f,0x9a,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5eb,0x10f,0x9a,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5ec,0x10f,0x9a,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5ed,0x10f,0x9a,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5ee,0x10f,0x9a,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x5ef,0x10f,0x9a,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x5f0,0x10f,0x9a,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x5f1,0x10f,0x9a,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x5f2,0x10f,0x9a,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x5f3,0x10f,0x9a,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x5f4,0x10f,0x9a,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x5f5,0x10f,0x9a,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x5f6,0x129,0x9a,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x5f7,0x129,0x9a,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x5f8,0x129,0x9a,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x5f9,0x129,0x9a,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x5fa,0x129,0x9a,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x5fb,0x129,0x9a,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x5fc,0x129,0x9a,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x5fd,0x129,0x9a,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x5fe,0x129,0x9a,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x5ff,0x129,0x9a,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x600,0x129,0x9a,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x601,0x129,0x9a,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x602,0x129,0x9a,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x603,0x129,0x9a,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x604,0x129,0x9a,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x605,0x129,0x9a,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x606,0x129,0x9a,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x607,0x143,0x9a,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x608,0x143,0x9a,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x609,0x143,0x9a,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x60a,0x143,0x9a,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x60b,0x143,0x9a,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x60c,0x143,0x9a,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x60d,0x143,0x9a,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x60e,0x143,0x9a,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x60f,0x143,0x9a,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x610,0x143,0x9a,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x611,0x143,0x9a,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x612,0x143,0x9a,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x613,0x143,0x9a,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x614,0x143,0x9a,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x615,0x143,0x9a,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x616,0x143,0x9a,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x617,0x143,0x9a,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x618,0x15d,0x9a,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x619,0x15d,0x9a,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x61a,0x15d,0x9a,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x61b,0x15d,0x9a,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x61c,0x15d,0x9a,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x61d,0x15d,0x9a,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x61e,0x15d,0x9a,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x61f,0x15d,0x9a,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x620,0x15d,0x9a,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x621,0x15d,0x9a,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x622,0x15d,0x9a,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x623,0x15d,0x9a,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x624,0x15d,0x9a,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x625,0x15d,0x9a,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x626,0x15d,0x9a,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x627,0x15d,0x9a,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x628,0x15d,0x9a,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x629,0xf5,0xb3,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x62a,0xf5,0xb3,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x62b,0xf5,0xb3,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x62c,0xf5,0xb3,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x62d,0xf5,0xb3,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x62e,0xf5,0xb3,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x62f,0xf5,0xb3,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x630,0xf5,0xb3,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x631,0xf5,0xb3,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x632,0xf5,0xb3,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x633,0xf5,0xb3,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x634,0xf5,0xb3,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x635,0xf5,0xb3,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x636,0xf5,0xb3,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x637,0xf5,0xb3,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x638,0xf5,0xb3,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x639,0xf5,0xb3,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x63a,0x10f,0xb3,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x63b,0x10f,0xb3,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x63c,0x10f,0xb3,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x63d,0x10f,0xb3,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x63e,0x10f,0xb3,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x63f,0x10f,0xb3,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x640,0x10f,0xb3,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x641,0x10f,0xb3,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x642,0x10f,0xb3,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x643,0x10f,0xb3,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x644,0x10f,0xb3,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x645,0x10f,0xb3,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x646,0x10f,0xb3,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x647,0x10f,0xb3,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x648,0x10f,0xb3,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x649,0x10f,0xb3,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x64a,0x10f,0xb3,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x64b,0x129,0xb3,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x64c,0x129,0xb3,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x64d,0x129,0xb3,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x64e,0x129,0xb3,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x64f,0x129,0xb3,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x650,0x129,0xb3,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x651,0x129,0xb3,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x652,0x129,0xb3,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x653,0x129,0xb3,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x654,0x129,0xb3,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x655,0x129,0xb3,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x656,0x129,0xb3,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x657,0x129,0xb3,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x658,0x129,0xb3,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x659,0x129,0xb3,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x65a,0x129,0xb3,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x65b,0x129,0xb3,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x65c,0x143,0xb3,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x65d,0x143,0xb3,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x65e,0x143,0xb3,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x65f,0x143,0xb3,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x660,0x143,0xb3,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x661,0x143,0xb3,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x662,0x143,0xb3,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x663,0x143,0xb3,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x664,0x143,0xb3,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x665,0x143,0xb3,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x666,0x143,0xb3,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x667,0x143,0xb3,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x668,0x143,0xb3,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x669,0x143,0xb3,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x66a,0x143,0xb3,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x66b,0x143,0xb3,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x66c,0x143,0xb3,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x66d,0x15d,0xb3,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x66e,0x15d,0xb3,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x66f,0x15d,0xb3,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x670,0x15d,0xb3,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x671,0x15d,0xb3,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x672,0x15d,0xb3,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x673,0x15d,0xb3,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x674,0x15d,0xb3,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x675,0x15d,0xb3,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x676,0x15d,0xb3,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x677,0x15d,0xb3,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x678,0x15d,0xb3,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x679,0x15d,0xb3,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x67a,0x15d,0xb3,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x67b,0x15d,0xb3,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x67c,0x15d,0xb3,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x67d,0x15d,0xb3,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x67e,0xf5,0xcc,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x67f,0xf5,0xcc,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x680,0xf5,0xcc,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x681,0xf5,0xcc,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x682,0xf5,0xcc,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x683,0xf5,0xcc,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x684,0xf5,0xcc,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x685,0xf5,0xcc,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x686,0xf5,0xcc,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x687,0xf5,0xcc,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x688,0xf5,0xcc,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x689,0xf5,0xcc,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x68a,0xf5,0xcc,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x68b,0xf5,0xcc,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x68c,0xf5,0xcc,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x68d,0xf5,0xcc,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x68e,0xf5,0xcc,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x68f,0x10f,0xcc,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x690,0x10f,0xcc,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x691,0x10f,0xcc,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x692,0x10f,0xcc,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x693,0x10f,0xcc,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x694,0x10f,0xcc,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x695,0x10f,0xcc,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x696,0x10f,0xcc,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x697,0x10f,0xcc,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x698,0x10f,0xcc,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x699,0x10f,0xcc,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x69a,0x10f,0xcc,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x69b,0x10f,0xcc,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x69c,0x10f,0xcc,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x69d,0x10f,0xcc,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x69e,0x10f,0xcc,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x69f,0x10f,0xcc,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6a0,0x129,0xcc,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6a1,0x129,0xcc,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6a2,0x129,0xcc,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6a3,0x129,0xcc,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6a4,0x129,0xcc,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6a5,0x129,0xcc,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6a6,0x129,0xcc,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6a7,0x129,0xcc,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6a8,0x129,0xcc,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6a9,0x129,0xcc,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6aa,0x129,0xcc,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x6ab,0x129,0xcc,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x6ac,0x129,0xcc,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x6ad,0x129,0xcc,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x6ae,0x129,0xcc,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x6af,0x129,0xcc,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x6b0,0x129,0xcc,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6b1,0x143,0xcc,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6b2,0x143,0xcc,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6b3,0x143,0xcc,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6b4,0x143,0xcc,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6b5,0x143,0xcc,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6b6,0x143,0xcc,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6b7,0x143,0xcc,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6b8,0x143,0xcc,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6b9,0x143,0xcc,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6ba,0x143,0xcc,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6bb,0x143,0xcc,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x6bc,0x143,0xcc,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x6bd,0x143,0xcc,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x6be,0x143,0xcc,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x6bf,0x143,0xcc,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x6c0,0x143,0xcc,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x6c1,0x143,0xcc,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6c2,0x15d,0xcc,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6c3,0x15d,0xcc,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6c4,0x15d,0xcc,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6c5,0x15d,0xcc,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6c6,0x15d,0xcc,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6c7,0x15d,0xcc,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6c8,0x15d,0xcc,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6c9,0x15d,0xcc,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6ca,0x15d,0xcc,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6cb,0x15d,0xcc,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6cc,0x15d,0xcc,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x6cd,0x15d,0xcc,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x6ce,0x15d,0xcc,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x6cf,0x15d,0xcc,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x6d0,0x15d,0xcc,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x6d1,0x15d,0xcc,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x6d2,0x15d,0xcc,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6d3,0xf5,0xe5,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6d4,0xf5,0xe5,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6d5,0xf5,0xe5,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6d6,0xf5,0xe5,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6d7,0xf5,0xe5,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6d8,0xf5,0xe5,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6d9,0xf5,0xe5,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6da,0xf5,0xe5,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6db,0xf5,0xe5,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6dc,0xf5,0xe5,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6dd,0xf5,0xe5,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x6de,0xf5,0xe5,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x6df,0xf5,0xe5,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x6e0,0xf5,0xe5,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x6e1,0xf5,0xe5,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x6e2,0xf5,0xe5,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x6e3,0xf5,0xe5,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6e4,0x10f,0xe5,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6e5,0x10f,0xe5,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6e6,0x10f,0xe5,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6e7,0x10f,0xe5,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6e8,0x10f,0xe5,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6e9,0x10f,0xe5,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6ea,0x10f,0xe5,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6eb,0x10f,0xe5,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6ec,0x10f,0xe5,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6ed,0x10f,0xe5,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6ee,0x10f,0xe5,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x6ef,0x10f,0xe5,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x6f0,0x10f,0xe5,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x6f1,0x10f,0xe5,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x6f2,0x10f,0xe5,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x6f3,0x10f,0xe5,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x6f4,0x10f,0xe5,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x6f5,0x129,0xe5,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x6f6,0x129,0xe5,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x6f7,0x129,0xe5,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x6f8,0x129,0xe5,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x6f9,0x129,0xe5,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x6fa,0x129,0xe5,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x6fb,0x129,0xe5,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x6fc,0x129,0xe5,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x6fd,0x129,0xe5,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x6fe,0x129,0xe5,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x6ff,0x129,0xe5,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x700,0x129,0xe5,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x701,0x129,0xe5,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x702,0x129,0xe5,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x703,0x129,0xe5,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x704,0x129,0xe5,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x705,0x129,0xe5,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x706,0x143,0xe5,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x707,0x143,0xe5,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x708,0x143,0xe5,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x709,0x143,0xe5,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x70a,0x143,0xe5,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x70b,0x143,0xe5,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x70c,0x143,0xe5,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x70d,0x143,0xe5,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x70e,0x143,0xe5,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x70f,0x143,0xe5,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x710,0x143,0xe5,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x711,0x143,0xe5,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x712,0x143,0xe5,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x713,0x143,0xe5,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x714,0x143,0xe5,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x715,0x143,0xe5,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x716,0x143,0xe5,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x717,0x15d,0xe5,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x718,0x15d,0xe5,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x719,0x15d,0xe5,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x71a,0x15d,0xe5,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x71b,0x15d,0xe5,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x71c,0x15d,0xe5,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x71d,0x15d,0xe5,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x71e,0x15d,0xe5,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x71f,0x15d,0xe5,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x720,0x15d,0xe5,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x721,0x15d,0xe5,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x722,0x15d,0xe5,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x723,0x15d,0xe5,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x724,0x15d,0xe5,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x725,0x15d,0xe5,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x726,0x15d,0xe5,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x727,0x15d,0xe5,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x728,0xf5,0xfe,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x729,0xf5,0xfe,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x72a,0xf5,0xfe,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x72b,0xf5,0xfe,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x72c,0xf5,0xfe,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x72d,0xf5,0xfe,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x72e,0xf5,0xfe,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x72f,0xf5,0xfe,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x730,0xf5,0xfe,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x731,0xf5,0xfe,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x732,0xf5,0xfe,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x733,0xf5,0xfe,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x734,0xf5,0xfe,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x735,0xf5,0xfe,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x736,0xf5,0xfe,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x737,0xf5,0xfe,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x738,0xf5,0xfe,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x739,0x10f,0xfe,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x73a,0x10f,0xfe,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x73b,0x10f,0xfe,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x73c,0x10f,0xfe,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x73d,0x10f,0xfe,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x73e,0x10f,0xfe,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x73f,0x10f,0xfe,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x740,0x10f,0xfe,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x741,0x10f,0xfe,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x742,0x10f,0xfe,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x743,0x10f,0xfe,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x744,0x10f,0xfe,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x745,0x10f,0xfe,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x746,0x10f,0xfe,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x747,0x10f,0xfe,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x748,0x10f,0xfe,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x749,0x10f,0xfe,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x74a,0x129,0xfe,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x74b,0x129,0xfe,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x74c,0x129,0xfe,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x74d,0x129,0xfe,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x74e,0x129,0xfe,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x74f,0x129,0xfe,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x750,0x129,0xfe,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x751,0x129,0xfe,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x752,0x129,0xfe,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x753,0x129,0xfe,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x754,0x129,0xfe,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x755,0x129,0xfe,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x756,0x129,0xfe,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x757,0x129,0xfe,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x758,0x129,0xfe,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x759,0x129,0xfe,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x75a,0x129,0xfe,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x75b,0x143,0xfe,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x75c,0x143,0xfe,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x75d,0x143,0xfe,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x75e,0x143,0xfe,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x75f,0x143,0xfe,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x760,0x143,0xfe,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x761,0x143,0xfe,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x762,0x143,0xfe,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x763,0x143,0xfe,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x764,0x143,0xfe,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x765,0x143,0xfe,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x766,0x143,0xfe,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x767,0x143,0xfe,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x768,0x143,0xfe,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x769,0x143,0xfe,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x76a,0x143,0xfe,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x76b,0x143,0xfe,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x76c,0x15d,0xfe,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x76d,0x15d,0xfe,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x76e,0x15d,0xfe,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x76f,0x15d,0xfe,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x770,0x15d,0xfe,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x771,0x15d,0xfe,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x772,0x15d,0xfe,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x773,0x15d,0xfe,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x774,0x15d,0xfe,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x775,0x15d,0xfe,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x776,0x15d,0xfe,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x777,0x15d,0xfe,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x778,0x15d,0xfe,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x779,0x15d,0xfe,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x77a,0x15d,0xfe,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x77b,0x15d,0xfe,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x77c,0x15d,0xfe,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x77d,0xf5,0x117,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x77e,0xf5,0x117,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x77f,0xf5,0x117,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x780,0xf5,0x117,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x781,0xf5,0x117,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x782,0xf5,0x117,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x783,0xf5,0x117,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x784,0xf5,0x117,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x785,0xf5,0x117,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x786,0xf5,0x117,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x787,0xf5,0x117,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x788,0xf5,0x117,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x789,0xf5,0x117,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x78a,0xf5,0x117,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x78b,0xf5,0x117,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x78c,0xf5,0x117,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x78d,0xf5,0x117,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x78e,0x10f,0x117,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x78f,0x10f,0x117,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x790,0x10f,0x117,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x791,0x10f,0x117,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x792,0x10f,0x117,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x793,0x10f,0x117,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x794,0x10f,0x117,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x795,0x10f,0x117,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x796,0x10f,0x117,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x797,0x10f,0x117,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x798,0x10f,0x117,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x799,0x10f,0x117,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x79a,0x10f,0x117,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x79b,0x10f,0x117,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x79c,0x10f,0x117,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x79d,0x10f,0x117,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x79e,0x10f,0x117,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x79f,0x129,0x117,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7a0,0x129,0x117,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7a1,0x129,0x117,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7a2,0x129,0x117,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7a3,0x129,0x117,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7a4,0x129,0x117,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7a5,0x129,0x117,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7a6,0x129,0x117,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7a7,0x129,0x117,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7a8,0x129,0x117,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7a9,0x129,0x117,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7aa,0x129,0x117,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x7ab,0x129,0x117,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x7ac,0x129,0x117,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x7ad,0x129,0x117,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x7ae,0x129,0x117,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x7af,0x129,0x117,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x7b0,0x143,0x117,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7b1,0x143,0x117,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7b2,0x143,0x117,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7b3,0x143,0x117,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7b4,0x143,0x117,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7b5,0x143,0x117,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7b6,0x143,0x117,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7b7,0x143,0x117,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7b8,0x143,0x117,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7b9,0x143,0x117,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7ba,0x143,0x117,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7bb,0x143,0x117,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x7bc,0x143,0x117,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x7bd,0x143,0x117,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x7be,0x143,0x117,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x7bf,0x143,0x117,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x7c0,0x143,0x117,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x7c1,0x15d,0x117,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7c2,0x15d,0x117,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7c3,0x15d,0x117,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7c4,0x15d,0x117,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7c5,0x15d,0x117,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7c6,0x15d,0x117,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7c7,0x15d,0x117,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7c8,0x15d,0x117,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7c9,0x15d,0x117,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7ca,0x15d,0x117,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7cb,0x15d,0x117,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7cc,0x15d,0x117,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x7cd,0x15d,0x117,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x7ce,0x15d,0x117,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,1999,0x15d,0x117,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,2000,0x15d,0x117,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x7d1,0x15d,0x117,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x7d2,0xf5,0x130,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7d3,0xf5,0x130,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7d4,0xf5,0x130,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7d5,0xf5,0x130,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7d6,0xf5,0x130,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7d7,0xf5,0x130,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7d8,0xf5,0x130,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7d9,0xf5,0x130,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7da,0xf5,0x130,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7db,0xf5,0x130,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7dc,0xf5,0x130,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7dd,0xf5,0x130,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x7de,0xf5,0x130,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x7df,0xf5,0x130,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x7e0,0xf5,0x130,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x7e1,0xf5,0x130,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x7e2,0xf5,0x130,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x7e3,0x10f,0x130,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7e4,0x10f,0x130,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7e5,0x10f,0x130,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7e6,0x10f,0x130,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7e7,0x10f,0x130,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7e8,0x10f,0x130,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7e9,0x10f,0x130,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7ea,0x10f,0x130,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7eb,0x10f,0x130,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7ec,0x10f,0x130,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7ed,0x10f,0x130,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7ee,0x10f,0x130,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x7ef,0x10f,0x130,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x7f0,0x10f,0x130,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x7f1,0x10f,0x130,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x7f2,0x10f,0x130,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x7f3,0x10f,0x130,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x7f4,0x129,0x130,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x7f5,0x129,0x130,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x7f6,0x129,0x130,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x7f7,0x129,0x130,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x7f8,0x129,0x130,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x7f9,0x129,0x130,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x7fa,0x129,0x130,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x7fb,0x129,0x130,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x7fc,0x129,0x130,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x7fd,0x129,0x130,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x7fe,0x129,0x130,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x7ff,0x129,0x130,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x800,0x129,0x130,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x801,0x129,0x130,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x802,0x129,0x130,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x803,0x129,0x130,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x804,0x129,0x130,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x805,0x143,0x130,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x806,0x143,0x130,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x807,0x143,0x130,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x808,0x143,0x130,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x809,0x143,0x130,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x80a,0x143,0x130,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x80b,0x143,0x130,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x80c,0x143,0x130,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x80d,0x143,0x130,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x80e,0x143,0x130,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x80f,0x143,0x130,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x810,0x143,0x130,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x811,0x143,0x130,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x812,0x143,0x130,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x813,0x143,0x130,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x814,0x143,0x130,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x815,0x143,0x130,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x816,0x15d,0x130,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x817,0x15d,0x130,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x818,0x15d,0x130,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x819,0x15d,0x130,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x81a,0x15d,0x130,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x81b,0x15d,0x130,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x81c,0x15d,0x130,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x81d,0x15d,0x130,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x81e,0x15d,0x130,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x81f,0x15d,0x130,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x820,0x15d,0x130,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x821,0x15d,0x130,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x822,0x15d,0x130,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x823,0x15d,0x130,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x824,0x15d,0x130,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x825,0x15d,0x130,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x826,0x15d,0x130,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x827,0xbc,0x56,s_VERDANA8_fnt_00563e98,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x827,0);
    Window_GadgetNotify_Text_SetLayout(self,0x827,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x828,0xbc,0x6f,s_VERDANA8_fnt_00563e98,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x828,0);
    Window_GadgetNotify_Text_SetLayout(self,0x828,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x829,0xbc,0xa2,s_VERDANA8_fnt_00563e98,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x829,0);
    Window_GadgetNotify_Text_SetLayout(self,0x829,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x82a,0xbc,0x88,s_VERDANA8_fnt_00563e98,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x82a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x82a,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x82b,0xbc,0xba,s_VERDANA8_fnt_00563e98,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x82b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x82b,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x82c,0xbc,0xd3,s_VERDANA8_fnt_00563e98,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x82c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x82c,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x82d,0xbc,0x105,s_VERDANA8_fnt_00563e98,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x82d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x82d,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x82e,0xbc,0xec,s_VERDANA8_fnt_00563e98,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x82e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x82e,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x830,0xbc,0x11e,s_VERDANA8_fnt_00563e98,DAT_005829dc);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x830,0);
    Window_GadgetNotify_Text_SetLayout(self,0x830,1,0x37,0xffff,0);
  }
  value1 = UI_AddText(self,0x831,0x29,0x15e,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x831,0);
    Window_GadgetNotify_Text_SetLayout(self,0x831,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x833,0x29,0x171,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x833,0);
    Window_GadgetNotify_Text_SetLayout(self,0x833,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x834,0x29,0x197,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x834,0);
    Window_GadgetNotify_Text_SetLayout(self,0x834,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x835,0x29,0x184,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x835,0);
    Window_GadgetNotify_Text_SetLayout(self,0x835,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x836,0x29,0x1e4,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x836,0);
    Window_GadgetNotify_Text_SetLayout(self,0x836,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x837,0x29,0x1d1,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x837,0);
    Window_GadgetNotify_Text_SetLayout(self,0x837,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x838,0x29,0x1be,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x838,0);
    Window_GadgetNotify_Text_SetLayout(self,0x838,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x839,0x29,0x1ab,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x839,0);
    Window_GadgetNotify_Text_SetLayout(self,0x839,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x83a,0x29,0x1f6,s_VERDANA7_fnt_00563ec8,s__Kurvenbeschriftung_00565a98);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83a,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x83b,0x1d,0xa2,s_VERDANA8_fnt_00563e98,DAT_00581910);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83b,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x83c,0x1d,0xc6,s_VERDANA8_fnt_00563e98,DAT_0058294c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83c,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x83d,0x1d,0x106,s_VERDANA8_fnt_00563e98,DAT_00582ca0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83d,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x83e,0x1d,0xe6,s_VERDANA8_fnt_00563e98,DAT_00582c0c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83e,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x83f,0x1d,0x126,s_VERDANA8_fnt_00563e98,DAT_00582af0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x83f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x83f,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x840,0xb1,0x150,s_VERDANA7_fnt_00563ec8,s__Beschriftung_00565a88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x840,0);
    Window_GadgetNotify_Text_SetLayout(self,0x840,0,0x73,0xffff,0);
  }
  value1 = UI_AddText(self,0x841,0x1d0,0x209,s_VERDANA7_fnt_00563ec8,s__Beschriftung_00565a88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x841,0);
    Window_GadgetNotify_Text_SetLayout(self,0x841,0,0x50,0xffff,0);
  }
  value1 = UI_AddText(self,0x842,0x17c,0x56,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x842,0);
    Window_GadgetNotify_Text_SetLayout(self,0x842,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x843,0x1a6,0x56,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x843,0);
    Window_GadgetNotify_Text_SetLayout(self,0x843,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x845,0x1d1,0x56,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x845,0);
    Window_GadgetNotify_Text_SetLayout(self,0x845,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x846,0x17c,0x6f,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x846,0);
    Window_GadgetNotify_Text_SetLayout(self,0x846,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x847,0x1a6,0x6f,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x847,0);
    Window_GadgetNotify_Text_SetLayout(self,0x847,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x848,0x1d1,0x6f,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x848,0);
    Window_GadgetNotify_Text_SetLayout(self,0x848,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x849,0x17c,0x88,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x849,0);
    Window_GadgetNotify_Text_SetLayout(self,0x849,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x84a,0x1a6,0x88,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84a,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x84b,0x1d1,0x88,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84b,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x84c,0x17c,0xa2,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84c,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x84d,0x1a6,0xa2,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84d,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x84e,0x1d1,0xa2,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84e,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x84f,0x17c,0xba,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x84f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x84f,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x850,0x1a6,0xba,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x850,0);
    Window_GadgetNotify_Text_SetLayout(self,0x850,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x851,0x1d1,0xba,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x851,0);
    Window_GadgetNotify_Text_SetLayout(self,0x851,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x852,0x17c,0xd3,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x852,0);
    Window_GadgetNotify_Text_SetLayout(self,0x852,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x853,0x1a6,0xd3,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x853,0);
    Window_GadgetNotify_Text_SetLayout(self,0x853,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x854,0x1d1,0xd3,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x854,0);
    Window_GadgetNotify_Text_SetLayout(self,0x854,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x855,0x17c,0xec,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x855,0);
    Window_GadgetNotify_Text_SetLayout(self,0x855,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x856,0x1a6,0xec,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x856,0);
    Window_GadgetNotify_Text_SetLayout(self,0x856,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x857,0x1d1,0xec,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x857,0);
    Window_GadgetNotify_Text_SetLayout(self,0x857,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x858,0x17c,0x105,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x858,0);
    Window_GadgetNotify_Text_SetLayout(self,0x858,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x859,0x1a6,0x105,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x859,0);
    Window_GadgetNotify_Text_SetLayout(self,0x859,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x85a,0x1d1,0x105,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85a,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x85b,0x17c,0x11e,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85b,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x85c,0x1a6,0x11e,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85c,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x85d,0x1d1,0x11e,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85d,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x85e,0x17c,0x137,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85e,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85e,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x85f,0x1a6,0x137,s_VERDANA8_fnt_00563e98,&DAT_00565a84);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x85f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x85f,1,0x1e,0xffff,0);
  }
  value1 = UI_AddText(self,0x860,0x1d1,0x137,s_VERDANA8_fnt_00563e98,s___1_000_000__005658a0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x860,0);
    Window_GadgetNotify_Text_SetLayout(self,0x860,1,0x5a,0xffff,0);
  }
  value1 = UI_AddText(self,0x861,0x1f,0x7c,s_VEDANA11_fnt_00564090,s__Romana_00565a7c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x861,0);
    Window_GadgetNotify_Text_SetLayout(self,0x861,2,0x91,0xffff,0);
  }
  value1 = UI_AddText(self,0x862,0x102,0x153,s_VEDANA11_fnt_00564090,DAT_005828b8);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x862,0);
    Window_GadgetNotify_Text_SetLayout(self,0x862,0,0x104,0xffff,0);
  }
  UI_AddSprite(self,0x863,0xfd,0x3c,s_SYMB_SK00_spr_00565a6c);
  UI_AddSprite(self,0x864,0x117,0x3a,s_SYMB_SK01_spr_00565a5c);
  UI_AddSprite(self,0x865,0x130,0x3b,s_SYMB_SK02_spr_00565a4c);
  UI_AddSprite(self,0x866,0x14a,0x3f,s_SYMB_SK03_spr_00565a3c);
  UI_AddSprite(self,0x867,0x163,0x3e,s_SYMB_SK04_spr_00565a2c);
  UI_AddSprite(self,0x868,0x181,0x3e,s_SYMB_SK05_spr_00565a1c);
  UI_AddSprite(self,0x869,0x1a5,0x3b,s_SYMB_SK06_spr_00565a0c);
  UI_AddSprite(self,0x86a,0x1f5,0x3b,s_SYMB_SK07_spr_005659fc);
  UI_AddImage(self,0x4b2,0x301,0x1b4,s_PB33_00_spr_00564ba0,0,0);
  value1 = UI_AddText(self,0x88a,0x288,0x212,s_VERDANA7_fnt_00563ec8,DAT_00581538);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x88a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x88a,2,0x69,0xffff,0);
  }
  UI_AddSprite(self,0x88b,0xd2,0x134,s_DUECHSCHNITT_spr_005659e8);
  UI_AddImage(self,0x8ac,0x268,0x227,s_SKFILIALPERSONAL_00_spr_00565b18,1,0);
  UI_AddImage(self,0x8ad,0x2aa,0x227,s_SKFILIALMONEY_00_spr_00565b00,1,0);
  UI_AddSprite(self,0x8ae,0x9e,0x15c,s_TABELLENCOLOURS_00_spr_005659d0);
  UI_AddSprite(self,0x8af,0x9e,0x16f,s_TABELLENCOLOURS_01_spr_005659b8);
  UI_AddSprite(self,0x8b0,0x9e,0x182,s_TABELLENCOLOURS_02_spr_005659a0);
  UI_AddSprite(self,0x8b1,0x9e,0x195,s_TABELLENCOLOURS_03_spr_00565988);
  UI_AddSprite(self,0x8b2,0x9e,0x1bb,s_TABELLENCOLOURS_04_spr_00565970);
  UI_AddSprite(self,0x8b3,0x9e,0x1a8,s_TABELLENCOLOURS_05_spr_00565958);
  UI_AddSprite(self,0x8b4,0x9e,0x1ce,s_TABELLENCOLOURS_06_spr_00565940);
  UI_AddSprite(self,0x8b5,0x9e,0x1e1,s_TABELLENCOLOURS_07_spr_00565928);
  UI_AddSprite(self,0x8b6,0x9e,500,s_TABELLENCOLOURS_08_spr_00565910);
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x3f,0x36,s_MG_H_LEERPIZZ_B_spr_005658fc);
  return self;
}
