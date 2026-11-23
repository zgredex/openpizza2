// Game_InitDateState: ported from Pizza Connection 2 at 0x4f6bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f6bd0
#include "pc2_port.h"

void __fastcall Game_InitDateState(uint32_t *arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  uint32_t *uptr4;
  int value5;
  uint32_t *uptr6;
  
  if (DAT_0057bb20 != '\0') {
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    if (value2 == 0) {
      value2 = 0;
    }
    else {
      value2 = value2 + 4;
    }
    if (DAT_0057bb2c == 0xb) {
      arg1[0x30] = 0x7fffffff;
    }
    else {
      arg1[0x30] = DAT_0057bb2c * 0x60;
    }
    *(uint16_t *)(arg1 + 0x31) = 0;
    *(uint8_t *)((intptr_t)arg1 + 0xc6) = 0;
    arg1[1] = DAT_0057bb48;
    arg1[2] = DAT_0057bb4c;
    arg1[3] = DAT_0057bb50;
    uptr4 = arg1 + 4;
    for (value5 = 0x2c; value5 != 0; value5 = value5 + -1) {
      *uptr4 = 0;
      uptr4 = uptr4 + 1;
    }
    uvalue1 = *(uint32_t *)(value2 + 0x33c);
    arg1[0x34] = 0xffffffff;
    arg1[0x32] = uvalue1;
    arg1[0x35] = 0xb;
    *(uint8_t *)(arg1 + 0x33) = 0;
    return;
  }
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (value2 == 0) {
    value2 = 0;
  }
  else {
    value2 = value2 + 4;
  }
  uptr4 = (uint32_t *)(value2 + 0x34c);
  arg1[0x30] = *(int *)(value2 + 0x348) * 0x60;
  value5 = 0;
  uptr6 = arg1;
  do {
    uptr6 = uptr6 + 1;
    value3 = value5 + 1;
    *uptr6 = *uptr4;
    *(uint8_t *)((intptr_t)arg1 + value5 + 0xc4) = 0;
    uptr4 = uptr4 + 1;
    value5 = value3;
  } while (value3 < 3);
  uptr4 = arg1 + 4;
  for (value5 = 0x2c; value5 != 0; value5 = value5 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  value2 = *(int *)(value2 + 0x33c);
  arg1[0x32] = value2;
  value2 = value2 + -1;
  arg1[0x34] = value2;
  if (value2 == 0) {
    arg1[0x35] = 0;
    *(uint8_t *)(arg1 + 0x33) = 0;
    return;
  }
  arg1[0x35] = 0xc;
  *(uint8_t *)(arg1 + 0x33) = 0;
  return;
}
