// Map_ApplyRandomTileVariant: ported from Pizza Connection 2 at 0x4d22c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d22c0
#include "pc2_port.h"

void __fastcall Map_ApplyRandomTileVariant(int arg1)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x28),(int *)0x0);
  self = *(void **)(value1 + 0xfa8);
  if (*(int *)(arg1 + 0x6c) == 0) {
    Array_GetRecord28(self,1,*(int *)(arg1 + 0x54));
    return;
  }
  uvalue2 = Random_RangeFast(0,*(int *)(arg1 + 0x6c) - 1);
  value1 = IDMap_Lookup((void *)(arg1 + 0x58),uvalue2,(int *)0x0);
  Array_GetRecord28(self,1,value1);
  return;
}
