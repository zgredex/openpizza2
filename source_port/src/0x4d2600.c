// Game_UpdateObjectMapMarker: ported from Pizza Connection 2 at 0x4d2600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2600
#include "pc2_port.h"

void __fastcall Game_UpdateObjectMapMarker(int arg1)

{
  char cVar1;
  uint32_t *self;
  void *pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  char *cptr7;
  char *cptr8;
  int64_t lvalue9;
  int64_t lvalue10;
  uint32_t *uptr11;
  int local_12c;
  void *local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  double local_110;
  double local_108;
  char local_100 [256];
  
  pvVar2 = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)DAT_0057c670 + 0x2dac),(int *)0x0);
  if (pvVar2 != (void *)0x0) {
    value6 = *(int *)(arg1 + 4);
    if (*(int *)(arg1 + 0x54) == -1) {
      value6 = -1;
    }
    value5 = 0;
    local_128 = pvVar2;
    if (*(int *)(arg1 + 8) != -1) {
      local_124 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 8));
      value5 = Game_FindCityIndex(local_124);
    }
    if (value6 == 0x1a) {
      value6 = *(int *)(arg1 + 0x30);
    }
    switch(value6) {
    case 0xf:
      break;
    case 0x10:
      value5 = value5 + 8;
      break;
    case 0x11:
      value5 = 0x1a;
      break;
    default:
      value5 = -1;
      break;
    case 0x17:
      value5 = 0x18;
      break;
    case 0x19:
      value5 = 0x19;
      break;
    case 0x1c:
      value5 = value5 + 0x10;
    }
    value6 = Array_GetRecordByKeyPtr(pvVar2,*(int *)(arg1 + 0x54));
    if (value6 != 0) {
      UI_RemoveObject(pvVar2,*(int *)(arg1 + 0x54));
    }
    if (value5 != -1) {
      value6 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x28),(int *)0x0);
      UI_GetViewRect(*(void **)(value6 + 0xfa8),&local_120);
      local_108 = 128.0 / (double)(local_118 - local_120);
      local_110 = 128.0 / (double)(local_114 - local_11c);
      local_12c = Game_GetObjectCenterY(arg1);
      local_12c = local_12c - local_120;
      Game_GetObjectBottom(arg1);
      lvalue9 = __ftol();
      self = *(uint32_t **)((intptr_t)DAT_0057c670 + 0xa4);
      uptr11 = self;
      local_12c = (intptr_t)lvalue9;
      lvalue10 = __ftol();
      pvVar2 = local_128;
      value6 = MovieWindow_CreateForScreen
                        (local_128,*(int *)(arg1 + 0x54),(intptr_t)lvalue9,(intptr_t)lvalue10,uptr11);
      if (value6 != 0) {
        UI_GetButtonContext(pvVar2,*(int *)(arg1 + 0x54),&local_12c);
        Array_SetField14ByKey(pvVar2,*(int *)(arg1 + 0x54),1);
        Record_SetIndex48(self,local_12c,value5);
        value6 = *(int *)(arg1 + 4);
        if (value6 == 0xf) {
          value6 = IDMap_Lookup((void *)(local_124 + 0x148),*(int *)(arg1 + 0x2c),(int *)0x0);
          if (value6 == 0) {
            cptr7 = s_Error_0056311c;
          }
          else {
            cptr7 = (char *)(value6 + 4);
          }
          uvalue3 = 0xffffffff;
          do {
            cptr8 = cptr7;
            if (uvalue3 == 0) break;
            uvalue3 = uvalue3 - 1;
            cptr8 = cptr7 + 1;
            cVar1 = *cptr7;
            cptr7 = cptr8;
          } while (cVar1 != '\0');
          uvalue3 = ~uvalue3;
          cptr7 = cptr8 + -uvalue3;
          cptr8 = local_100;
          for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
            *(uint32_t *)cptr8 = *(uint32_t *)cptr7;
            cptr7 = cptr7 + 4;
            cptr8 = cptr8 + 4;
          }
          for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
            *cptr8 = *cptr7;
            cptr7 = cptr7 + 1;
            cptr8 = cptr8 + 1;
          }
          pvVar2 = local_128;
        }
        else if (value6 == 0x1a) {
          String_Format(local_100,(uint8_t *)s__s___s__0056c954,
                        *(uint32_t *)(&DAT_005840d4 + *(int *)(arg1 + 0x30) * 4));
        }
        else {
          String_Format(local_100,&DAT_005630d0,*(uint32_t *)(&DAT_005840d4 + value6 * 4));
        }
        UI_SetObjectTextByKey(pvVar2,*(int *)(arg1 + 0x54),local_100);
      }
    }
  }
  return;
}
