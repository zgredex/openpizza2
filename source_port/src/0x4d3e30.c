// Person_RemoveFromStaff: ported from Pizza Connection 2 at 0x4d3e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3e30
#include "pc2_port.h"

void __fastcall Person_RemoveFromStaff(int arg1)

{
  void *pvVar1;
  int value2;
  int *ptr3;
  int value4;
  
                    /* Removes a person from branch and player staff rosters. */
  if (*(int *)(arg1 + 0x820) != -1) {
    pvVar1 = (void *)Game_GetPlayerSubmapValue
                               (DAT_0057c670,*(int *)(arg1 + 0x81c),*(int *)(arg1 + 0x820));
    if (pvVar1 != (void *)0x0) {
      value2 = IDMap_FindIndexByValue(pvVar1,arg1);
      if (value2 != -1) {
        value4 = 0;
        ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x1500),value2,(int *)0x0);
        Branch_RemoveStaffMember(pvVar1,ptr3,value4);
      }
    }
  }
  pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x818),(int *)0x0
                               );
  if (pvVar1 != (void *)0x0) {
    ptr3 = Map_FindRecordByFirstField(pvVar1,arg1);
    if (ptr3 != (int *)0x0) {
      City_RemovePersonEntry(pvVar1,ptr3);
      Mem_Free(ptr3);
    }
  }
  value2 = Game_GetRecordByField814(arg1);
  if (*(int *)(value2 + 0x78) != 0x23) {
    *(uint32_t *)(value2 + 0x78) = 0x23;
    if (*(int *)(value2 + 0x74) == 0) {
      Person_TruncatePathToCurrentStep(value2);
      return;
    }
    *(uint8_t *)(value2 + 0x81) = 1;
  }
  return;
}
