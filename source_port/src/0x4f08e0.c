// Map_UnlinkCells: ported from Pizza Connection 2 at 0x4f08e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f08e0
#include "pc2_port.h"

void Map_UnlinkCells(uint32_t arg1,int arg2,int arg3)

{
  uint16_t uvalue1;
  uint16_t uvalue2;
  bool flag3;
  short *psVar4;
  int value5;
  
  uvalue1 = *(uint16_t *)(arg2 + 4);
  uvalue2 = *(uint16_t *)(arg3 + 4);
  psVar4 = (short *)(arg3 + 0x14);
  flag3 = true;
  value5 = 8;
  do {
    if ((intptr_t)*(short *)((arg2 - arg3) + (intptr_t)psVar4) == (uint32_t)uvalue2) {
      *(uint16_t *)((arg2 - arg3) + (intptr_t)psVar4) = 0xffff;
      flag3 = false;
    }
    if ((intptr_t)*psVar4 == (uint32_t)uvalue1) {
      *psVar4 = -1;
      flag3 = false;
    }
    psVar4 = psVar4 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  if (flag3) {
    Debug_WarningMessageBox();
  }
  NoOp_2();
  return;
}
