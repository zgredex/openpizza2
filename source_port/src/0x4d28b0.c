// Game_RemoveObjectFromUI: ported from Pizza Connection 2 at 0x4d28b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d28b0
#include "pc2_port.h"

void __fastcall Game_RemoveObjectFromUI(int arg1)

{
  void *self;
  int value1;
  
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)(DAT_0057c670 + 0x2dac),(int *)0x0);
  if (self != (void *)0x0) {
    value1 = Array_GetRecordByKeyPtr(self,*(int *)(arg1 + 0x54));
    if (value1 != 0) {
      UI_RemoveObject(self,*(int *)(arg1 + 0x54));
    }
  }
  return;
}
