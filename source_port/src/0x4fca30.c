// AI_LiquidateBankruptCompany: ported from Pizza Connection 2 at 0x4fca30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fca30
#include "pc2_port.h"

void __thiscall AI_LiquidateBankruptCompany(void *self,void *arg1)

{
  DWORD DVar1;
  int value2;
  uint32_t *uptr3;
  void *pvVar4;
  int value5;
  int value6;
  bool flag7;
  int value8;
  
                    /* Liquidates a bankrupt AI company and dissolves it. */
  value8 = *(int *)((intptr_t)arg1 + 0x48);
  value2 = *(int *)((intptr_t)arg1 + 0x4c);
  *(uint32_t *)((intptr_t)self + value2 * 0x168 + 0x198) = 1;
  DVar1 = GetCurrentThreadId();
  if (DVar1 == *(DWORD *)((intptr_t)self + 0x10)) {
    uptr3 = (uint32_t *)((intptr_t)self + value2 * 0x168 + 0x74);
    value6 = 10;
    do {
      uptr3[3] = 0;
      *uptr3 = 0xffffffff;
      uptr3 = uptr3 + 4;
      value6 = value6 + -1;
    } while (value6 != 0);
    flag7 = *(int *)((intptr_t)self + value2 * 0x168 + 300) != 0x18;
    *(uint32_t *)((intptr_t)self + value2 * 0x168 + 300) = 0x18;
  }
  else {
    value6 = *(int *)((intptr_t)self + 0xc);
    if (value6 == 0) {
      Thread_IsOwner((intptr_t)self);
    }
    uptr3 = (uint32_t *)((intptr_t)self + value2 * 0x168 + 0x74);
    value5 = 10;
    do {
      uptr3[3] = 0;
      *uptr3 = 0xffffffff;
      uptr3 = uptr3 + 4;
      value5 = value5 + -1;
    } while (value5 != 0);
    flag7 = *(int *)((intptr_t)self + value2 * 0x168 + 300) != 0x18;
    *(uint32_t *)((intptr_t)self + value2 * 0x168 + 300) = 0x18;
    if (value6 == 0) {
      Thread_Init((intptr_t)self);
    }
  }
  if (flag7) {
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value8 == value2) {
      value2 = 5;
      value8 = 0x2b;
    }
    else {
      value2 = 3;
      value8 = 0x31;
    }
    UI_Briefing_Printf((intptr_t)DAT_0057c670,value8,value2,-1,-1,0,DAT_00582dcc,DAT_00581fcc,
                       (intptr_t)arg1 + 8);
  }
  value8 = *(int *)((intptr_t)arg1 + 0x194) + -1;
  if (-1 < value8) {
    do {
      uptr3 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x180),value8,(int *)0x0);
      if (uptr3 != (uint32_t *)0x0) {
        Game_CompleteObjectTransfer(DAT_0057c670,uptr3);
      }
      value8 = value8 + -1;
    } while (-1 < value8);
  }
  value8 = *(int *)((intptr_t)arg1 + 0x15c) + -1;
  if (-1 < value8) {
    do {
      pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x148),value8,(int *)0x0);
      if (pvVar4 != (void *)0x0) {
        UI_ShiftRowData(self,pvVar4,1);
      }
      value8 = value8 + -1;
    } while (-1 < value8);
  }
  Company_Dissolve(arg1,0);
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x10c) = 0;
  if (arg1 != *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
    pvVar4 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
    Array_SearchSet(pvVar4,0x13);
    Array_SearchSet(pvVar4,0x19);
  }
  return;
}
