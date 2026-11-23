// Sound_GetDeviceCaps: ported from Pizza Connection 2 at 0x541ca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541ca0
#include "pc2_port.h"

uint32_t __cdecl Sound_GetDeviceCaps(int *arg1)

{
  uint32_t uvalue1;
  int value2;
  uint32_t unaff_ESI;
  uint32_t *uptr3;
  uint32_t local_60 [24];
  
  uptr3 = local_60;
  for (value2 = 0x18; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  local_60[0] = 0x60;
  value2 = (**(code **)(*arg1 + 0x10))(arg1,local_60);
  if ((value2 < 0) || (uvalue1 = 0x10000, (unaff_ESI & 0x20) == 0)) {
    uvalue1 = 0;
  }
  return uvalue1;
}
