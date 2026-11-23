// SoundBuffer_SetBaseVTable: ported from Pizza Connection 2 at 0x53efd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53efd0
#include "pc2_port.h"

void __fastcall SoundBuffer_SetBaseVTable(uint32_t *arg1)

{
  *arg1 = &PTR_LAB_0055c840;
  return;
}
