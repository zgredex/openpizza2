// Game_ApplyObjectEvent: ported from Pizza Connection 2 at 0x50ad00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ad00
#include "pc2_port.h"

int __fastcall Game_ApplyObjectEvent(int arg1)

{
  int value1;
  int value2;
  
  if (((*(int *)(arg1 + 200) == 0) ||
      (value2 = Map_GetObjectNeighborCell
                         (*(void **)(arg1 + 0xc4),*(int *)(arg1 + 200),
                          *(int *)(arg1 + 0x88)), value2 == 0)) ||
     (value1 = *(int *)(value2 + 8), value1 == 0)) {
    value2 = 0;
  }
  else {
    switch(*(uint32_t *)(*(int *)(arg1 + 200) + 0xc)) {
    case 0x14:
      *(uint8_t *)(value1 + 0x2c) = 0;
      return value2;
    case 0x15:
      *(uint8_t *)(value1 + 0x2d) = 0;
      return value2;
    case 0x16:
      *(uint8_t *)(value1 + 0x2e) = 0;
      return value2;
    case 0x17:
      *(uint8_t *)(value1 + 0x2f) = 0;
      return value2;
    }
  }
  return value2;
}
