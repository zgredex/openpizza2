// City_SpawnResidentWeighted: ported from Pizza Connection 2 at 0x4da110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da110
#include "pc2_port.h"

void __fastcall City_SpawnResidentWeighted(void *arg1)

{
  uint32_t uvalue1;
  void *self;
  int value2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  int *ptr6;
  int local_fa0 [1000];
  
                    /* Moves a resident into a weighted-choice city house. */
  value4 = 0;
  do {
    uvalue1 = Random_RangeFast(0,2);
    self = (void *)Game_FindIdleObjectByClass(DAT_0057c670,uvalue1);
    if (self != (void *)0x0) {
      value4 = 0;
      uvalue3 = 0;
      do {
        value2 = Game_GetPlayerBySlot(DAT_0057c670,value4);
        uvalue5 = uvalue3;
        if (value2 != 0) {
          value2 = Stats_GetPlayerSharePercent(arg1,value4);
          uvalue5 = value2 + uvalue3;
          if ((intptr_t)uvalue3 < (intptr_t)uvalue5) {
            ptr6 = local_fa0 + uvalue3;
            for (value2 = uvalue5 - uvalue3; value2 != 0; value2 = value2 + -1) {
              *ptr6 = value4;
              ptr6 = ptr6 + 1;
            }
          }
        }
        value4 = value4 + 1;
        uvalue3 = uvalue5;
      } while (value4 < 6);
      uvalue3 = Random_RangeFast(0,uvalue5);
      value4 = Game_GetPlayerBySlot(DAT_0057c670,local_fa0[uvalue3]);
      if ((value4 != 0) && (0 < *(int *)(value4 + 0x15c))) {
        uvalue3 = Random_RangeFast(0,*(int *)(value4 + 0x15c) - 1);
        value4 = IDMap_Lookup((void *)(value4 + 0x148),uvalue3,(int *)0x0);
        if (value4 != 0) {
          Person_AssignBranchStaffRole(self,value4,uvalue1,0xffffffff,'\0');
        }
      }
      return;
    }
    value4 = value4 + 1;
  } while (value4 < 4);
  return;
}
