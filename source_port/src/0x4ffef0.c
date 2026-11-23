// Staff_HandleKidnapping: ported from Pizza Connection 2 at 0x4ffef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffef0
#include "pc2_port.h"

void __thiscall Staff_HandleKidnapping(void *self,void *arg1,int *arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int *ptr4;
  int value5;
  
                    /* Handles employee kidnapping, removal, and ransom. */
  value2 = *(int *)((intptr_t)arg1 + 0x30);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value2 == value1) {
    UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,4,4,2,*(int *)((intptr_t)arg1 + 0x16f0),DAT_005828a8,
                       DAT_0058190c,arg2 + 1);
  }
  value2 = Game_GetPlayerBySlot(DAT_0057c670,value2);
  if (value2 != 0) {
    value2 = *(int *)(value2 + 0x4c);
    Object_AdjustShortPercent(self,value2,0x19);
    value1 = Game_CountObjectsByType(arg1,0xffffffff);
    value5 = 0;
    if (0 < value1) {
      do {
        ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value5,(int *)0x0);
        ptr4 = (int *)Game_GetRecordByField814(*ptr3);
        if (ptr4 == arg2) break;
        value5 = value5 + 1;
      } while (value5 < value1);
      arg2 = ptr3;
    }
    if ((value5 != value1) && (arg2 != (int *)0x0)) {
      Branch_RemoveStaffMember(arg1,arg2,0);
      value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      *(int *)(value1 + 0x10b4) = *(int *)(value1 + 0x10b4) + 1;
      if (*(int *)((intptr_t)self + value2 * 0x168 + 0x114) != 0) {
        value2 = arg2[1];
        ptr3 = City_AssignPersonToBuilding(arg1,(uint32_t)*(uint8_t *)(*arg2 + 0x824));
        if (ptr3 != (int *)0x0) {
          ptr3[1] = value2;
        }
      }
    }
  }
  return;
}
