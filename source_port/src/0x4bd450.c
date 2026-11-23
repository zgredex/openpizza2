// UI_SelectPreviousObjectOfType: ported from Pizza Connection 2 at 0x4bd450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bd450
#include "pc2_port.h"

void UI_SelectPreviousObjectOfType(void)

{
  void *pvVar1;
  int value2;
  
  value2 = Game_FindPreviousFreeObjectOfType(DAT_0057c670,DAT_0057d6fc);
  pvVar1 = DAT_0057c670;
  if (value2 != 0) {
    DAT_0057d6fc = value2;
    *(int *)((intptr_t)DAT_0057c670 + 0x21c) = value2;
    *(uint32_t *)((intptr_t)pvVar1 + 0x2da8) = 1;
  }
  return;
}
