// Sound_RewindBuffer: ported from Pizza Connection 2 at 0x5445f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5445f0
#include "pc2_port.h"

uint32_t __thiscall Sound_RewindBuffer(void *self,uint32_t arg1)

{
  int value1;
  
  value1 = (**(code **)(**(int **)((intptr_t)self + 0x48) + 0x34))(*(int **)((intptr_t)self + 0x48),arg1);
  return (-1 < value1) - 1 & 0x80004005;
}
