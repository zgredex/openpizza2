// Sound_SetEnabledFlag: ported from Pizza Connection 2 at 0x5479c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5479c0
#include "pc2_port.h"

void __thiscall Sound_SetEnabledFlag(char *self,char arg1)

{
  if (arg1 == '\0') {
    if (((uint8_t)((DAT_00575090) >> 8)) != '\0') {
      DAT_00575090 = (DAT_00575090 & ~(0xffu << 8)) | (((arg1) & 0xffu) << 8);
      *(uint8_t *)((intptr_t)self + 0xfe) = 1;
    }
  }
  else if (((uint8_t)((DAT_00575090) >> 8)) == '\0') {
    DAT_00575090 = (DAT_00575090 & ~(0xffu << 8)) | (((arg1) & 0xffu) << 8);
    *(uint8_t *)((intptr_t)self + 0xfe) = 1;
    return;
  }
  return;
}
