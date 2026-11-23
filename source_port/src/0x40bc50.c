// SubMenu_BuildBranchExpansion: ported from Pizza Connection 2 at 0x40bc50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40bc50
#include "pc2_port.h"


void * __cdecl SubMenu_BuildBranchExpansion(int *arg1)

{
  int value1;
  void *self;
  
                    /* Builds the branch-expansion page. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0048f8b0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x45b,99,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x45c,99,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x45d,99,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x45e,99,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x45f,99,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x460,99,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x461,99,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x462,99,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x463,99,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x464,99,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x465,99,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x466,99,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x467,99,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x468,99,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x469,99,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x46a,99,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x46b,99,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x46c,0x95,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x46d,0x95,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x46e,0x95,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x46f,0x95,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x470,0x95,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x471,0x95,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x472,0x95,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x473,0x95,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x474,0x95,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x475,0x95,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x476,0x95,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x477,0x95,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x478,0x95,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x479,0x95,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x47a,0x95,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x47b,0x95,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x47c,0x95,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x47d,199,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x47e,199,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x47f,199,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x480,199,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x481,199,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x482,199,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x483,199,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x484,199,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x485,199,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x486,199,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x487,199,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x488,199,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x489,199,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x48a,199,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x48b,199,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x48c,199,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x48d,199,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x48e,0x31,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x48f,0x31,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x490,0x31,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x491,0x31,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x492,0x31,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x493,0x31,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x494,0x31,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x495,0x31,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x496,0x31,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x497,0x31,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x498,0x31,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x499,0x31,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x49a,0x31,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x49b,0x31,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x49c,0x31,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x49d,0x31,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x49e,0x31,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x49f,99,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4a0,99,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4a1,99,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4a2,99,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4a3,99,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4a4,99,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4a5,99,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4a6,99,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4a7,99,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4a8,99,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4a9,99,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4aa,99,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4ab,99,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4ac,99,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4ad,99,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4ae,99,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4af,99,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4b0,0x95,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4b1,0x95,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4b2,0x95,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4b3,0x95,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4b4,0x95,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4b5,0x95,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4b6,0x95,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4b7,0x95,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4b8,0x95,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4b9,0x95,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4ba,0x95,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4bb,0x95,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4bc,0x95,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4bd,0x95,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4be,0x95,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4bf,0x95,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4c0,0x95,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4c1,199,0x15e,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4c2,199,0x15e,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4c3,199,0x15e,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4c4,199,0x15e,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4c5,199,0x15e,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4c6,199,0x15e,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4c7,199,0x15e,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4c8,199,0x15e,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4c9,199,0x15e,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4ca,199,0x15e,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4cb,199,0x15e,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4cc,199,0x15e,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4cd,199,0x15e,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4ce,199,0x15e,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4cf,199,0x15e,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4d0,199,0x15e,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4d1,199,0x15e,s_BEWERTUNG__16_spr_00563ed8);
  UI_AddSprite(self,0x4d2,0x31,0x13b,s_BEWERTUNG__00_spr_00564018);
  UI_AddSprite(self,0x4d3,0x31,0x13b,s_BEWERTUNG__01_spr_00564004);
  UI_AddSprite(self,0x4d4,0x31,0x13b,s_BEWERTUNG__02_spr_00563ff0);
  UI_AddSprite(self,0x4d5,0x31,0x13b,s_BEWERTUNG__03_spr_00563fdc);
  UI_AddSprite(self,0x4d6,0x31,0x13b,s_BEWERTUNG__04_spr_00563fc8);
  UI_AddSprite(self,0x4d7,0x31,0x13b,s_BEWERTUNG__05_spr_00563fb4);
  UI_AddSprite(self,0x4d8,0x31,0x13b,s_BEWERTUNG__06_spr_00563fa0);
  UI_AddSprite(self,0x4d9,0x31,0x13b,s_BEWERTUNG__07_spr_00563f8c);
  UI_AddSprite(self,0x4da,0x31,0x13b,s_BEWERTUNG__08_spr_00563f78);
  UI_AddSprite(self,0x4db,0x31,0x13b,s_BEWERTUNG__09_spr_00563f64);
  UI_AddSprite(self,0x4dc,0x31,0x13b,s_BEWERTUNG__10_spr_00563f50);
  UI_AddSprite(self,0x4dd,0x31,0x13b,s_BEWERTUNG__11_spr_00563f3c);
  UI_AddSprite(self,0x4de,0x31,0x13b,s_BEWERTUNG__12_spr_00563f28);
  UI_AddSprite(self,0x4df,0x31,0x13b,s_BEWERTUNG__13_spr_00563f14);
  UI_AddSprite(self,0x4e0,0x31,0x13b,s_BEWERTUNG__14_spr_00563f00);
  UI_AddSprite(self,0x4e1,0x31,0x13b,s_BEWERTUNG__15_spr_00563eec);
  UI_AddSprite(self,0x4e2,0x31,0x13b,s_BEWERTUNG__16_spr_00563ed8);
  value1 = UI_AddText(self,0x4e3,0x27,0x130,s_VERDANA7_fnt_00563ec8,DAT_00580bec);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e3,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e3,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e4,0x58,0x130,s_VERDANA7_fnt_00563ec8,DAT_005816d4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e4,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e4,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e5,0x8a,0x130,s_VERDANA7_fnt_00563ec8,DAT_00582974);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e5,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e5,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e6,0xbc,0x130,s_VERDANA7_fnt_00563ec8,DAT_0058234c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e6,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e6,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e7,0x27,0x154,s_VERDANA7_fnt_00563ec8,DAT_00580e64);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e7,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e7,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e8,0x58,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582e08);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e8,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e8,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4e9,0x89,0x154,s_VERDANA7_fnt_00563ec8,DAT_00582770);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4e9,2,0x32,0,0);
  }
  value1 = UI_AddText(self,0x4ea,0xba,0x154,s_VERDANA7_fnt_00563ec8,DAT_005810a4);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ea,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ea,2,0x32,0,0);
  }
  UI_AddSprite(self,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(self,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  value1 = UI_AddText(self,0x441,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005829d0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,2,0xbe,0,0);
  }
  value1 = UI_AddText(self,0x44d,0x2f,0x117,s_VERDANA8_fnt_00563e98,DAT_0058176c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x44d,0);
    Window_GadgetNotify_Text_SetLayout(self,0x44d,0,0x2d,0,0);
  }
  value1 = UI_AddTextButton(self,0x44f,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582d84,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x44f,0,0,0);
    Gadget_SetButtonTextLayout(self,0x44f,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x4eb,0x57,0x117,s_VERDANA8_fnt_00563e98,s__3Tage_00563e7c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4eb,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4eb,1,0x37,0,0);
  }
  value1 = UI_AddText(self,0x4ed,0x2f,0x102,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ed,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ed,0,0x3c,0,0);
  }
  value1 = UI_AddText(self,0x4ee,0x66,0x102,s_VERDANA8_fnt_00563e98,s__3422__00563e74);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ee,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ee,1,0x50,0,0);
  }
  value1 = UI_AddText(self,0x4ef,0x31,0x86,s_VERDANA10_fnt_00563e64,DAT_0058145c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4ef,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4ef,0,0x50,0,0);
  }
  value1 = UI_AddText(self,0x4f0,0x31,0x98,s_VERDANA8_fnt_00563e98,DAT_00582e30);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x4f0,0);
    Window_GadgetNotify_Text_SetLayout(self,0x4f0,0,0xb9,0x5a,0);
  }
  UI_AddImage(self,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(self,0x1f43,0x5e,0x2f,s_MG_H_PIZZ_B7_spr_00563e38);
  return self;
}
