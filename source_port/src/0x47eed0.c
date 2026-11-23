// Branch_SettleDueConstructionOrders: ported from Pizza Connection 2 at 0x47eed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47eed0
#include "pc2_port.h"

void __thiscall Branch_SettleDueConstructionOrders(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x19ac)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x1998),value2,(int *)0x0);
      if ((*(int *)(value1 + 0x1c) != 0) && (*(int *)(value1 + 4) <= arg1 * 10)) {
        Branch_PayConstructionOrder(self,value2);
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x19ac));
  }
  return;
}
