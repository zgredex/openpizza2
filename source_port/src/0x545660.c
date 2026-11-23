// Sound_Get3DBufferParams: ported from Pizza Connection 2 at 0x545660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545660
#include "pc2_port.h"

uint32_t __fastcall Sound_Get3DBufferParams(int arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  
  uptr1 = (uint32_t *)(arg1 + 0x60);
  uptr4 = uptr1;
  for (value3 = 0x10; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  *uptr1 = 0x40;
  value3 = (**(code **)(**(int **)(arg1 + 0x5c) + 0xc))(*(int **)(arg1 + 0x5c),uptr1);
  uvalue2 = 0x80070057;
  if (-1 < value3) {
    uvalue2 = 0;
  }
  return uvalue2;
}
