// UI_ShowPauseDialog: ported from Pizza Connection 2 at 0x48d4c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d4c0
#include "pc2_port.h"


void UI_ShowPauseDialog(uint32_t arg1,uint32_t arg2)

{
  void *self;
  int local_4;
  
                    /* Shows the modal pause dialog. */
  self = Dialog_Loading(&local_4);
  *(uint8_t **)((intptr_t)self + 0x48) = &LAB_004c63f0;
  Window_GadgetNotify_Text_SetText(self,0x3e9,arg2);
  Window_GadgetNotify_Text_SetText(self,0x3f9,arg1);
  UI_AddUniquePair(self,0x3f8,0xd);
  Set_Field228(DAT_0057c5e0,self);
  Window_ShowWindowById(DAT_0057c5e0,local_4);
  return;
}
