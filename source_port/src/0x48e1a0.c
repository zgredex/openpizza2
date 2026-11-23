// Game_CheckPlayerControlFlags: ported from Pizza Connection 2 at 0x48e1a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e1a0
#include "pc2_port.h"

bool __thiscall Game_CheckPlayerControlFlags(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  
  if (arg2 == 0) {
    if (arg1 == 0) {
      return false;
    }
    value1 = Game_GetPlayerBySlot(self,*(int *)(arg1 + 8));
    if (value1 == 0) {
      return false;
    }
    if (*(char *)(*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200) + 0xac +
                 *(int *)(value1 + 0x48)) != '\0') {
      return false;
    }
  }
  else {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(arg2 + 0x50),(int *)0x0);
    value1 = Game_GetPlayerBySlot(self,*(int *)(value1 + 0x81c));
    if (value1 == 0) {
      return false;
    }
    if (*(char *)(*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200) + 0xac +
                 *(int *)(value1 + 0x48)) != '\0') {
      return false;
    }
  }
  value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  return *(char *)(value2 + 0xac + value1) == '\0';
}
