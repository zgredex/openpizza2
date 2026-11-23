// StatisticsView_CreateWindow: ported from Pizza Connection 2 at 0x443520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x443520
#include "pc2_port.h"


void * __cdecl StatisticsView_CreateWindow(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the statistics-view city background window. */
  value1 = Window_CreatePictureWindow(DAT_0057c5e0,s_BG003_tga_00566280,&LAB_004b5410);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(self,0x1f4c,0x216,-2,s_MAUERBOGEN_spr_00564830);
  UI_AddImage(self,0x3f5,0x264,3,s_PB22_00_spr_00564174,0,0);
  UI_AddImage(self,0x3f6,0x2f7,3,s_PB24_00_spr_00564144,0,0);
  UI_AddSprite(self,0x3ff,600,0xb2,s_HPB__00_spr_00564824);
  UI_AddSprite(self,0x400,0x280,0xb2,s_HPB__01_spr_00564818);
  UI_AddSprite(self,0x401,0x2a8,0xb2,s_HPB__02_spr_0056480c);
  UI_AddSprite(self,0x402,0x2d0,0xb2,s_HPB__03_spr_00564800);
  UI_AddSprite(self,0x403,0x2f8,0xb2,s_HPB__04_spr_005647f4);
  UI_AddImage(self,0x3fa,599,0xb1,s_RB01_00_spr_005647e8,1,0);
  UI_AddImage(self,0x3fb,0x27f,0xb1,s_RB02_00_spr_005647dc,1,0);
  UI_AddImage(self,0x3fc,0x2a7,0xb1,s_RB03_00_spr_005647d0,1,0);
  UI_AddImage(self,0x3fd,0x2cf,0xb1,s_RB04_00_spr_005647c4,1,0);
  UI_AddImage(self,0x3fe,0x2f7,0xb1,s_RB05_00_spr_005647b8,1,0);
  UI_AddImage(self,0x40c,0x27f,6,s_CITYBUT01_00_spr_005647a4,0,0);
  UI_CreateBitmapGadget(self,0x430,0xec,0x232,0x2c,0x1d,0x10);
  value1 = UI_AddText(self,0x40f,0x280,4,s_TIMESFONT_fnt_00563ea8,s_Paris_0056479c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,2,0x78,0,0);
  }
  value1 = UI_AddText(self,0x410,10,0x238,s_TIMES14_fnt_00564788,s_17_32_00564794);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0);
    Window_GadgetNotify_Text_SetLayout(self,0x410,2,0x32,0,0);
  }
  UI_CreateAnimationWindow(self,0x412,0x2fb,0x7c,s_KAKANIM_ani_0056472c);
  UI_CreateAnimationWindow(self,0x415,0x268,3,s_SPIDERANIM_ani_00564778);
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x1f45,0xca,0x240,s_VERDANA10_fnt_00563e64,&DAT_00564774);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f45,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f45,2,0,0xffff,0);
  }
  UI_CreateBitmapGadget(self,0x1f42,0x58,0x240,0x6c,0x10,0x10);
  value1 = UI_AddText(self,0x1f41,0x68,0x230,s_VERDANA8_fnt_00563e98,s__32_11_2003_00564768);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,2,0x5b,0xffff,0);
  }
  UI_CreateAnimationWindow(self,0x411,0x1b,0x227,s_KAKANIM2_ani_00564758);
  UI_AddSprite(self,0x1f44,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(self,0x1f46,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(self,0x1f47,0x2ff,0x35,s_STAR_01_spr_00564738);
  UI_AddSprite(self,0x1f48,0x2ff,0x49,s_STAR_01_spr_00564738);
  UI_AddSprite(self,0x1f49,0x2ff,0x5d,s_STAR_01_spr_00564738);
  UI_AddSprite(self,0x1f4a,0x2ff,0x71,s_STAR_01_spr_00564738);
  UI_AddSprite(self,0x1f4b,0x2ff,0x85,s_STAR_01_spr_00564738);
  UI_CreateAnimationWindow(self,0x414,0x2f4,0xbe,s_KAKANIM1_ani_0056471c);
  UI_CreateAnimationWindow(self,0x413,0x2fb,0x1b,s_TOMATENANIM_ani_0056470c);
  return self;
}
