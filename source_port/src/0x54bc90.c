// UI_RemoveAllBriefings: ported from Pizza Connection 2 at 0x54bc90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bc90
#include "pc2_port.h"

void __fastcall UI_RemoveAllBriefings(uint32_t *arg1)

{
  int value1;
  uint8_t *bptr2;
  
  if (arg1[1] != 0) {
    UI_DetachObject(arg1[1]);
  }
  bptr2 = (uint8_t *)(arg1 + 2);
  value1 = 6;
  do {
    UI_DecrementRowCounter((void *)*arg1,bptr2);
    bptr2 = bptr2 + 0x44;
    value1 = value1 + -1;
  } while (value1 != 0);
  return;
}
