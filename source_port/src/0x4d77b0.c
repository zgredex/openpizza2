// MapObject_SpawnByKind: ported from Pizza Connection 2 at 0x4d77b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d77b0
#include "pc2_port.h"

uint32_t __thiscall
MapObject_SpawnByKind
          (void *self,void *arg1,uint32_t arg2,int arg3,void *arg4,int arg5)

{
  uint32_t *uptr1;
  void *pvVar2;
  void *this_00;
  int value3;
  int value4;
  uint32_t uvalue5;
  int value6;
  uint32_t local_c;
  
                    /* Spawns or advances a map object by spawn kind. */
  this_00 = arg1;
  local_c = 0;
  value3 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x28),(int *)0x0);
  pvVar2 = *(void **)(value3 + 0xfa8);
  switch(arg2) {
  case 1:
    uptr1 = (uint32_t *)((intptr_t)arg1 + 4);
    arg1 = (void *)0xf;
    switch(*uptr1) {
    case 0xf:
      value4 = Building_GetSpriteVariant((intptr_t)this_00);
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      *(uint32_t *)((intptr_t)this_00 + 0x38) = 2;
      if ((value3 < 0) || (3 < value3)) {
        value6 = value3;
      }
      else {
        value6 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value6 + 0x810 + value4 * 4;
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      *(uint32_t *)((intptr_t)this_00 + 0x30) = 0xf;
      *(int *)((intptr_t)this_00 + 0x34) = value3 + 0x85c + value4 * 4;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    default:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      arg1 = (void *)0x1a;
      if ((value3 < 0) || (3 < value3)) {
        value4 = value3;
      }
      else {
        value4 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      if (arg5 == -1) {
        if ((-1 < value3) && (value3 < 4)) {
          value3 = *(int *)(&DAT_00568188 + value3 * 4);
        }
        arg5 = value3 + 0x858;
      }
      Building_EvictOccupants(this_00);
      *(uint32_t *)((intptr_t)this_00 + 0x38) = 2;
      *(uint32_t *)((intptr_t)this_00 + 0x50) = 0;
      *(uint32_t *)((intptr_t)this_00 + 0x4c) = 0;
      *(uint32_t *)((intptr_t)this_00 + 0x30) = 0xf;
      *(int *)((intptr_t)this_00 + 0x34) = arg5;
      arg5 = value4 + 0x80c;
      goto LAB_004d78bf;
    case 0x14:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x80c;
      local_c = 0;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    case 0x15:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x810;
      local_c = 1;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    case 0x16:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x814;
      local_c = 2;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
    }
    goto LAB_004d78d0;
  case 2:
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    value3 = value3 + 0x818;
    Building_EvictOccupants(arg1);
    value4 = *(int *)((intptr_t)arg1 + 0x48);
    *(uint32_t *)((intptr_t)arg1 + 0x50) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x38) = 5;
    if ((-1 < value4) && (value4 < 4)) {
      value4 = *(int *)(&DAT_00568188 + value4 * 4);
    }
    *(uint32_t *)((intptr_t)arg1 + 0x30) = 0x11;
    arg5 = value4 + 0x975;
    goto LAB_004d78bc;
  case 3:
    uptr1 = (uint32_t *)((intptr_t)arg1 + 4);
    arg1 = (void *)0x10;
    switch(*uptr1) {
    case 0x10:
      value4 = Building_GetSpriteVariant((intptr_t)this_00);
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      *(uint32_t *)((intptr_t)this_00 + 0x38) = 3;
      if ((value3 < 0) || (3 < value3)) {
        value6 = value3;
      }
      else {
        value6 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value6 + 0x804 + value4 * 4;
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      *(uint32_t *)((intptr_t)this_00 + 0x30) = 0x10;
      *(int *)((intptr_t)this_00 + 0x34) = value3 + 0x838 + value4 * 4;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    default:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      arg1 = (void *)0x1a;
      if ((value3 < 0) || (3 < value3)) {
        value4 = value3;
      }
      else {
        value4 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      if (arg5 == -1) {
        if ((-1 < value3) && (value3 < 4)) {
          value3 = *(int *)(&DAT_00568188 + value3 * 4);
        }
        arg5 = value3 + 0x834;
      }
      Building_EvictOccupants(this_00);
      *(uint32_t *)((intptr_t)this_00 + 0x38) = 3;
      *(uint32_t *)((intptr_t)this_00 + 0x50) = 0;
      *(uint32_t *)((intptr_t)this_00 + 0x4c) = 0;
      *(uint32_t *)((intptr_t)this_00 + 0x30) = 0x10;
      *(int *)((intptr_t)this_00 + 0x34) = arg5;
      arg5 = value4 + 0x800;
      goto LAB_004d78bf;
    case 0x14:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x800;
      local_c = 0;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    case 0x15:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x804;
      local_c = 1;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      break;
    case 0x16:
      value3 = *(int *)((intptr_t)this_00 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      arg5 = value3 + 0x808;
      local_c = 2;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
    }
    goto LAB_004d78d0;
  case 4:
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    arg1 = (void *)0x1a;
    value4 = *(int *)((intptr_t)self + arg3 * 4 + 0xc20);
    if ((value3 < 0) || (3 < value3)) {
      value6 = value3;
    }
    else {
      value6 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    if (value4 == 0) {
      Building_EvictOccupants(this_00);
    }
    *(uint32_t *)((intptr_t)this_00 + 0x38) = 4;
    *(uint32_t *)((intptr_t)this_00 + 0x50) = 0;
    *(uint32_t *)((intptr_t)this_00 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)this_00 + 0x30) = 0x1c;
    *(int *)((intptr_t)this_00 + 0x34) = value3 + 0x81c + value4 * 4;
    arg5 = value6 + 0x7e4 + value4 * 4;
    goto LAB_004d78bf;
  case 5:
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    value3 = value3 + 0x7fc;
    Building_EvictOccupants(arg1);
    uvalue5 = Random_RangeFast(6,10);
    *(uint32_t *)((intptr_t)arg1 + 0x38) = uvalue5;
    *(void **)((intptr_t)arg1 + 0x30) = arg4;
LAB_004d78bc:
    arg1 = (void *)0x1a;
    *(int *)((intptr_t)this_00 + 0x34) = arg5;
    arg5 = value3;
    goto LAB_004d78bf;
  case 6:
    arg1 = arg4;
    value3 = IsSpecialIdRange((intptr_t)this_00);
    if (value3 == 0) {
      Building_EvictOccupants(this_00);
    }
    if (arg4 == (void *)0x11) {
      *(uint32_t *)((intptr_t)this_00 + 0xc) = *(uint32_t *)((intptr_t)self + 0x10c4);
      Player_SetSlotFlag18(self,*(int *)((intptr_t)self + 0x10c4));
      City_UpdateSecurityPatrolFrames(self,(intptr_t)this_00);
      *(int *)((intptr_t)self + 0x10c4) = *(int *)((intptr_t)self + 0x10c4) + 1;
      Game_PlaceObjectInPlayerCity(self,this_00,arg3);
      goto LAB_004d78d0;
    }
    break;
  case 7:
    arg1 = arg4;
    value3 = *(int *)((intptr_t)this_00 + 0x48);
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    arg5 = value3 + 0x864;
    Building_EvictOccupants(this_00);
    break;
  default:
  }
  if (arg1 == (void *)0x1a) {
LAB_004d78bf:
    MapObject_SetCityFromPlayer(this_00,pvVar2,arg3);
  }
  else {
    Game_PlaceObjectInPlayerCity(self,this_00,arg3);
  }
LAB_004d78d0:
  MapObject_SetTypeAndSprite(this_00,(intptr_t)arg1,arg5);
  Map_DrawMinimap(DAT_0057c670);
  *(uint32_t *)((intptr_t)pvVar2 + 0xf4) = 1;
  return local_c;
}
