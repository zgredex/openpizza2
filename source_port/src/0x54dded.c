// CRT_InitFloatCvtTable: ported from Pizza Connection 2 at 0x54dded.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dded
#include "pc2_port.h"

void CRT_InitFloatCvtTable(void)

{
  PTR_FUN_00576a1c = &LAB_00551a42;
  PTR_FUN_00576a18 = __cfltcvt;
  PTR_FUN_00576a20 = __fassign;
  PTR_FUN_00576a24 = CRT_ForceDecimalPoint;
  PTR_FUN_00576a28 = &LAB_00551a90;
  PTR_FUN_00576a2c = __cfltcvt;
  return;
}
