// Map_CollectType351ToList: ported from Pizza Connection 2 at 0x47e6e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e6e0
#include "pc2_port.h"

void __fastcall Map_CollectType351ToList(int arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  uint32_t *uptr4;
  uint32_t *uptr5;
  uint32_t local_280 [160];
  
  value1 = Grid_CollectType351(*(void **)(arg1 + 0x14e0),(intptr_t)local_280);
  if (0 < value1) {
    uptr4 = local_280 + 1;
    do {
      uptr2 = operator_new(0x20);
      uptr5 = uptr2;
      for (value3 = 8; value3 != 0; value3 = value3 + -1) {
        *uptr5 = 0;
        uptr5 = uptr5 + 1;
      }
      uptr2[5] = uptr4[-1];
      uptr2[6] = *uptr4;
      uptr2[7] = 0;
      List_Add((void *)(arg1 + 0x1998),uptr2);
      uptr4 = uptr4 + 2;
      value1 = value1 + -1;
    } while (value1 != 0);
  }
  return;
}
