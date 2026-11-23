// Company_OpenBranchAtSite: ported from Pizza Connection 2 at 0x4fc0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc0f0
#include "pc2_port.h"


uint32_t __thiscall Company_OpenBranchAtSite(void *self,int arg1,void *arg2)

{
  void *this_00;
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  uint8_t *bptr6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a176;
  local_c = ExceptionList;
  bptr6 = (uint8_t *)0x0;
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  if (*(int *)((intptr_t)arg2 + 0x14dc) == 0) {
    ExceptionList = &local_c;
    Thread_SetGlobalFlag(self,1);
    pvVar1 = operator_new(0x330);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      bptr6 = Recipe_CreateGenerated
                         (pvVar1,*(int *)((intptr_t)arg2 + 0x30),5,2,*(float *)((intptr_t)arg2 + 0x34),
                          -1);
    }
    local_4 = 0xffffffff;
    value2 = Game_FindPlayerSlot(DAT_0057c670,(intptr_t)this_00);
    Company_GenerateNameFromTopProduct(bptr6,value2);
    bptr6[0x308] = 5;
    bptr6[0x309] = 0;
    bptr6[0x30a] = 0;
    bptr6[0x30b] = 0;
    Thread_SetGlobalFlag(self,0);
    List_Add((void *)((intptr_t)this_00 + 0x110),bptr6);
    Branch_SetAssignedEmployee(arg2,bptr6);
LAB_004fc276:
    uvalue5 = 4;
  }
  else {
    ExceptionList = &local_c;
    uvalue3 = Game_SelectLeastUsedCategory(this_00,2);
    if (uvalue3 != 0xffffffff) {
      value2 = *(int *)((intptr_t)this_00 + 0x15c) + 0x10;
      if (0x14 < value2) {
        value2 = 0x14;
      }
      value4 = Game_CountActiveCompanies((intptr_t)this_00);
      if (value4 < value2) {
        Thread_SetGlobalFlag(self,1);
        pvVar1 = operator_new(0x330);
        local_4 = 1;
        if (pvVar1 == (void *)0x0) {
          bptr6 = (uint8_t *)0x0;
        }
        else {
          bptr6 = Recipe_CreateGenerated
                             (pvVar1,*(int *)((intptr_t)arg2 + 0x30),uvalue3,2,
                              *(float *)((intptr_t)arg2 + 0x34),-1);
        }
        local_4 = 0xffffffff;
        value2 = Game_FindPlayerSlot(DAT_0057c670,(intptr_t)this_00);
        Company_GenerateNameFromTopProduct(bptr6,value2);
        *(uint32_t *)(bptr6 + 0x308) = uvalue3;
        Thread_SetGlobalFlag(self,0);
        List_Add((void *)((intptr_t)this_00 + 0x110),bptr6);
        Recipe_SetOnMenu(this_00,(intptr_t)bptr6,1);
        goto LAB_004fc276;
      }
    }
    *(uint32_t *)((intptr_t)arg2 + 0x28) = *(uint32_t *)((intptr_t)arg2 + 0x28) & 0xef;
    uvalue5 = 1;
  }
  ExceptionList = local_c;
  return uvalue5;
}
