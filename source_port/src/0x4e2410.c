// BuildingValue_Compute: ported from Pizza Connection 2 at 0x4e2410.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2410
#include "pc2_port.h"


double __thiscall BuildingValue_Compute(int arg1,void *arg2,int arg3)

{
  float fVar1;
  int value2;
  int value3;
  float local_2c;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005594f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  local_2c = 1.5;
  if (arg3 != 0) {
    local_2c = *(float *)(arg3 + 0xc);
    value2 = Array_FindIndexStride60(arg2,arg3);
    Game_CollectAllOwnedObjects(local_28,value2);
    local_2c = ((float)local_14 * *(float *)(arg3 + 8) + 1.0) * local_2c;
    value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if (*(int *)(arg1 + 0x48) == value3) {
      value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(value3 + 0x114) / 100000 + -1 == value2) {
        local_2c = local_2c * 0.5;
      }
      if (*(int *)(value3 + 0x1f8) / 100000 + -1 == value2) {
        local_2c = local_2c * 1.5;
      }
    }
  }
  fVar1 = *(float *)((intptr_t)arg2 + 0x94);
  value3 = Game_GetPlayerCity(arg1);
  value2 = *(int *)(value3 + 0x54);
  value3 = *(int *)(value3 + 0x3c);
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return (double)(fVar1 * local_2c * (1.0 - (float)(value2 + value3) * 0.03));
}
