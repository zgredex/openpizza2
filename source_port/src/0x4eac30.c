// Game_GetNestedArrayEntry: ported from Pizza Connection 2 at 0x4eac30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eac30
#include "pc2_port.h"

uint32_t __thiscall Game_GetNestedArrayEntry(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  
  if (arg1 < 0) {
    return 0;
  }
  if (*(int *)((intptr_t)self + arg1 * 0x48 + 0x68) == 0) {
    return 0;
  }
  value1 = Game_GetRecordChild14(self,arg1);
  if (arg2 < value1) {
    uvalue2 = IDMap_Lookup(*(void **)((intptr_t)self + arg1 * 0x48 + 0x68),arg2,(int *)0x0);
    return uvalue2;
  }
  return 0;
}
