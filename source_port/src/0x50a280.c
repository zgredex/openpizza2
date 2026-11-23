// Waiter_LoadOrderFromKitchen: ported from Pizza Connection 2 at 0x50a280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a280
#include "pc2_port.h"

void __fastcall Waiter_LoadOrderFromKitchen(void *arg1)

{
  int value1;
  void *pvVar2;
  uint32_t *uptr3;
  void *self;
  void *this_00;
  LPVOID pvVar4;
  double fVar5;
  int value6;
  
                    /* Loads a waiter's tray from the kitchen order. */
  value1 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)((intptr_t)arg1 + 0x50),(int *)0x0);
  value6 = *(int *)((intptr_t)arg1 + 0xfc);
  pvVar2 = (void *)Game_GetPlayerSubmapValue
                             (DAT_0057c670,*(int *)(value1 + 0x81c),*(int *)(value1 + 0x820));
  if (pvVar2 == (void *)0x0) {
    Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
    return;
  }
  Object_SetDestinationAndTarget(arg1,1,*(int *)((intptr_t)pvVar2 + 0x16f0));
  uptr3 = (uint32_t *)RecordMap_Lookup1998(pvVar2,*(int *)((intptr_t)arg1 + 0x88));
  if (uptr3 == (uint32_t *)0x0) {
    return;
  }
  self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar2 + 0x30));
  if ((self == (void *)0x0) ||
     (this_00 = (void *)Game_FindRecordByField34(self,value6), this_00 == (void *)0x0)) {
    *uptr3 = 200000;
    value6 = 0;
    pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)pvVar2 + 0x34),
                                  (int *)0x0);
    fVar5 = BuildingValue_Compute((intptr_t)self,pvVar2,value6);
    uptr3[4] = (float)fVar5;
    uptr3[3] = 0x28;
    uptr3[1] = 600;
    uptr3[2] = 600;
    return;
  }
  pvVar4 = (LPVOID)Storage_ReceivePendingOrder(this_00,*(int *)((intptr_t)pvVar2 + 0x3c));
  if (pvVar4 == (LPVOID)0x0) {
    *uptr3 = 0;
    UI_SetChildState(arg1,10);
    return;
  }
  *uptr3 = 200000;
  uptr3[4] = *(uint32_t *)((intptr_t)pvVar4 + 0x10);
  uptr3[1] = *(uint32_t *)((intptr_t)pvVar4 + 4);
  uptr3[2] = *(uint32_t *)((intptr_t)pvVar4 + 4);
  uptr3[3] = *(uint32_t *)((intptr_t)pvVar4 + 0xc);
  Mem_Free(pvVar4);
  return;
}
