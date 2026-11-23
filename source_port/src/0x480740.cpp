// Object_AccumulateIncome: ported from Pizza Connection 2 at 0x480740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480740
#include "pc2_port.h"

void __fastcall Object_AccumulateIncome(int arg1)

{
  *(int *)(arg1 + 0x16bc) = *(int *)(arg1 + 0x16bc) + *(int *)(arg1 + 0x14d4);
  return;
}
