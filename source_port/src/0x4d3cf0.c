// Person_ReleaseFromBranch: ported from Pizza Connection 2 at 0x4d3cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3cf0
#include "pc2_port.h"

void __fastcall Person_ReleaseFromBranch(void *arg1)

{
  void *self;
  int value1;
  void *this_00;
  void *this_01;
  int64_t lvalue2;
  int value3;
  float fVar4;
  
                    /* Charges and releases a person from their branch job. */
  this_01 = (void *)0x0;
  self = (void *)Game_GetRecordByField814((intptr_t)arg1);
  value3 = *(int *)((intptr_t)arg1 + 0x820);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x81c));
  this_00 = (void *)IDMap_Lookup((void *)(value1 + 0x148),value3,(int *)0x0);
  if (this_00 != (void *)0x0) {
    value3 = *(int *)((intptr_t)this_00 + 0x34);
    *(int *)((intptr_t)arg1 + 0x818) = value3;
    this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),value3,(int *)0x0);
    switch(*(uint8_t *)((intptr_t)arg1 + 0x824)) {
    case 0:
      fVar4 = (float)*(int *)((intptr_t)arg1 + 0x3c);
      value3 = 6;
      break;
    case 1:
      fVar4 = (float)*(int *)((intptr_t)arg1 + 0x3c);
      value3 = 8;
      break;
    case 2:
      fVar4 = (float)*(int *)((intptr_t)arg1 + 0x3c);
      value3 = 7;
      break;
    case 3:
      fVar4 = (float)*(int *)((intptr_t)arg1 + 0x3c);
      value3 = 0xd;
      break;
    default:
      goto switchD_004d3d52_default;
    }
    Game_CanAfford(this_00,value3,fVar4,'\0',-1);
  }
switchD_004d3d52_default:
  *(uint32_t *)((intptr_t)arg1 + 0x81c) = 0xffffffff;
  *(uint32_t *)((intptr_t)arg1 + 0x820) = 0xffffffff;
  lvalue2 = Rating_GetCompositeTruncated((intptr_t)arg1);
  Person_SetPerformance(arg1,(intptr_t)lvalue2);
  if (this_01 == (void *)0x0) {
    Person_RemoveFromStaff((intptr_t)arg1);
    return;
  }
  *(uint32_t *)((intptr_t)self + 0x78) = 0x10;
  if (*(int *)((intptr_t)self + 0x74) == 0) {
    UI_SetChildState(self,0x13);
    Person_TruncatePathToCurrentStep((intptr_t)self);
    AI_AddKnownRecord(this_01,arg1);
    return;
  }
  *(uint8_t *)((intptr_t)self + 0x81) = 1;
  UI_SetChildState(self,0x13);
  AI_AddKnownRecord(this_01,arg1);
  return;
}
