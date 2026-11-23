// Game_GetRecordByField814: ported from Pizza Connection 2 at 0x4d3910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3910
#include "pc2_port.h"

void __fastcall Game_GetRecordByField814(int arg1)

{
  IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*(int *)(arg1 + 0x814),(int *)0x0);
  return;
}
