// Resource_Close: ported from Pizza Connection 2 at 0x402990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402990
#include "pc2_port.h"

void __thiscall Resource_Close(void *self,int arg1)

{
  CS_Enter((intptr_t)self + 0x1688);
  if (*(int *)(arg1 + 0x1c) == 1) {
    CRT_Fclose(*(FILE **)(arg1 + 0x18));
  }
  *(uint32_t *)(arg1 + 0x14) = 0;
  CS_Leave((intptr_t)self + 0x1688);
  return;
}
