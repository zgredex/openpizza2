// CompanyOverview_BuildCompanyList: ported from Pizza Connection 2 at 0x4b4280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b4280
#include "pc2_port.h"

void __thiscall CompanyOverview_BuildCompanyList(void *self,void *arg1)

{
  uint32_t *uptr1;
  void *pvVar2;
  int value3;
  int value4;
  int value5;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_005589bb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_0057d6a0 != (LPVOID)0x0) {
    ExceptionList = &pvStack_c;
    Mem_Free(DAT_0057d6a0);
    DAT_0057d6a0 = (LPVOID)0x0;
  }
  if (DAT_0057d6a4 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057d6a4)(1,self);
    DAT_0057d6a4 = (uint32_t *)0x0;
  }
  pvVar2 = operator_new(0x1c);
  uStack_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057d6a4 = (uint32_t *)0x0;
  }
  else {
    DAT_0057d6a4 = List_Construct(pvVar2,0);
  }
  uStack_4 = 0xffffffff;
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value3 = Game_CountActiveCompanies((intptr_t)pvVar2);
  value5 = 0;
  if (0 < value3) {
    do {
      value4 = Game_GetActiveCompanyById(pvVar2,value5);
      List_Add(DAT_0057d6a4,value4);
      value5 = value5 + 1;
    } while (value5 < value3);
  }
  if (DAT_0056a7d4 != -1) {
    value3 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),DAT_0056a7d4,(int *)0x0);
    if ((value3 != 0) && (*(int *)(value3 + 0x14dc) != 0)) {
      List_Add(DAT_0057d6a4,*(int *)(value3 + 0x14dc));
    }
  }
  uptr1 = (uint32_t *)DAT_0057d6a4[5];
  if (0 < (intptr_t)uptr1) {
    DAT_0057d6a0 = operator_new((intptr_t)uptr1 * 4);
  }
  CompanyOverview_SortCompanyIndices(uptr1);
  value3 = 0;
  do {
    if (value3 < (intptr_t)uptr1) {
      Window_GadgetNotify_Button_SetState
                (arg1,value3 + 0x1f41,
                 (uint32_t)(*(int *)(&DAT_0056a760 + *(int *)((intptr_t)DAT_0057d6a0 + value3 * 4) * 4) == 1))
      ;
    }
    value3 = value3 + 1;
  } while (value3 < 8);
  ExceptionList = pvStack_c;
  return;
}
