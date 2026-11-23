// Branch_SpawnWalkInCustomer: ported from Pizza Connection 2 at 0x477190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477190
#include "pc2_port.h"


void __fastcall Branch_SpawnWalkInCustomer(void *arg1)

{
  short svalue1;
  uint8_t uvalue2;
  uint32_t extraout_var;
  int value3;
  int value4;
  void *self;
  uint32_t uvalue5;
  int value6;
  int *ptr7;
  uint8_t unaff_BP;
  uint32_t unaff_ESI;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Spawns a random walk-in customer during branch opening hours. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f0b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uvalue2 = Game_GetHourlyValue(arg1,0);
  if (CONCAT31(extraout_var,uvalue2) != 0) {
    value3 = Game_FindRecordByTripleKey(DAT_0057c670,0xb,4,3,&local_24);
    value4 = AI_ComputePath(1,0,0,unaff_ESI,unaff_BP);
    if (value4 != 0) {
      self = operator_new(0x24);
      local_4 = 0;
      local_20 = self;
      if (self == (void *)0x0) {
        value6 = 0;
      }
      else {
        uvalue5 = Random_RangeFast(0,7);
        value6 = ConstructionOrder_Construct(self,local_24,uvalue5);
      }
      local_4 = 0xffffffff;
      Map_ScreenToGridCell
                (*(void **)((intptr_t)arg1 + 0x14e0),*(int *)(value4 + 0xc),*(int *)(value4 + 0x10),
                 &local_30,&local_34,(int *)0x1);
      *(uint32_t *)((intptr_t)arg1 + 0x1718) = 0;
      List_Add((void *)((intptr_t)arg1 + 0x19e0),value6);
      *(int *)(value6 + 0x18) = local_30;
      *(int *)(value6 + 0x1c) = local_34;
      *(int *)(value6 + 0x20) =
           *(int *)(*(int *)((intptr_t)arg1 + 0x14e0) + 0x1c) * local_34 + local_30;
      ptr7 = (int *)Grid_GetCell(*(void **)((intptr_t)arg1 + 0x14e0),local_30,local_34);
      svalue1 = *(short *)(value3 + (*(int *)(value6 + 8) + 10) * 0xc);
      CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
      Map_SetTileFieldWithDefault(*(void **)((intptr_t)arg1 + 0x14e0),(intptr_t)ptr7,(intptr_t)svalue1,1);
      UI_ComputeCenteredRect(*(void **)((intptr_t)arg1 + 0x14e0),ptr7,&local_2c,&local_28);
      local_2c = local_2c - *(int *)(*(int *)((intptr_t)arg1 + 0x14e0) + 0x24);
      local_28 = local_28 - *(int *)(*(int *)((intptr_t)arg1 + 0x14e0) + 0x28);
      local_1c = local_2c - 0x10;
      local_18 = local_28 + -8;
      local_10 = local_28 + 8;
      local_14 = local_2c + 0x10;
      Gfx_BlitRectList(DAT_0058072c,&local_1c);
      CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
    }
  }
  ExceptionList = local_c;
  return;
}
