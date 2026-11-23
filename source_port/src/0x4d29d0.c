// Game_RemoveRecordFromLocalMap: ported from Pizza Connection 2 at 0x4d29d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d29d0
#include "pc2_port.h"

uint32_t __thiscall Game_RemoveRecordFromLocalMap(void *self,void *arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = IDMap_RemoveByKey((void *)((intptr_t)self + 0x78),*(int *)((intptr_t)arg1 + 0x164));
  Set_Field168(arg1,0);
  return uvalue1;
}
