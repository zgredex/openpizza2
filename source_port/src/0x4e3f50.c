// Game_ScalePlayerStat80: ported from Pizza Connection 2 at 0x4e3f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3f50
#include "pc2_port.h"

void __fastcall Game_ScalePlayerStat80(int arg1)

{
  int value1;
  int value2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value1 = *(int *)(value1 + 0xd40 + *(int *)(arg1 + 0x48) * 4);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  *(int *)(value2 + 0xd40 + *(int *)(arg1 + 0x48) * 4) = (value1 << 3) / 10;
  return;
}
