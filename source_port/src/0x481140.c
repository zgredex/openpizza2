// Branch_GetCachedBillboards: ported from Pizza Connection 2 at 0x481140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481140
#include "pc2_port.h"

uint32_t __fastcall Branch_GetCachedBillboards(int arg1)

{
  void *self;
  uint32_t *uptr1;
  
  if (*(int *)(arg1 + 0x1a28) == 0) {
    self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
    uptr1 = Map_CollectBillboardDistances(self,*(int *)(arg1 + 0x16f0));
    *(uint32_t **)(arg1 + 0x1a28) = uptr1;
    return uptr1[5];
  }
  return *(uint32_t *)(*(int *)(arg1 + 0x1a28) + 0x14);
}
