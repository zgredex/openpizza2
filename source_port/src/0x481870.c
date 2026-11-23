// Game_HandleMapInput: ported from Pizza Connection 2 at 0x481870.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481870
#include "pc2_port.h"

void __thiscall Game_HandleMapInput(void *self,void *arg1,int arg2,int arg3,int *arg4)

{
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  int value6;
  int value7;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Handles map-view zoom, scroll, and selection input. */
  switch(arg3) {
  case 6:
  case 9:
    value4 = *(int *)((intptr_t)self + 0x290);
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    if (value4 == 4) {
      UI_SubtractOrigin(arg1,arg4,arg4 + 1);
      arg3 = 0;
      value4 = -1;
      value2 = Get_FieldF0((intptr_t)arg1);
      arg2 = 0;
      if (value2 < 1) {
        return;
      }
      do {
        value7 = Array_GetPair8(arg1,arg2,&local_8);
        if (local_8 != 99999) {
          UI_GetButtonContext(arg1,local_8,&local_4);
          value3 = Record_GetValue48(*(void **)((intptr_t)self + 0xa4),local_4);
          if ((value3 < 8) &&
             ((value6 = *arg4 - *(int *)(value7 + 0x38),
              value3 = arg4[1] - *(int *)(value7 + 0x3c), value3 = value3 * value3 + value6 * value6,
              value4 == -1 || (value3 < arg3)))) {
            value4 = *(int *)(value7 + 4);
            arg3 = value3;
          }
        }
        arg2 = arg2 + 1;
      } while (arg2 < value2);
      if (value4 == -1) {
        return;
      }
      value7 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      value2 = *(int *)(value7 + 0xfc0);
      value3 = 0;
      arg4 = (int *)0xffffffff;
      if (0 < value2) {
        do {
          value6 = IDMap_Lookup((void *)(value7 + 0xfac),value3,(int *)0x0);
          if ((value6 != 0) && (*(int *)(value6 + 0x54) == value4)) {
            arg4 = *(int **)(value6 + 0x2c);
            value4 = *(int *)(value6 + 8);
            break;
          }
          value3 = value3 + 1;
        } while (value3 < value2);
      }
      if (value3 == value2) {
        return;
      }
      if (arg4 == (int *)0xffffffff) {
        return;
      }
      uvalue5 = Game_GetPlayerSubmapValue(self,value4,(intptr_t)arg4);
      *(uint32_t *)((intptr_t)self + 0x9c) = uvalue5;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
      if (value4 == value2) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
      }
      else {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
      }
      *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      Game_SetViewMode(self,4,0);
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x2d98) = 3;
    if (((value4 == 5) || (value4 == 7)) || (value4 == 6)) {
      Game_SetViewMode(self,1,0);
    }
    UI_SetChildrenField14(self,0);
  case 8:
    if ((*(int *)((intptr_t)self + 0x2d98) == 3) || (arg3 == 6)) {
      local_c = *arg4;
      local_10 = arg4[1];
      value4 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      pvVar1 = *(void **)(value4 + 0xfa8);
      value4 = *(int *)((intptr_t)pvVar1 + 0x2c);
      value2 = *(int *)((intptr_t)pvVar1 + 0x30);
      value3 = *(int *)((intptr_t)pvVar1 + 0x34) + DAT_00571950;
      value7 = *(int *)((intptr_t)pvVar1 + 0x38) + DAT_00571954;
      UI_SubtractOrigin(arg1,&local_c,&local_10);
      value7 = (value7 - value2) * local_10;
      value3 = (value3 - value4) * local_c;
      Map_ScrollToClamped(self,pvVar1,
                          (((intptr_t)(value3 + (value3 >> 0x1f & 0x7fU)) >> 7) - (DAT_00571950 >> 1)) +
                          value4,(((intptr_t)(value7 + (value7 >> 0x1f & 0x7fU)) >> 7) - (DAT_00571954 >> 1)
                                ) + value2);
      return;
    }
    break;
  case 7:
  case 10:
    *(uint32_t *)((intptr_t)self + 0x2d98) = 0;
    UI_SetChildrenField14(self,1);
    break;
  case 0x1b:
    value2 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
    value4 = *(int *)(value2 + 0xfc0);
    value7 = 0;
    if (0 < value4) {
      do {
        value3 = IDMap_Lookup((void *)(value2 + 0xfac),value7,(int *)0x0);
        if ((value3 != 0) && (*(int *)(value3 + 0x54) == arg2)) {
          value6 = *(int *)((intptr_t)self + 0x290);
          *(uint32_t *)((intptr_t)self + 0x21c) = 0;
          *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
          if (value6 == 4) {
            if ((*(int *)(value3 + 0x2c) != -1) && (*(int *)(value3 + 4) == 0xf)) {
              value4 = Game_GetPlayerSubmapValue(self,*(int *)(value3 + 8),*(int *)(value3 + 0x2c));
              *(int *)((intptr_t)self + 0x9c) = value4;
              Sound_SelectCurrentTrack(DAT_0057ba0c);
              value4 = *(int *)(value4 + 0x30);
              value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
              if (value4 == value2) {
                *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
              }
              else {
                *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
              }
              *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
              Game_SetViewMode(self,4,0);
              return;
            }
            *(int *)((intptr_t)self + 0x218) = value3;
            Game_CenterViewOnObject(value3);
            if (*(int *)(value3 + 4) == 0x1c) {
              value4 = *(int *)(value3 + 8);
              value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
              if (value4 == value2) {
                Game_SetViewMode(self,2,1);
                return;
              }
            }
            else if (*(int *)(value3 + 4) == 0x19) {
              Game_SetViewMode(self,3,1);
              return;
            }
            Game_SetViewMode(self,1,1);
            return;
          }
          if (((value6 == 1) || (value6 == 2)) || (value6 == 3)) {
            *(uint32_t *)((intptr_t)self + 0x218) = 0;
            Game_SelectBuilding(value3,0);
            *(int *)((intptr_t)self + 0x218) = value3;
            Game_CenterViewOnObject(value3);
          }
          else {
            *(int *)((intptr_t)self + 0x218) = value3;
            Game_CenterViewOnObject(value3);
            Game_SetViewMode(self,1,1);
          }
        }
        value7 = value7 + 1;
        if (value4 <= value7) {
          return;
        }
      } while( true );
    }
  }
  return;
}
