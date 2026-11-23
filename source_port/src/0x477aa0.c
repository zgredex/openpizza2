// Branch_GenerateUniqueName: ported from Pizza Connection 2 at 0x477aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477aa0
#include "pc2_port.h"

void __fastcall Branch_GenerateUniqueName(int arg1)

{
  bool flag1;
  uint32_t uvalue2;
  int value3;
  int value4;
  uint32_t uvalue5;
  int value6;
  uint32_t unaff_EDI;
  int value7;
  int local_8;
  
  local_8 = 0;
  value4 = arg1;
  value7 = arg1;
  do {
    uvalue2 = Random_RangeFast(0,0x45);
    flag1 = false;
    value6 = 0;
    do {
      value3 = Game_GetPlayerBySlot(DAT_0057c670,value6);
      if (value3 != 0) {
        value4 = Game_GetPlayerBySlot(DAT_0057c670,value6);
        value4 = *(int *)(value4 + 0x15c);
        value7 = 0;
        if (0 < value4) {
          do {
            value3 = Game_GetPlayerBySlot(DAT_0057c670,value6);
            value3 = IDMap_Lookup((void *)(value3 + 0x148),value7,(int *)0x0);
            if ((value3 != 0) &&
               (uvalue5 = FUN_005570c0(*(void **)(&DAT_00583078 + uvalue2 * 4),(uint8_t *)(value3 + 4),
                                     *(void **)(&DAT_00583078 + uvalue2 * 4)), uvalue5 == 0)) {
              flag1 = true;
              goto LAB_00477b43;
            }
            value7 = value7 + 1;
          } while (value7 < value4);
        }
      }
      value6 = value6 + 1;
    } while (value6 < 6);
LAB_00477b43:
    if (((value7 == value4) || (!flag1)) || (local_8 = local_8 + 1, 0x1d < local_8)) {
      String_Format((uint8_t *)(arg1 + 4),*(uint8_t **)(&DAT_00583078 + uvalue2 * 4),unaff_EDI);
      return;
    }
  } while( true );
}
