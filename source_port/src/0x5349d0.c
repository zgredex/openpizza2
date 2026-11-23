// RecordList_GetCount: ported from Pizza Connection 2 at 0x5349d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5349d0
#include "pc2_port.h"

uint32_t __fastcall RecordList_GetCount(int arg1)

{
  return *(uint32_t *)(arg1 + 0x68);
}
