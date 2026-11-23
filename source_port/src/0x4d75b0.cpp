// SaveGame_LookupSavedId: ported from Pizza Connection 2 at 0x4d75b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d75b0
#include "pc2_port.h"

void __thiscall SaveGame_LookupSavedId(void *self,int arg1)

{
  Map_LookupLinear((void *)((intptr_t)self + 0xfac),arg1);
  return;
}
