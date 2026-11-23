// SoundBuffer_SetVolume: ported from Pizza Connection 2 at 0x5411c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5411c0
#include "pc2_port.h"

uint32_t __fastcall SoundBuffer_SetVolume(int arg1)

{
  int value1;
  int64_t lvalue2;
  
  lvalue2 = __ftol();
  value1 = (**(code **)(**(int **)(arg1 + 0x48) + 0x44))(*(int **)(arg1 + 0x48),(intptr_t)lvalue2);
  if (value1 < 0) {
    return 0x80070057;
  }
  *(int *)(arg1 + 0x14) = (intptr_t)lvalue2;
  return 0;
}
