// City_GetLocalizedName: ported from Pizza Connection 2 at 0x4dca70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dca70
#include "pc2_port.h"

uint32_t __fastcall City_GetLocalizedName(int arg1)

{
  return *(uint32_t *)(&DAT_00582fd8 + *(int *)(arg1 + 0x10bc) * 4);
}
