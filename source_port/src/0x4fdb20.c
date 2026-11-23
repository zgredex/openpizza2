// AI_TryTakeOverRivalBranch: ported from Pizza Connection 2 at 0x4fdb20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fdb20
#include "pc2_port.h"

uint32_t AI_TryTakeOverRivalBranch(void *arg1,uint32_t arg2,void *arg3)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  int value4;
  int value5;
  
                    /* Attempts an AI takeover of a rival branch. */
  value1 = Game_CountFreeResidentialBuildings((intptr_t)arg3);
  if (value1 != 0) {
    uvalue2 = City_MoveResidentIntoVacantHouse(arg1,(intptr_t)arg3,0);
    return uvalue2;
  }
  value1 = Rating_GetInverse100((intptr_t)arg3);
  if (value1 < 0x29) {
    uvalue2 = City_MoveResidentIntoVacantHouse(arg1,(intptr_t)arg3,0);
    return uvalue2;
  }
  value1 = Game_CountObjectsByType(arg3,0xffffffff);
  value5 = 0;
  if (0 < value1) {
    do {
      ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)arg3 + 0x1500),value5,(int *)0x0);
      if (ptr3 != (int *)0x0) {
        if (*(int *)(*ptr3 + 0xc) < 0x15) {
LAB_004fdbbf:
          uvalue2 = City_MoveResidentIntoVacantHouse(arg1,(intptr_t)arg3,1);
          return uvalue2;
        }
        value4 = Rating_AdjustB(*ptr3);
        if (value4 < 0x15) goto LAB_004fdbbf;
      }
      value5 = value5 + 1;
    } while (value5 < value1);
  }
  return 3;
}
