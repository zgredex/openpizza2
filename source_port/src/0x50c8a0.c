// Object_LinkWithFacingObject: ported from Pizza Connection 2 at 0x50c8a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50c8a0
#include "pc2_port.h"

uint32_t __thiscall Object_LinkWithFacingObject(void *self,void *arg1)

{
  void *this_00;
  void *this_01;
  int value1;
  int value2;
  
  this_00 = *(void **)((intptr_t)arg1 + 0x16f0);
  if ((this_00 != (void *)0x0) && (value2 = 0, 0 < *(int *)((intptr_t)this_00 + 0x8c))) {
    do {
      this_01 = (void *)Game_MapRecordToGlobal(this_00,value2);
      value1 = *(int *)((intptr_t)this_01 + 0x30);
      if ((((value1 == 0x17) || (value1 == 0xd)) &&
          ((*(int *)((intptr_t)this_01 + 0x38) != 0x2d && (*(int *)((intptr_t)this_01 + 0x38) != 0x2e)))) &&
         ((value1 != 0x1d || (*(int *)((intptr_t)this_01 + 0xa4) != 0x1a)))) {
        value1 = MapObject_IsTargetFacingMe(self,arg1,(intptr_t)this_01);
        if (value1 != 0) {
          if ((*(int *)((intptr_t)self + 0x38) != 0x2c) && (*(int *)((intptr_t)self + 0x110) != -1)) {
            value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
            *(int *)(value2 + 0x78) = *(int *)(value2 + 0x78) + 1;
          }
          Object_SetState(self,0x2c);
          *(uint32_t *)((intptr_t)self + 0x8c) = *(uint32_t *)((intptr_t)this_01 + 0x164);
          Object_SetState(this_01,0x2c);
          if (*(int *)((intptr_t)this_01 + 0x30) == 0xd) {
            *(uint32_t *)((intptr_t)this_01 + 0x8c) = *(uint32_t *)((intptr_t)self + 0x164);
          }
          else {
            *(uint32_t *)((intptr_t)this_01 + 0x8c) = *(uint32_t *)((intptr_t)self + 0x164);
          }
          Branch_InitCityObjects(arg1,0x1e);
          return 1;
        }
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)this_00 + 0x8c));
  }
  return 0;
}
