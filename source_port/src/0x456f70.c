// SubMenu_BuildSchool: ported from Pizza Connection 2 at 0x456f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x456f70
#include "pc2_port.h"


void * __cdecl SubMenu_BuildSchool(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the school page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004bf6a0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x429,0x37,0x86,s_RAHMEN01_spr_00566790);
  UI_AddSprite(self,0x42a,0x3b,0xad,s_RAHMEN02_spr_00566780);
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x43b,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582938);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43b,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x43c,0x38,0x79,s_VERDANA8_fnt_00563e98,DAT_00581094);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43c,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43c,0,100,0,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f41,0x27,0x10b,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x1f42,0x30,0x111,s_VERDANA7_fnt_00563ec8,DAT_005819f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f42,0,0x5a,0x1e,0);
  }
  value1 = UI_AddTextButton(self,0x1f43,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582c90,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x1f43,0,0,0);
    Gadget_SetButtonTextLayout(self,0x1f43,2,0x54,0,0,0xfffe);
  }
  UI_CreateBitmapGadget(self,0x1f45,0x40,0xb8,0x93,0x50,0x10);
  UI_AddSprite(self,0x1f4c,0x5c,0x30,s_MG_H_SCHULE_spr_00566770);
  UI_AddSprite(self,0x1f4d,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1f4e,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1f4f,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1f50,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1f51,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1f52,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1f53,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1f54,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1f55,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1f56,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1f57,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1f58,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1f59,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1f5a,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1f5b,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1f5c,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1f5d,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1f5e,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1f5f,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1f60,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1f61,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1f62,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1f63,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1f64,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1f65,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1f66,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1f67,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1f68,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1f69,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1f6a,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1f6b,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1f6c,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1f6d,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1f6e,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1f6f,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1f70,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1f71,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1f72,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1f73,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1f74,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1f75,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1f76,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1f77,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1f78,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1f79,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1f7a,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1f7b,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1f7c,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1f7d,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1f7e,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1f7f,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1f80,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1f81,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1f82,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1f83,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1f84,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1f85,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1f86,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1f87,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1f88,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1f89,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1f8a,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1f8b,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1f8c,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1f8d,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1f8e,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1f8f,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1f90,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1f91,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1f92,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1f93,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1f94,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1f95,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1f96,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1f97,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1f98,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1f99,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1f9a,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1f9b,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1f9c,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1f9d,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1f9e,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1f9f,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1fa0,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1fa1,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1fa2,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1fa3,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1fa4,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1fa5,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1fa6,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1fa7,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1fa8,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1fa9,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1faa,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1fab,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1fac,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1fad,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1fae,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1faf,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1fb0,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1fb1,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1fb2,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1fb3,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1fb4,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1fb5,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1fb6,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1fb7,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1fb8,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1fb9,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1fba,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1fbb,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1fbc,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1fbd,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1fbe,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1fbf,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1fc0,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1fc1,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1fc2,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1fc3,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x1fc4,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x1fc5,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x1fc6,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x1fc7,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x1fc8,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x1fc9,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x1fca,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x1fcb,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x1fcc,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x1fcd,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x1fce,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x1fcf,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x1fd0,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x1fd1,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x1fd2,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x1fd3,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x1fd4,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x1fd5,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd5,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fd6,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fd7,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd7,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fd8,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd8,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fd9,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fd9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fd9,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fda,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fda,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fda,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fdb,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fdb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fdb,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x1fdc,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1fdc,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1fdc,2,0x32,0,0);
  }
  return self;
}
