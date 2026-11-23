// Object_SetCompanyStylePalette: ported from Pizza Connection 2 at 0x505f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505f40
#include "pc2_port.h"

void __cdecl
Object_SetCompanyStylePalette
          (uint8_t arg1,uint8_t arg2,uint8_t arg3,uint8_t arg4,
          uint8_t arg5,uint8_t arg6,uint8_t arg7,uint8_t arg8)

{
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  
  DAT_00580ac8 = arg1;
  DAT_00580ac9 = arg2;
  DAT_00580acb = arg4;
  DAT_00580aca = arg3;
  DAT_00580acc = arg5;
  DAT_00580ace = arg7;
  DAT_00580acd = arg6;
  DAT_00580acf = arg8;
  pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  value2 = Game_CountRecordsByOwner(pvVar1,3);
  if (0 < value2) {
    pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                  (int *)0x0);
    value2 = Map_GetRandomBuildingOfType(pvVar1,3,0,'\0');
    if (value2 != 0) {
      value2 = 0;
      do {
        if (((&DAT_00580ac8)[value2] == '\f') && (uvalue3 = Random_RangeFast(1,100), 0x32 < (intptr_t)uvalue3)
           ) {
          (&DAT_00580ac8)[value2] = 3;
        }
        value2 = value2 + 1;
      } while (value2 < 8);
    }
  }
  return;
}
