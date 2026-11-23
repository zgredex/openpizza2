// Color_RGBTo16FromDword: ported from Pizza Connection 2 at 0x539840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539840
#include "pc2_port.h"

void __thiscall Color_RGBTo16FromDword(void *self,uint32_t arg1)

{
  Color_RGBTo16(self,(uint8_t)arg1,(uint8_t)(arg1 >> 8),arg1 >> 0x10 & 0xff);
  return;
}
