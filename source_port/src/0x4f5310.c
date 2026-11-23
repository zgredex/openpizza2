// AI_ChooseWalkTarget: ported from Pizza Connection 2 at 0x4f5310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5310
#include "pc2_port.h"


int __thiscall
AI_ChooseWalkTarget(void *self,int arg1,void *arg2,uint32_t *arg3,uint32_t *arg4)

{
  int *ptr1;
  uint8_t flag2;
  void *this_00;
  int value3;
  int value4;
  uint32_t *this_01;
  uint32_t uvalue5;
  int value6;
  int value7;
  uint32_t *uptr8;
  int local_834;
  int local_830;
  int local_82c;
  int local_828;
  int local_824;
  int local_820;
  int local_81c;
  uint32_t local_818 [5];
  int local_804;
  uint32_t local_7fc [508];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a08b;
  pvStack_c = ExceptionList;
  value7 = 0;
  ExceptionList = &pvStack_c;
  List_Construct(local_818,0);
  local_4 = 0;
  local_830 = 0;
  local_7fc[0] = 2;
  ptr1 = *(int **)(arg1 + 200);
  local_7fc[1] = 3;
  local_7fc[2] = 0;
  local_7fc[3] = 1;
  local_7fc[4] = 6;
  local_7fc[5] = 7;
  local_7fc[6] = 4;
  local_7fc[7] = 5;
  local_834 = 200000;
  if (ptr1 == (int *)0x0) {
    value6 = -1;
    this_00 = (void *)0x0;
  }
  else {
    value6 = *ptr1;
    this_00 = (void *)ptr1[0x16];
  }
  Record_GetTwoFloats48(this_00,value6,&local_82c,&local_828);
  local_828 = local_828 + *(int *)((intptr_t)self + 0xfc);
  local_82c = local_82c + *(int *)((intptr_t)self + 0xf8);
  if (0 < *(int *)((intptr_t)arg2 + 0x170c)) {
    do {
      value6 = IDMap_Lookup((void *)((intptr_t)arg2 + 0x16f8),value7,(int *)0x0);
      if ((((value6 != 0) && (flag2 = Game_GetPlayerByte8(value6), flag2 != 0)) && (flag2 < 7)) &&
         (0 < *(int *)(value6 + 0xc))) {
        UI_ComputeCenteredRect
                  (self,(int *)(*(int *)((intptr_t)self + 0x4c) + *(int *)(value6 + 0x20) * 0xc),
                   &local_81c,&local_820);
        value3 = Distance_Manhattan3(local_82c,local_828,local_81c,local_820);
        if ((value3 < local_834) &&
           (value4 = Game_HasBuildingWithSameType(arg2,value6,arg1), value4 == 0)) {
          local_834 = value3;
          local_830 = value6;
        }
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)((intptr_t)arg2 + 0x170c));
    if (local_830 != 0) {
      *arg3 = *(uint32_t *)(local_830 + 0x20);
      List_Node_Reset((intptr_t)local_818);
      this_01 = Grid_CollectFootprintCells(self,local_830);
      local_830 = 0;
      if (0 < (intptr_t)this_01[5]) {
        do {
          value7 = IDMap_Lookup(this_01,local_830,(int *)0x0);
          value6 = 0;
          uptr8 = local_7fc;
          do {
            value3 = Grid_GetNeighborCell(self,value7,value6);
            if ((*(int *)(*(int *)(value3 + 8) + 0x28) != 0) &&
               (*(short *)(*(int *)(value3 + 8) + 0x24) != -1)) {
              local_824 = List_Add(local_818,value3);
              IDMap_Update(local_818,&local_824);
              local_7fc[local_824 + 8] = *uptr8;
            }
            value6 = value6 + 1;
            uptr8 = uptr8 + 1;
          } while (value6 < 8);
          local_830 = local_830 + 1;
        } while (local_830 < (intptr_t)this_01[5]);
      }
      if (this_01 != (uint32_t *)0x0) {
        (**(code **)*this_01)(1);
      }
      if (0 < local_804) {
        uvalue5 = Random_RangeFast(0,local_804 - 1);
        value7 = IDMap_Lookup(local_818,uvalue5,(int *)0x0);
        value7 = Array_GetRecord28(self,1,(intptr_t)*(short *)(*(int *)(value7 + 8) + 0x24));
        local_4 = 0xffffffff;
        *arg4 = local_7fc[uvalue5 + 8];
        List_Node_Destroy(local_818);
        ExceptionList = pvStack_c;
        return value7;
      }
    }
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(local_818);
  ExceptionList = pvStack_c;
  return 0;
}
