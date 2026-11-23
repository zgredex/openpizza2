// Branch_GetBuildingValue: ported from Pizza Connection 2 at 0x47fd90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fd90
#include "pc2_port.h"

double __fastcall Branch_GetBuildingValue(int arg1)

{
  int value1;
  void *self;
  void *this_00;
  void *pvVar2;
  int value3;
  double fVar4;
  
  value3 = 0;
  value1 = IDMap_Lookup((void *)(arg1 + 0x1998),0,(int *)0x0);
  if ((value1 != 0) && (*(int *)(value1 + 0x1c) != 0)) {
    return (double)*(float *)(value1 + 0x10);
  }
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0
                                );
  pvVar2 = Player_FindRecordByCityId(self,arg1);
  if (pvVar2 != (void *)0x0) {
    value3 = Array_GetStride60(this_00,*(int *)((intptr_t)pvVar2 + 0x30));
  }
  fVar4 = BuildingValue_Compute((intptr_t)self,this_00,value3);
  return fVar4;
}
