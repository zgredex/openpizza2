// List_Node_Reset: ported from Pizza Connection 2 at 0x401440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401440
#include "pc2_port.h"

void __fastcall List_Node_Reset(int arg1)

{
  if (*(LPVOID *)(arg1 + 4) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 4));
  }
  *(uint32_t *)(arg1 + 4) = 0;
  if (*(LPVOID *)(arg1 + 8) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)(arg1 + 8));
  }
  *(uint32_t *)(arg1 + 8) = 0;
  *(uint32_t *)(arg1 + 0x10) = 0;
  *(uint32_t *)(arg1 + 0xc) = 0;
  *(uint32_t *)(arg1 + 0x14) = 0;
  *(uint32_t *)(arg1 + 0x18) = 100000;
  return;
}
