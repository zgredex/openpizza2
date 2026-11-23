// Sound_ApplySettings: ported from Pizza Connection 2 at 0x5477a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5477a0
#include "pc2_port.h"

void __thiscall Sound_ApplySettings(void *self,uint32_t *arg1)

{
  uint32_t uvalue1;
  
  DAT_00575094 = arg1[1];
  DAT_00575098 = arg1[2];
  DAT_0057509c = arg1[3];
  DAT_00575090 = (DAT_00575090 & ~(0xffffu << 16)) | ((((uint16_t)((uint32_t)*arg1 >> 0x10)) & 0xffffu) << 16);
  DAT_00575090 = (DAT_00575090 & ~(0x0u << 16)) | (((CONCAT11(*(uint8_t *)((intptr_t)arg1 + 1),(char)*arg1)) & 0x0u) << 16);
  Sound_LoadSpeechSet(self);
  *(uint32_t *)((intptr_t)self + 0x1d0) = arg1[1];
  uvalue1 = Sound_ConvertVolumeSetting(arg1[2]);
  *(uint32_t *)((intptr_t)self + 0x1d4) = uvalue1;
  uvalue1 = Sound_ConvertVolumeSetting(arg1[3]);
  *(uint32_t *)((intptr_t)self + 0x1d8) = uvalue1;
  return;
}
