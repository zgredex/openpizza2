// CRT_GetStreamBuffer: ported from Pizza Connection 2 at 0x552042.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552042
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __cdecl CRT_GetStreamBuffer(uint32_t *arg1)

{
  uint32_t uvalue1;
  uint8_t flag2;
  uint32_t extraout_var;
  int value3;
  void *pvVar4;
  
  flag2 = CRT_TestLockFlag(arg1[4]);
  if (CONCAT31(extraout_var,flag2) == 0) {
    return 0;
  }
  if (arg1 == (uint32_t *)&DAT_005767a8) {
    value3 = 0;
  }
  else {
    if (arg1 != (uint32_t *)&DAT_005767c8) {
      return 0;
    }
    value3 = 1;
  }
  _DAT_00585660 = _DAT_00585660 + 1;
  if ((*(uint16_t *)(arg1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_00585664)[value3] == 0) {
    pvVar4 = _malloc(0x1000);
    (&DAT_00585664)[value3] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      arg1[2] = arg1 + 5;
      *arg1 = arg1 + 5;
      arg1[6] = 2;
      arg1[1] = 2;
      goto LAB_005520be;
    }
  }
  uvalue1 = (&DAT_00585664)[value3];
  arg1[6] = 0x1000;
  arg1[2] = uvalue1;
  *arg1 = uvalue1;
  arg1[1] = 0x1000;
LAB_005520be:
  *(uint16_t *)(arg1 + 3) = *(uint16_t *)(arg1 + 3) | 0x1102;
  return 1;
}
