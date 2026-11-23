// OfficeView_CreateWindow: ported from Pizza Connection 2 at 0x4275a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4275a0
#include "pc2_port.h"


void * __cdecl OfficeView_CreateWindow(int *arg1)

{
  int value1;
  void *self;
  char local_40 [64];
  
                    /* Creates the player-office city view window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_BG001_spr_00564840,&LAB_004a2670);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  String_Format(local_40,(uint8_t *)s_OP_BACK__s_spr_00564de8,value1 + 0x44);
  UI_AddSprite(self,0x1f4c,0,0,local_40);
  UI_AddSprite(self,0x1f4a,0x216,-2,s_MAUERBOGEN_spr_00564830);
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
  value1 = UI_AddText(self,0x40f,0x25c,3,s_TIMESFONT_fnt_00563ea8,s_Paris_0056479c);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x40f,0);
    Window_GadgetNotify_Text_SetLayout(self,0x40f,2,0xb4,0,0);
  }
  value1 = UI_AddText(self,0x410,10,0x238,s_TIMES14_fnt_00564788,s_17_32_00564794);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x410,0);
    Window_GadgetNotify_Text_SetLayout(self,0x410,2,0x32,0,0);
  }
  UI_CreateAnimationWindow(self,0x415,0x268,3,s_SPIDERANIM_ani_00564778);
  UI_AddImage(self,8000,0x23c,0xd9,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  value1 = UI_AddText(self,0x42b,0xca,0x240,s_VERDANA10_fnt_00563e64,&DAT_00564774);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(self,0x42b,2,0,0xffff,0);
  }
  UI_CreateBitmapGadget(self,0x430,0x58,0x240,0x6c,0x10,0x10);
  value1 = UI_AddText(self,0x1f41,0x68,0x230,s_VERDANA8_fnt_00563e98,s__32_11_2003_00564768);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(self,0x1f41,2,0x5b,0xffff,0);
  }
  UI_CreateAnimationWindow(self,0x411,0x1b,0x227,s_KAKANIM2_ani_00564758);
  UI_AddSprite(self,0x1f48,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  UI_AddSprite(self,0x1f49,0xec,0x232,s_PLAYLOG_8_01_02_spr_00564744);
  UI_CreateAnimationWindow(self,0x412,0x2fb,0x7c,s_KAKANIM_ani_0056472c);
  return self;
}
