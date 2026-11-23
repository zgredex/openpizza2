// Storage_ReceivePendingOrder: ported from Pizza Connection 2 at 0x5142c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5142c0
#include "pc2_port.h"

uint32_t __thiscall Storage_ReceivePendingOrder(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  
  if (*(int *)((intptr_t)self + 0x58) == 0) {
    Storage_OrderDelivery((intptr_t)self);
    return 0;
  }
  uvalue1 = IDMap_Lookup((void *)((intptr_t)self + 0x44),0,(int *)0x0);
  IDMap_RemoveRecursive((void *)((intptr_t)self + 0x44),0);
  value2 = Array_FindPair(self,arg1);
  if (value2 != -1) {
    *(int *)((intptr_t)self + value2 * 0xc + 0x68) = *(int *)((intptr_t)self + value2 * 0xc + 0x68) + 1;
  }
  Storage_OrderDelivery((intptr_t)self);
  return uvalue1;
}
