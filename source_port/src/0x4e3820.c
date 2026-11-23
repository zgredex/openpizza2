// Game_ComputePlayerSalary: ported from Pizza Connection 2 at 0x4e3820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3820
#include "pc2_port.h"

int __fastcall Game_ComputePlayerSalary(int arg1)

{
  int value1;
  int value2;
  
  value2 = *(int *)(arg1 + 0x68);
  value1 = Game_GetPlayerFieldC20(arg1);
  if (value2 == 1) {
    if (4 < value1) {
      value2 = 20000;
LAB_004e384b:
      value1 = Game_GetPlayerCity(arg1);
      return (((10 - *(int *)(value1 + 0x58)) - *(int *)(value1 + 0x40)) * value2 * 10) / 100;
    }
  }
  else if ((value2 == 2) && (5 < value1)) {
    value2 = 40000;
    goto LAB_004e384b;
  }
  return -1;
}
