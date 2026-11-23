// Company_GenerateStartingRecipes: ported from Pizza Connection 2 at 0x4dd8f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd8f0
#include "pc2_port.h"


void __fastcall Company_GenerateStartingRecipes(void *arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  void *pvVar4;
  uint32_t uvalue5;
  uint8_t *bptr6;
  void *pvVar7;
  int value8;
  float fVar9;
  int value10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Gives a company its three starter recipes. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559331;
  local_c = ExceptionList;
  uvalue1 = *(uint32_t *)((intptr_t)arg1 + 0x108);
  uvalue2 = *(uint32_t *)((intptr_t)arg1 + 0x10c);
  ExceptionList = &local_c;
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x10c) = 0x412e8480;
  pvVar4 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  Company_PlaceScenarioBranches(pvVar4,(intptr_t)arg1);
  *(uint32_t *)((intptr_t)arg1 + 0x108) = uvalue1;
  *(uint32_t *)((intptr_t)arg1 + 0x10c) = uvalue2;
  pvVar4 = operator_new(0x330);
  local_4 = 0;
  if (pvVar4 == (void *)0x0) {
    bptr6 = (uint8_t *)0x0;
  }
  else {
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    value10 = 1;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    value8 = 2;
    uvalue5 = Random_RangeFast(0,7);
    bptr6 = Recipe_CreateGenerated(pvVar4,value3,uvalue5,value8,fVar9,value10);
  }
  pvVar4 = (void *)((intptr_t)arg1 + 0x110);
  local_4 = 0xffffffff;
  List_Add(pvVar4,bptr6);
  Recipe_SetOnMenu(arg1,(intptr_t)bptr6,1);
  pvVar7 = operator_new(0x330);
  local_4 = 1;
  if (pvVar7 == (void *)0x0) {
    bptr6 = (uint8_t *)0x0;
  }
  else {
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    value10 = 2;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    value8 = 2;
    uvalue5 = Random_RangeFast(0,7);
    bptr6 = Recipe_CreateGenerated(pvVar7,value3,uvalue5,value8,fVar9,value10);
  }
  local_4 = 0xffffffff;
  List_Add(pvVar4,bptr6);
  Recipe_SetOnMenu(arg1,(intptr_t)bptr6,1);
  pvVar7 = operator_new(0x330);
  local_4 = 2;
  if (pvVar7 == (void *)0x0) {
    bptr6 = (uint8_t *)0x0;
  }
  else {
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    value10 = 3;
    fVar9 = *(float *)(DAT_0057c670 + 0x2f4);
    value8 = 2;
    uvalue5 = Random_RangeFast(0,7);
    bptr6 = Recipe_CreateGenerated(pvVar7,value3,uvalue5,value8,fVar9,value10);
  }
  local_4 = 0xffffffff;
  List_Add(pvVar4,bptr6);
  Recipe_SetOnMenu(arg1,(intptr_t)bptr6,1);
  ExceptionList = local_c;
  return;
}
