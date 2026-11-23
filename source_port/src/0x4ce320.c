// UI_ShowConfirmDialog: ported from Pizza Connection 2 at 0x4ce320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ce320
#include "pc2_port.h"


void __cdecl
UI_ShowConfirmDialog(int arg1,uint32_t arg2,uint32_t arg3,uint32_t arg4)

{
  void *self;
  
                    /* Shows the confirmation dialog and returns its command. */
  DAT_0057df80 = arg1;
  DAT_0057de78 = arg2;
  self = Dialog_Confirm(&arg1);
  *(uint8_t **)((intptr_t)self + 0x48) = &LAB_004ce2b0;
  Window_GadgetNotify_Text_SetText(self,0x42d,arg3);
  Window_GadgetNotify_Text_SetText(self,0x42f,arg4);
  Window_GadgetNotify_Text_SetMode(self,0x42f,2);
  UI_AddUniquePair(self,0x431,0xd);
  UI_AddUniquePair(self,0x430,0x1b);
  Window_ShowWindowById(DAT_0057c5e0,arg1);
  return;
}
