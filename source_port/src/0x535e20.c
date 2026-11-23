// Palette_WriteToStream: ported from Pizza Connection 2 at 0x535e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535e20
#include "pc2_port.h"

void __thiscall Palette_WriteToStream(void *self,int *arg1)

{
  if (*(int *)self == 0) {
    NoOp_Stub();
  }
  CRT_FwriteLocked(*(char **)self,1,0x300,arg1);
  return;
}
