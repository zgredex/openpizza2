// Player_BuildStorage: ported from Pizza Connection 2 at 0x4f7710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7710
#include "pc2_port.h"


int Player_BuildStorage(int arg1,void *arg2,int arg3,int arg4,int arg5)

{
  void *self;
  void *this_00;
  int value1;
  int value2;
  uint8_t *uptr3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  char *cptr6;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates a storage building for a player. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a0eb;
  local_c = ExceptionList;
  uptr4 = (uint32_t *)0x0;
  ExceptionList = &local_c;
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),arg1,(int *)0x0);
  local_10 = (void *)Game_GetPlayerBySlot(DAT_0057c670,arg3);
  Game_AcquireStateLock(DAT_0057c670,0);
  value1 = *(int *)((intptr_t)arg2 + 0x48);
  if ((-1 < value1) && (value1 < 4)) {
    value1 = *(int *)(&DAT_00568188 + value1 * 4);
  }
  if (arg5 == 0) {
    uvalue5 = 3;
  }
  else {
    uvalue5 = 6;
  }
  MapObject_SpawnByKind(self,arg2,uvalue5,arg3,(void *)0x10,value1 + 0x834 + arg4 * 4);
  *(uint32_t *)(*(int *)((intptr_t)self + 0xfa8) + 0xf4) = 1;
  *(uint32_t *)((intptr_t)arg2 + 0x4c) = 0;
  this_00 = operator_new(0x150);
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    uptr4 = Storage_Construct(this_00,(void *)0x0);
  }
  local_4 = 0xffffffff;
  value1 = Game_GetPlayerBySlot(DAT_0057c670,arg3);
  value2 = List_Add((void *)(value1 + 0x180),uptr4);
  *(int *)((intptr_t)arg2 + 0x2c) = value2;
  value1 = (intptr_t)self + 4;
  cptr6 = s__s__d_00568964;
  uptr3 = (uint8_t *)Get_Subobject4((intptr_t)uptr4);
  String_Format(uptr3,(uint8_t *)cptr6,value1);
  uptr4[9] = arg3;
  uptr4[10] = arg1;
  uptr4[0xb] = arg4;
  uptr4[0xd] = arg2;
  *(int *)((intptr_t)self + 0xdc4) = *(int *)((intptr_t)self + 0xdc4) + 1;
  if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18689,0x23,1);
  }
  Window_UnlockState((intptr_t)DAT_0057c670);
  Game_ComputeTradeOffers(self,(intptr_t)arg2,3,&local_18,&local_14,arg3,(int *)0x0);
  if (arg5 == 0) {
    *(uint8_t *)(uptr4 + 0xf) = 1;
    uptr4[0x10] = 0;
    Game_CanAffordWithCurrency(local_10,2,(float)local_14,'\0',0xffffffff);
  }
  else {
    *(uint8_t *)(uptr4 + 0xf) = 0;
    uptr4[0x10] = local_18;
    Storage_ChargePurchaseCost(uptr4);
  }
  ExceptionList = local_c;
  return value2;
}
