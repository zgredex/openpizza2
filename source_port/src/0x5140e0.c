// Storage_ChargePurchaseCost: ported from Pizza Connection 2 at 0x5140e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5140e0
#include "pc2_port.h"

void __fastcall Storage_ChargePurchaseCost(void *arg1)

{
  if (*(char *)((intptr_t)arg1 + 0x3c) == '\0') {
    Storage_DistributeCostToShops(arg1,(float)*(int *)((intptr_t)arg1 + 0x40),'\x01');
  }
  return;
}
