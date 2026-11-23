// Game_BuildStatusTextByIndex: ported from Pizza Connection 2 at 0x4e33a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e33a0
#include "pc2_port.h"

uint32_t __thiscall
Game_BuildStatusTextByIndex(void *self,int arg1,int arg2,int *arg3,char *arg4)

{
  int value1;
  uint32_t uvalue2;
  
  if (arg2 < 0x14) {
    value1 = IDMap_Lookup((void *)(arg1 + 0x148),arg2,(int *)0x0);
    if (value1 == 0) {
      return 0;
    }
    uvalue2 = Game_BuildCompanyStatusText(self,*(int *)(value1 + 0x16f0),arg3,arg4);
    return CONCAT31((int3)((uint32_t)uvalue2 >> 8),1);
  }
  if (0x27 < arg2) {
    if (*(int *)(arg1 + 0x1d8) == 0) {
      return 0;
    }
    uvalue2 = Game_BuildCompanyStatusText(self,*(int *)(arg1 + 0x1d8),arg3,arg4);
    return CONCAT31((int3)((uint32_t)uvalue2 >> 8),1);
  }
  value1 = IDMap_Lookup((void *)(arg1 + 0x180),arg2 + -0x14,(int *)0x0);
  if (value1 == 0) {
    return 0;
  }
  uvalue2 = Game_BuildCompanyStatusText(self,*(int *)(value1 + 0x34),arg3,arg4);
  return CONCAT31((int3)((uint32_t)uvalue2 >> 8),1);
}
