// CompetitorWindow_InitStatsPanel: ported from Pizza Connection 2 at 0x4a3230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a3230
#include "pc2_port.h"

void __cdecl CompetitorWindow_InitStatsPanel(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  char cVar2;
  int value3;
  uint32_t uvalue4;
  int value5;
  uint32_t unaff_EDI;
  uint32_t *uptr6;
  int *ptr7;
  char *cptr8;
  
                    /* Shows the selected competitor item's name and statistics. */
  cVar2 = 0 < DAT_0057d014;
  uptr6 = &DAT_0057d220;
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  String_Format(&DAT_0057d020,&DAT_00579aec,unaff_EDI);
  uvalue1 = (uint32_t)(uint8_t)cVar2;
  UI_SetChildVisibleByID(arg1,0x1f9e,uvalue1);
  UI_SetChildVisibleByID(arg1,0x1f5d,uvalue1);
  UI_SetChildVisibleByID(arg1,0x1f9d,uvalue1);
  if (0 < DAT_0057d014) {
    cptr8 = &DAT_0057d020;
    ptr7 = &DAT_0057d220;
    self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    value5 = DAT_00568ef0;
    value3 = Game_GetPlayerBySlot(DAT_0057c670,DAT_00568ef4);
    uvalue4 = Game_BuildStatusTextByIndex(self,value3,value5,ptr7,cptr8);
    cVar2 = (char)uvalue4;
  }
  if (cVar2 == '\0') {
    Gadget_SetTextf(arg1,0x1f5a,&DAT_00568f00,unaff_EDI);
  }
  else {
    Gadget_SetTextf(arg1,0x1f5a,(uint8_t *)s__d__d_00568ef8,DAT_0057d018);
    value5 = Game_GetPlayerBySlot(DAT_0057c670,DAT_00568ef4);
    if (DAT_00568ef0 < 0x14) {
      DAT_0057d01c = IDMap_Lookup((void *)(value5 + 0x148),DAT_00568ef0,(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,0x1f9d,DAT_0057d01c + 4);
    }
    else if (DAT_00568ef0 < 0x27) {
      value5 = IDMap_Lookup((void *)(value5 + 0x180),DAT_00568ef0 + -0x14,(int *)0x0);
      value5 = Get_Subobject4(value5);
      Window_GadgetNotify_Text_SetText(arg1,0x1f9d,value5);
    }
    else {
      Gadget_SetTextf(arg1,0x1f9d,(uint8_t *)s__s__s_00563314,DAT_00581c50);
    }
  }
  UI_SetChildVisibleByID(arg1,0x1f5d,(uint32_t)(DAT_0057d01c != 0));
  Gadget_SetTextf(arg1,0x1f71,&DAT_005686f4,DAT_0057d220);
  Gadget_SetTextf(arg1,0x1f6c,&DAT_005686f4,DAT_0057d228);
  Gadget_SetTextf(arg1,0x1f6d,&DAT_005686f4,DAT_0057d230);
  Gadget_SetTextf(arg1,0x1f6e,&DAT_005686f4,DAT_0057d238);
  Gadget_SetTextf(arg1,0x1f70,&DAT_005686f4,DAT_0057d224);
  Gadget_SetTextf(arg1,0x1f65,&DAT_005686f4,DAT_0057d22c);
  Gadget_SetTextf(arg1,0x1f67,&DAT_005686f4,DAT_0057d234);
  Gadget_SetTextf(arg1,0x1f69,&DAT_005686f4,DAT_0057d23c);
  Window_GadgetNotify_Text_SetText(arg1,0x1f9e,&DAT_0057d020);
  return;
}
