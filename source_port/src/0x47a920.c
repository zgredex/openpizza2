// Branch_ApplyStatsToOwner: ported from Pizza Connection 2 at 0x47a920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a920
#include "pc2_port.h"

void __fastcall Branch_ApplyStatsToOwner(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int *ptr3;
  float *fptr4;
  int value5;
  double fVar6;
  
                    /* Applies branch statistics to the owner and releases staff. */
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
  value1 = Game_FindRecordByField4(self,(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
  value2 = Stats_FindRecordByType(arg1,-1);
  if (value2 != 0) {
    value5 = 0x19;
    fptr4 = (float *)(value1 + 0x78);
    do {
      value5 = value5 + -1;
      *fptr4 = *(float *)((value2 - value1) + (intptr_t)fptr4) + *fptr4;
      fptr4 = fptr4 + 1;
    } while (value5 != 0);
  }
  fVar6 = Stats_SumFilteredFloats
                    ((intptr_t)arg1,-1,-1,(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
  *(float *)(value1 + 0x60) = (float)(fVar6 + (double)*(float *)(value1 + 0x60));
  if (0 < *(int *)((intptr_t)arg1 + 0x1514)) {
    do {
      value1 = 0;
      ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),0,(int *)0x0);
      Branch_RemoveStaffMember(arg1,ptr3,value1);
    } while (0 < *(int *)((intptr_t)arg1 + 0x1514));
  }
  return;
}
