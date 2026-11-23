// Cost_ComputeQuantityPrice: ported from Pizza Connection 2 at 0x4d40d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d40d0
#include "pc2_port.h"

int __fastcall Cost_ComputeQuantityPrice(int arg1)

{
  return (*(int *)(arg1 + 0xc) / 10) * *(int *)(arg1 + 0x3c) * 10;
}
