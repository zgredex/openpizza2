// GuardMenu_Fill: ported from Pizza Connection 2 at 0x4bd340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bd340
#include "pc2_port.h"

void __cdecl GuardMenu_Fill(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint8_t *uptr3;
  
  Sound_ProcessEvent(DAT_0057ba0c,0x17,0,'\x01');
  DAT_0057d6fc = *(uint32_t *)(DAT_0057c670 + 0x21c);
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value2 = Game_GetPlayerCity((intptr_t)self);
  value1 = *(int *)(value2 + 0x68);
  value2 = *(int *)(value2 + 0x50);
  Gadget_SetTextf(arg1,0x1f76,(uint8_t *)s__s__d_00568964,DAT_00581044);
  uptr3 = Economy_GetModifier(self,0x17,0);
  Gadget_SetTextf(arg1,0x1f68,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x17,1);
  Gadget_SetTextf(arg1,0x1f67,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(self,0x17,2);
  Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,uptr3);
  Gadget_SetTextf(arg1,0x1f74,&DAT_005683a4,(((value1 + value2) * -0x1e + 100) * 500) / 100);
  GuardMenu_FillSummary(arg1);
  return;
}
