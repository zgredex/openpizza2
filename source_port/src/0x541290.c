// SoundBuffer_SetFreqAndPan: ported from Pizza Connection 2 at 0x541290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541290
#include "pc2_port.h"

uint32_t __thiscall SoundBuffer_SetFreqAndPan(void *self,uint32_t arg1)

{
  int value1;
  uint32_t unaff_ESI;
  
  value1 = (**(code **)(**(int **)((intptr_t)self + 0x5c) + 0x44))(*(int **)((intptr_t)self + 0x5c),arg1,0);
  if (value1 < 0) {
    return 0x80070057;
  }
  value1 = (**(code **)(**(int **)((intptr_t)self + 0x5c) + 0x40))
                    (*(int **)((intptr_t)self + 0x5c),unaff_ESI,0);
  return (-1 < value1) - 1 & 0x80070057;
}
