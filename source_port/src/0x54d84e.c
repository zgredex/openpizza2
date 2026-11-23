// Thunk_SetVTable55CCA4: ported from Pizza Connection 2 at 0x54d84e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d84e
#include "pc2_port.h"

void __fastcall Thunk_SetVTable55CCA4(int arg1)

{
  *(uint8_t ***)(*(int *)(*(int *)(arg1 + -8) + 4) + -8 + arg1) = &PTR_LAB_0055cca4;
  return;
}
