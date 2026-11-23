// Stream_GetChar: ported from Pizza Connection 2 at 0x54d372.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d372
#include "pc2_port.h"

uint32_t __fastcall Stream_GetChar(int *arg1)

{
  uint32_t uvalue1;
  
  if (arg1[2] != 0) {
    if (arg1[3] == -1) {
      (**(code **)(*arg1 + 0x20))();
    }
    uvalue1 = (**(code **)(*arg1 + 0x20))();
    arg1[3] = uvalue1;
    return uvalue1;
  }
  if ((arg1[0xb] == 0) || ((uint32_t)arg1[0xb] <= (uint32_t)arg1[10])) {
    (**(code **)(*arg1 + 0x20))();
  }
  arg1[10] = arg1[10] + 1;
  if ((uint8_t *)arg1[10] < (uint8_t *)arg1[0xb]) {
    return (uint32_t)*(uint8_t *)arg1[10];
  }
  uvalue1 = (**(code **)(*arg1 + 0x20))();
  return uvalue1;
}
