// Map_GetRandomBuildingOfType: ported from Pizza Connection 2 at 0x4d74c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d74c0
#include "pc2_port.h"

int __thiscall Map_GetRandomBuildingOfType(void *self,int arg1,int arg2,char arg3)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int *ptr5;
  int value6;
  int local_400 [256];
  
  if (arg1 == 7) {
    arg1 = 0;
  }
  value4 = 0;
  value6 = 0;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    ptr5 = local_400;
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value6,(int *)0x0);
      if ((((*(int *)(value1 + 4) == arg1) && (*(int *)(value1 + 0x48) != -1)) &&
          ((arg3 == '\0' || (value2 = Game_CanShowObject(value1), value2 != 0)))) &&
         (value1 != arg2)) {
        *ptr5 = value1;
        value4 = value4 + 1;
        ptr5 = ptr5 + 1;
      }
      value6 = value6 + 1;
    } while (value6 < *(int *)((intptr_t)self + 0xfc0));
    if (value4 != 0) {
      uvalue3 = Random_RangeFast(0,value4 - 1);
      return local_400[uvalue3];
    }
  }
  DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_GetRandomBuilding___s_nicht_gefu_0056cd74,
                      *(uint32_t *)(&DAT_005840d4 + arg1 * 4));
  return 0;
}
