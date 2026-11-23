// HighScore_BuildCityListWindow: ported from Pizza Connection 2 at 0x476100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x476100
#include "pc2_port.h"


void * __cdecl HighScore_BuildCityListWindow(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Builds the high-score city list window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_PE_SUB_FREIES_SPIEL_spr_005674f0,&LAB_004ce810);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,2000,0x262,0x52,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d1,0x262,0x67,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d2,0x262,0x7c,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d3,0x262,0x91,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d4,0x262,0xa6,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d5,0x262,0xbb,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d6,0x262,0xd0,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d7,0x262,0xe5,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0x441,0x261,0x30,s_TIMES14_fnt_00564788,&DAT_00567544);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x441,0);
    Window_GadgetNotify_Text_SetLayout(self,0x441,0,0xb4,0,0);
  }
  UI_AddImage(self,0x7d8,0x262,0xfa,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7d9,0x262,0x10f,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7da,0x262,0x124,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7db,0x262,0x139,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7dc,0x262,0x14e,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7dd,0x262,0x163,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7de,0x262,0x178,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,3000,0x267,0x57,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,3000,0);
    Window_GadgetNotify_Text_SetLayout(self,3000,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbb9,0x267,0x6b,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbb9,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbb9,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbba,0x267,0x80,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbba,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbba,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbbb,0x267,0x95,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbbb,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbbb,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbbc,0x267,0xaa,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbbc,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbbc,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbbd,0x267,0xbf,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbbd,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbbd,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbbe,0x267,0xd4,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbbe,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbbe,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbbf,0x267,0xe9,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbbf,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbbf,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc0,0x267,0xfe,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc0,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc0,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc1,0x267,0x113,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc1,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc1,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc2,0x267,0x128,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc2,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc2,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc3,0x267,0x13d,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc3,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc3,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc4,0x267,0x152,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc4,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc4,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc5,0x267,0x167,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc5,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc5,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc6,0x267,0x17c,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc6,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc6,0,0x96,0,0);
  }
  value1 = UI_CreateSlider(self,0x462,0x30c,0x58,0x18a,s_SL01_00_spr_0056448c,0,1);
  if (value1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x462,&local_10);
  }
  UI_AddImage(self,0x7df,0x262,0x18d,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7e0,0x262,0x1a2,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7e1,0x262,0x1b7,s_TABPB01__00_spr_00564670,1,0);
  UI_AddImage(self,0x7e2,0x262,0x1cc,s_TABPB01__00_spr_00564670,1,0);
  value1 = UI_AddText(self,0xbc7,0x267,0x191,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc7,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc7,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc8,0x267,0x1a6,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc8,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc8,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbc9,0x267,0x1bb,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbc9,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbc9,0,0x96,0,0);
  }
  value1 = UI_AddText(self,0xbca,0x267,0x1d0,s_VERDANA8_fnt_00563e98,s__Blablablablabla_00564d60);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0xbca,0);
    Window_GadgetNotify_Text_SetLayout(self,0xbca,0,0x96,0,0);
  }
  return self;
}
