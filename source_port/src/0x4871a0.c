// Game_CompleteObjectTransfer: ported from Pizza Connection 2 at 0x4871a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4871a0
#include "pc2_port.h"

void __thiscall Game_CompleteObjectTransfer(void *self,uint32_t *arg1)

{
  void *this_00;
  void *this_01;
  void *this_02;
  int value1;
  int value2;
  
                    /* Completes an object ownership transfer and settles its orders. */
  this_01 = (void *)Game_GetPlayerBySlot(self,arg1[9]);
  this_02 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),arg1[10],(int *)0x0);
  value1 = Get_Field2C((intptr_t)arg1);
  this_00 = (void *)arg1[0xd];
  value2 = *(int *)((intptr_t)this_00 + 0x48);
  if ((-1 < value2) && (value2 < 4)) {
    value2 = *(int *)(&DAT_00568188 + value2 * 4);
  }
  Game_AcquireStateLock(self,1);
  Storage_SettlePendingOrders((intptr_t)arg1);
  Player_RemoveObjectReference(this_01,(intptr_t)arg1);
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  MapObject_SetTypeAndSprite(this_00,value1 + 0x1d,value2 + 0x840 + value1 * 4);
  Game_PlaceObjectInPlayerCity(this_02,this_00,-1);
  *(uint32_t *)((intptr_t)this_00 + 0x2c) = 0xffffffff;
  *(uint32_t *)((intptr_t)this_00 + 0x4c) = 1;
  *(uint32_t *)(*(int *)((intptr_t)this_02 + 0xfa8) + 0xf4) = 1;
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  if (((*(void **)((intptr_t)self + 0x218) == this_00) && (*(int *)((intptr_t)self + 0x290) == 1)) &&
     (*(void **)((intptr_t)self + 0x25c) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)((intptr_t)self + 0x25c),-0x18629,0x23,0);
  }
  if (arg1 != (uint32_t *)0x0) {
    (**(code **)*arg1)(1);
  }
  Window_UnlockState((intptr_t)self);
  return;
}
