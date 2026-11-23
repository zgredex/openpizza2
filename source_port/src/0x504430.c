// MissionGoal_Evaluate: ported from Pizza Connection 2 at 0x504430.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x504430
#include "pc2_port.h"

void __thiscall MissionGoal_Evaluate(void *self,int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  
                    /* Evaluates the active mission goal and advances it when satisfied. */
  switch(*(uint32_t *)((intptr_t)self + 0x48)) {
  case 0x15:
    if (arg1 % 3 == 0) {
      List_Node_Reset((intptr_t)self + 0x68);
    }
  default:
    goto switchD_00504442_caseD_16;
  case 0x18:
    UI_AppendCommandIfActive(self,0x18,-1);
    uvalue2 = Game_IsInputIndexUsed(0x50);
    if ((char)uvalue2 == '\0') goto switchD_00504442_caseD_16;
    value3 = 0x18;
    break;
  case 0x1b:
    UI_AppendCommandIfActive(self,0x1b,-1);
    uvalue2 = Game_AnyBuildingRatingAbove(0x50);
    if ((char)uvalue2 == '\0') goto switchD_00504442_caseD_16;
    value3 = 0x1b;
    break;
  case 0x1c:
    UI_AppendCommandIfActive(self,0x1c,-1);
    uvalue2 = Game_AnyBuildingCategoryRatingAbove(0x50);
    if ((char)uvalue2 == '\0') goto switchD_00504442_caseD_16;
    value3 = 0x1c;
    break;
  case 0x1e:
    UI_AppendCommandIfActive(self,0x1e,-1);
    uvalue2 = Game_IsObjectStatAbove(0x50);
    if ((char)uvalue2 == '\0') goto switchD_00504442_caseD_16;
    value3 = 0x1e;
    break;
  case 0x20:
    UI_AppendCommandIfActive(self,0x20,-1);
    uvalue2 = Game_IsInputIndexUsed(0x32);
    if (((((char)uvalue2 == '\0') || (uvalue2 = Game_AnyBuildingRatingAbove(0x32), (char)uvalue2 == '\0'))
        || (uvalue2 = Game_AnyBuildingCategoryRatingAbove(0x32), (char)uvalue2 == '\0')) ||
       ((uvalue2 = Game_IsObjectStatAbove(0x32), (char)uvalue2 == '\0' ||
        (uvalue1 = Game_AllBuildingCategoryRatingsAbove(0x32), (char)uvalue1 == '\0'))))
    goto switchD_00504442_caseD_16;
    value3 = 0x20;
    break;
  case 0x21:
    UI_AppendCommandIfActive(self,0x21,-1);
    uvalue1 = Game_AllBuildingCategoryRatingsAbove(0x32);
    if ((char)uvalue1 == '\0') goto switchD_00504442_caseD_16;
    value3 = 0x21;
  }
  MissionGoal_HandleEvent(self,value3,-1,-1);
switchD_00504442_caseD_16:
  UI_DecrementTimer(self,0x30,'\x01');
  UI_DecrementTimer(self,0xf,'\x01');
  UI_DecrementTimer(self,4,'\x01');
  UI_DecrementTimer(self,0x2c,'\x01');
  UI_DecrementTimer(self,0x30,'\0');
  UI_DecrementTimer(self,0x10,'\0');
  UI_DecrementTimer(self,4,'\0');
  return;
}
