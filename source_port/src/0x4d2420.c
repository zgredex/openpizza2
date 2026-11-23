// MapObject_SetTypeAndSprite: ported from Pizza Connection 2 at 0x4d2420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2420
#include "pc2_port.h"

void __thiscall MapObject_SetTypeAndSprite(void *self,int arg1,int arg2)

{
  int *ptr1;
  void *this_00;
  int value2;
  void *pvVar3;
  int local_20;
  int local_1c;
  uint32_t local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Changes a map object's type, sprite variant, and marker. */
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  this_00 = *(void **)(value2 + 0xfa8);
  if (this_00 != (void *)0x0) {
    if ((*(int *)((intptr_t)self + 4) == 0xf) && (arg1 != 0xf)) {
      value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 8));
      if (value2 != 0) {
        pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                      *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
        Object_SetSignAndLogoVariant(pvVar3,0,(intptr_t)self,value2);
      }
    }
    Map_ClearObjectFlags(self,this_00,0xffffffff);
    *(int *)((intptr_t)self + 0x20) = arg2;
    *(int *)((intptr_t)self + 4) = arg1;
    ptr1 = (int *)(*(int *)((intptr_t)this_00 + 0x4c) + *(int *)((intptr_t)self + 0x24) * 0xc);
    if (ptr1 != (int *)0x0) {
      CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
      Buffer_FreeLockedGlobal(ptr1[2] + 0x10);
      UI_DrawObjectWithBounds(this_00,ptr1,&local_10);
      local_10 = local_10 + *(int *)((intptr_t)this_00 + 0x24);
      local_8 = local_8 + *(int *)((intptr_t)this_00 + 0x24);
      local_c = local_c + *(int *)((intptr_t)this_00 + 0x28);
      local_4 = local_4 + *(int *)((intptr_t)this_00 + 0x28);
      *(int *)(ptr1[2] + 0x10) = arg2;
      List_AppendQuad(this_00,&local_10);
      Map_BuildElementAnimationList(this_00,arg2,ptr1[2] + 0x10);
      if (*(int *)((intptr_t)self + 4) == 0xf) {
        value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 8));
        if (value2 != 0) {
          pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                        *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
          Object_SetSignAndLogoVariant(pvVar3,1,(intptr_t)self,value2);
        }
      }
      pvVar3 = Game_GetLinkedObjectExtent(this_00,(uint32_t)ptr1,&local_14,&local_18);
      UI_AlignSpriteToRect(this_00,ptr1,pvVar3,&local_20,&local_1c);
      local_20 = local_20 + *(int *)((intptr_t)this_00 + 0x24);
      local_1c = local_1c + *(int *)((intptr_t)this_00 + 0x28);
      SetRect((LPRECT)((intptr_t)self + 0x10),local_20,local_1c,local_14 + local_20,local_18 + local_1c);
      CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
    }
    Game_UpdateObjectMapMarker((intptr_t)self);
  }
  return;
}
