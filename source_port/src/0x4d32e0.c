// MapSprite_ReleaseRecordList: ported from Pizza Connection 2 at 0x4d32e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d32e0
#include "pc2_port.h"

void __fastcall MapSprite_ReleaseRecordList(int arg1)

{
  Palette_Free((uint32_t *)(arg1 + 0x14));
  return;
}
