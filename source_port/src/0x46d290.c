// MissionHintWindow_Create: ported from Pizza Connection 2 at 0x46d290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x46d290
#include "pc2_port.h"


void * __cdecl MissionHintWindow_Create(int *arg1)

{
  int value1;
  void *self;
  
                    /* Creates the mission hint window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0,0,s_RQ_MISSION_spr_00566eb4,&LAB_004c6ab0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_AddTextButton(self,0x433,0x1ec,0x8d,s_VERDANA8_fnt_00563e98,s__Gehe_zu_00566ea8,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (value1 != 0) {
    Gadget_SetButtonColors(self,0x433,0,0,0);
    Gadget_SetButtonTextLayout(self,0x433,2,0x54,0,0,0xfffe);
  }
  value1 = UI_AddText(self,0x439,0x3e,0x25,s_VERDANA8_fnt_00563e98,s__Dummy_00566ea0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x439,0);
    Window_GadgetNotify_Text_SetLayout(self,0x439,0,0x203,0x79,0);
  }
  value1 = UI_AddText(self,0x43a,0x3d,0xe,s_VEDANA12_fnt_00566d60,s__Eine_Filiale_mieten_00566e88);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x43a,0);
    Window_GadgetNotify_Text_SetLayout(self,0x43a,0,500,0xffff,0);
  }
  UI_AddSprite(self,0x458,0x16,0x38,s_NEWSCHUTZ_spr_00564f6c);
  UI_AddSprite(self,0x461,0x16,0x5a,s_NEWSCHUTZ_spr_00564f6c);
  UI_AddSprite(self,0x468,0x16,0x7c,s_NEWSCHUTZ_spr_00564f6c);
  UI_AddSprite(self,0x46a,0x10,0xb,s_RB02X_FILIALE_spr_00566e74);
  return self;
}
