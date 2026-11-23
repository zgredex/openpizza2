// Sound_StopAndReset: ported from Pizza Connection 2 at 0x548a00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548a00
#include "pc2_port.h"

void __fastcall Sound_StopAndReset(int arg1)

{
  int *ptr1;
  int value2;
  int64_t lvalue3;
  
  if ((*(char *)(arg1 + 0xfc) != '\0') && (*(char *)(arg1 + 0x169) != '\0')) {
    CS_Enter(arg1 + 0x178);
    Object_FlushPending(arg1);
    if (*(int *)(arg1 + 0x1d0) != 0) {
      (**(code **)(**(int **)(arg1 + 8) + 0x68))
                (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x84));
    }
    *(uint8_t *)(arg1 + 0x169) = 0;
    *(uint32_t *)(arg1 + 0x14c) = 0;
    if (*(int *)(arg1 + 0x1d0) != 0) {
      ptr1 = *(int **)(arg1 + 8);
      value2 = *ptr1;
      lvalue3 = __ftol();
      (**(code **)(value2 + 0xa4))(ptr1,*(uint32_t *)(arg1 + 0xf8),(intptr_t)lvalue3);
    }
    SoundBuffer_Release(arg1);
    CS_Leave(arg1 + 0x178);
  }
  return;
}
