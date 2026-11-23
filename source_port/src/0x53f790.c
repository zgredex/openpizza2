// SoundBuffer_SeekSample: ported from Pizza Connection 2 at 0x53f790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f790
#include "pc2_port.h"

uint32_t __thiscall SoundBuffer_SeekSample(void *self,uint32_t arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0xc);
  if (value1 == 0) {
    return 0x80070006;
  }
  if (*(short *)((intptr_t)self + 0x14) == 1) {
    Stream_Seek(*(int *)((intptr_t)self + 0x2c) + arg1,value1,0);
    *(uint32_t *)((intptr_t)self + 0x30) = arg1;
    return 0;
  }
  Stream_Seek((arg1 /
              ((uint32_t)*(uint16_t *)((intptr_t)self + 0x20) * 4 + (uint32_t)*(uint16_t *)((intptr_t)self + 0x16) * -0xe)
              ) * (uint32_t)*(uint16_t *)((intptr_t)self + 0x20) + *(int *)((intptr_t)self + 0x2c),value1,0);
  *(uint32_t *)((intptr_t)self + 0x30) = arg1;
  *(uint8_t *)((intptr_t)self + 0x48) = 1;
  return 0;
}
