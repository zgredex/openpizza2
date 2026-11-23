// Game_AdvanceCurrentRecord: ported from Pizza Connection 2 at 0x4ba250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ba250
#include "pc2_port.h"

void Game_AdvanceCurrentRecord(void)

{
  int value1;
  int value2;
  bool flag3;
  int value4;
  int value5;
  int value6;
  int value7;
  int local_8;
  
  value7 = *(int *)(DAT_0057d6e8 + 0x30);
  flag3 = false;
  value4 = Game_GetPlayerBySlot(DAT_0057c670,value7);
  local_8 = 0;
  value1 = *(int *)(value4 + 0x15c);
  if (value1 < 1) {
    return;
  }
  do {
    value5 = IDMap_Lookup((void *)(value4 + 0x148),local_8,(int *)0x0);
    if (value5 == DAT_0057d6e8) {
      value4 = IDMap_Lookup((void *)(value4 + 0x148),local_8 + 1,(int *)0x0);
      if (value4 != 0) {
        DAT_0057d6e8 = value4;
        return;
      }
      value5 = 0;
      while( true ) {
        value5 = value5 + 1;
        value7 = value7 + 1;
        if (5 < value7) {
          value7 = 0;
        }
        value4 = Game_GetPlayerBySlot(DAT_0057c670,value7);
        if (((value4 != 0) &&
            (value2 = *(int *)(value4 + 0x48),
            value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value2 != value6)) &&
           (0 < *(int *)(value4 + 0x15c))) break;
        if ((flag3) || (6 < value5)) goto LAB_004ba316;
      }
      DAT_0057d6e8 = IDMap_Lookup((void *)(value4 + 0x148),0,(int *)0x0);
      flag3 = true;
    }
LAB_004ba316:
    local_8 = local_8 + 1;
    if (value1 <= local_8) {
      return;
    }
  } while( true );
}
