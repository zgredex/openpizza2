// CRT_DestructorThunk: ported from Pizza Connection 2 at 0x54d1f7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d1f7
#include "pc2_port.h"

void __fastcall CRT_DestructorThunk(int arg1)

{
  *(uint8_t ***)(*(int *)(*(int *)(arg1 + -8) + 4) + -8 + arg1) = &PTR_LAB_0055cc84;
  Thunk_SetVTable55CCA4(arg1);
  return;
}
