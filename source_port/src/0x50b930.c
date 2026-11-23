// Object_IsCompanySiteChanged: ported from Pizza Connection 2 at 0x50b930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b930
#include "pc2_port.h"

bool __thiscall Object_IsCompanySiteChanged(void *self,int arg1)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)self + 0x10c),(int *)0x0);
  if (value1 == 0) {
    return true;
  }
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)(value1 + 0x50),(int *)0x0);
  if (value1 == 0) {
    return true;
  }
  if (*(int *)(value1 + 0x81c) == -1) {
    return true;
  }
  if (*(int *)(value1 + 0x820) == -1) {
    return true;
  }
  value1 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value1 + 0x81c),*(int *)(value1 + 0x820));
  return value1 != arg1;
}
