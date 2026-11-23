// SaveGame_AnyExist: ported from Pizza Connection 2 at 0x4a1450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1450
#include "pc2_port.h"

uint32_t SaveGame_AnyExist(void)

{
  HANDLE pvVar1;
  uint32_t local_118 [70];
  
  pvVar1 = CRT_FindFirst(s_save_games_save___piz_00568d1c,local_118);
  if (pvVar1 != (HANDLE)0xffffffff) {
    CRT_FindClose(pvVar1);
    return 1;
  }
  pvVar1 = CRT_FindFirst(s_save_games_auto___piz_00568d04,local_118);
  if (pvVar1 == (HANDLE)0xffffffff) {
    return 0;
  }
  CRT_FindClose((HANDLE)0xffffffff);
  return 1;
}
