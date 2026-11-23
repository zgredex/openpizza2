// Map_PickRandomExitDirection: ported from Pizza Connection 2 at 0x4e4810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4810
#include "pc2_port.h"

uint8_t __fastcall Map_PickRandomExitDirection(int arg1)

{
  uint32_t uvalue1;
  uint32_t *uptr2;
  int value3;
  uint32_t local_10 [4];
  
  uptr2 = local_10;
  uvalue1 = 1;
  value3 = 0;
  do {
    if (-1 < *(char *)((uvalue1 & 0xff) + 200 + arg1)) {
      *uptr2 = uvalue1;
      value3 = value3 + 1;
      uptr2 = uptr2 + 1;
    }
    uvalue1 = uvalue1 + 1;
  } while ((intptr_t)uvalue1 < 4);
  uvalue1 = Random_RangeFast(0,value3 - 1);
  return (char)local_10[uvalue1];
}
