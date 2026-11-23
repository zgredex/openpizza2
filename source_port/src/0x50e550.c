// Game_GetObjectStatusLevel: ported from Pizza Connection 2 at 0x50e550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e550
#include "pc2_port.h"

uint8_t __fastcall Game_GetObjectStatusLevel(int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(arg1 + 0x50),(int *)0x0);
  value3 = *(int *)(value1 + 0x81c);
  value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (value3 == value2) {
    value3 = Rating_AdjustB(value1);
    if (value3 < 0x14) {
      return 1;
    }
    if (0 < *(int *)(value1 + 0x14)) {
      return 2;
    }
    if (0 < *(int *)(value1 + 0x18)) {
      return 2;
    }
    if (0 < *(int *)(value1 + 0x20)) {
      return 3;
    }
    if (*(int *)(value1 + 0xc) < 0x14) {
      return 4;
    }
    if (*(int *)(arg1 + 0x30) == 0x14) {
      return -(*(char *)(value1 + 0x825) != '\x02') & 7;
    }
  }
  return 0;
}
