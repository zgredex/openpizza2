// Sound_StopCurrentBuffer: ported from Pizza Connection 2 at 0x548db0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548db0
#include "pc2_port.h"

void __fastcall Sound_StopCurrentBuffer(int arg1)

{
  if (*(char *)(arg1 + 0xfc) != '\0') {
    CS_Enter(arg1 + 0x178);
    if (*(int *)(arg1 + 0x10) != 0) {
      (**(code **)(**(int **)(arg1 + 8) + 0x54))(*(int **)(arg1 + 8),*(int *)(arg1 + 0x10))
      ;
      *(uint32_t *)(arg1 + 0x10) = 0;
      *(uint32_t *)(arg1 + 0x14) = 0;
    }
    CS_Leave(arg1 + 0x178);
  }
  return;
}
