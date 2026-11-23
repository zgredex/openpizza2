// Game_GetPlayerMapValue: ported from Pizza Connection 2 at 0x489850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489850
#include "pc2_port.h"

uint32_t __thiscall Game_GetPlayerMapValue(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  
  value1 = Game_GetPlayerBySlot(self,arg1);
  if (value1 == 0) {
    return 0;
  }
  uvalue2 = IDMap_Lookup((void *)(value1 + 0x180),arg2,(int *)0x0);
  return uvalue2;
}
