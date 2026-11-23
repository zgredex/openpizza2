// Object_FlushPending: ported from Pizza Connection 2 at 0x548ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548ac0
#include "pc2_port.h"

void __fastcall Object_FlushPending(int arg1)

{
  if (*(char *)(arg1 + 0x140) != '\0') {
    (**(code **)(**(int **)(arg1 + 8) + 0x68))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x80));
    *(uint8_t *)(arg1 + 0x140) = 0;
  }
  return;
}
