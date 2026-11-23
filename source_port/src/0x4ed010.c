// Map_ComputeIsoOffsets: ported from Pizza Connection 2 at 0x4ed010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed010
#include "pc2_port.h"

void __fastcall Map_ComputeIsoOffsets(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 0xc) << 1;
  *(int *)(arg1 + 0xd8) = value1;
  *(int *)(arg1 + 0xdc) = value1;
  *(int *)(arg1 + 0xe0) = *(int *)(arg1 + 0x10) * 2;
  *(int *)(arg1 + 0xe4) = *(int *)(arg1 + 0x10) * 3;
  return;
}
