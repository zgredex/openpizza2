// Submenu_SetObjectPicture: ported from Pizza Connection 2 at 0x4bf120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf120
#include "pc2_port.h"

void __cdecl
Submenu_SetObjectPicture(void *arg1,int arg2,int arg3,int arg4,int arg5,int arg6)

{
  char cVar1;
  char *cptr2;
  int value3;
  void *self;
  uint32_t uvalue4;
  uint32_t uvalue5;
  char *cptr6;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  uint8_t local_244 [64];
  void *local_204;
  char local_200 [256];
  char local_100 [256];
  
  switch(*(uint32_t *)(arg6 + 4)) {
  case 5:
    String_Format(local_200,&DAT_005630d0,s_Kletterhaus_0056ac60);
    break;
  default:
    cptr2 = (char *)(DAT_0057c5cc + 0x25 + arg2 * 0x48);
LAB_004bf209:
    uvalue4 = 0xffffffff;
    do {
      cptr6 = cptr2;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr6 = cptr2 + 1;
      cVar1 = *cptr2;
      cptr2 = cptr6;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    cptr2 = cptr6 + -uvalue4;
    cptr6 = local_200;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr6 = *(uint32_t *)cptr2;
      cptr2 = cptr2 + 4;
      cptr6 = cptr6 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr6 = *cptr2;
      cptr2 = cptr2 + 1;
      cptr6 = cptr6 + 1;
    }
    cptr2 = _strchr(local_200,0x2e);
    cptr2[-1] = '\0';
    break;
  case 0xb:
    cptr2 = (char *)(DAT_0057c5cc + 0x25 + arg2 * 0x48);
    if (*(int *)(arg6 + 0x48) != -1) goto LAB_004bf209;
    uvalue4 = 0xffffffff;
    do {
      cptr6 = cptr2;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr6 = cptr2 + 1;
      cVar1 = *cptr2;
      cptr2 = cptr6;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    cptr2 = cptr6 + -uvalue4;
    cptr6 = local_200;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr6 = *(uint32_t *)cptr2;
      cptr2 = cptr2 + 4;
      cptr6 = cptr6 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr6 = *cptr2;
      cptr2 = cptr2 + 1;
      cptr6 = cptr6 + 1;
    }
    cptr2 = _strchr(local_200,0x2e);
    cptr2[-1] = '\0';
    cptr2[-2] = '\0';
    break;
  case 0x18:
    String_Format(local_200,&DAT_005630d0,s_H_STADION_0056ac54);
    break;
  case 0x22:
    String_Format(local_200,&DAT_005630d0,s_H_BAHNHOF_0056ac48);
  }
  if (arg3 == 1) {
    if (-1 < arg5) {
      String_Format(local_100,(uint8_t *)s_buildings_MG__s_d_spr_0056ac00,local_200);
      goto LAB_004bf2c3;
    }
    cptr2 = s_buildings_MG__s_spr_0056abec;
  }
  else {
    if (arg3 != 2) goto LAB_004bf2c3;
    if (-1 < arg5) {
      String_Format(local_100,(uint8_t *)s_buildings_M__s_d_0_spr_0056ac30,local_200);
      goto LAB_004bf2c3;
    }
    cptr2 = s_buildings_M__s_0_spr_0056ac18;
  }
  String_Format(local_100,(uint8_t *)cptr2,local_200);
LAB_004bf2c3:
  value3 = Array_GetRecordField40(arg1,arg4);
  if (value3 == 6) {
    value3 = UI_SetButtonSpriteByName(arg1,arg4,local_100);
    if (value3 == 0) {
      DebugConsole_Printf(DAT_0057c1e0,0xffff,(uint8_t *)s_Not_found___s_0056abdc,local_100);
      return;
    }
  }
  else if (value3 == 7) {
    self = (void *)UI_GetWindowObject(arg1,arg4);
    UI_RealizeSprite((intptr_t)self);
    value3 = Window_LoadSpriteCached
                      (DAT_0057c5e0,local_100,(uint32_t *)0x0,(uint32_t *)local_244);
    if (value3 != 0) {
      UI_GetChildSize(self,&local_24c,&local_250);
      uvalue4 = Object_GetActiveValue((intptr_t)self);
      Sprite_GetSize(local_204,&local_254,&local_248);
      Sprite_Draw(local_204,uvalue4,(uint32_t *)(local_24c - local_254 >> 1),local_250 - local_248 >> 1);
      UI_DecrementRowCounter(DAT_0057c5e0,local_244);
    }
  }
  return;
}
