// Company_OpenBranchInHomeCity: ported from Pizza Connection 2 at 0x4fc290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc290
#include "pc2_port.h"


uint32_t __thiscall Company_OpenBranchInHomeCity(void *self,int arg1)

{
  void *this_00;
  uint32_t uvalue1;
  int value2;
  void *this_01;
  uint8_t *this_02;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a18b;
  local_c = ExceptionList;
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  ExceptionList = &local_c;
  uvalue1 = Game_SelectLeastUsedCategory(this_00,2);
  if (uvalue1 == 0xffffffff) {
    ExceptionList = local_c;
    return 1;
  }
  value3 = *(int *)((intptr_t)this_00 + 0x15c) + 0x10;
  if (0x14 < value3) {
    value3 = 0x14;
  }
  value2 = Game_CountActiveCompanies((intptr_t)this_00);
  if (value3 <= value2) {
    ExceptionList = local_c;
    return 1;
  }
  this_01 = operator_new(0x330);
  local_4 = 0;
  if (this_01 == (void *)0x0) {
    this_02 = (uint8_t *)0x0;
  }
  else {
    this_02 = Recipe_CreateGenerated
                        (this_01,*(int *)((intptr_t)this_00 + 0x48),uvalue1,2,
                         *(float *)((intptr_t)DAT_0057c670 + 0x2f4),-1);
  }
  local_4 = 0xffffffff;
  value3 = Game_FindPlayerSlot(DAT_0057c670,(intptr_t)this_00);
  Company_GenerateNameFromTopProduct(this_02,value3);
  *(uint32_t *)(this_02 + 0x308) = uvalue1;
  List_Add((void *)((intptr_t)this_00 + 0x110),this_02);
  Game_CanAffordWithCurrency(this_00,9,500.0,'\0',0xffffffff);
  ExceptionList = local_c;
  return 4;
}
