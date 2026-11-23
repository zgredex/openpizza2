// CRT_StreamClassDestruct: ported from Pizza Connection 2 at 0x54cd50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cd50
#include "pc2_port.h"

void __fastcall CRT_StreamClassDestruct(int arg1)

{
  *(uint8_t ***)(*(int *)(*(int *)(arg1 + -0xc) + 4) + -0xc + arg1) = &PTR_LAB_0055cc2c;
  COM_SetSecondaryVTable(arg1);
  return;
}
