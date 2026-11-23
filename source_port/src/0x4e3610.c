// Game_ComputeActionCost: ported from Pizza Connection 2 at 0x4e3610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3610
#include "pc2_port.h"

int __fastcall Game_ComputeActionCost(int arg1)

{
  int value1;
  int value2;
  
  if (*(int *)(arg1 + 100) < 3) {
    value1 = *(int *)(&DAT_0056d104 + *(int *)(arg1 + 100) * 4);
    value2 = Game_GetPlayerCity(arg1);
    return (((*(int *)(value2 + 0x68) + *(int *)(value2 + 0x50)) * -0x1e + 100) * value1) / 100;
  }
  return 0;
}
