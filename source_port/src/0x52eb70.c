// Dialog_ConstructWithSprite: ported from Pizza Connection 2 at 0x52eb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52eb70
#include "pc2_port.h"


uint32_t * __thiscall
Dialog_ConstructWithSprite
          (void *self,void *arg1,void *arg2,char *arg3,uint32_t arg4,int arg5,
          int arg6,uint32_t arg7)

{
  char cVar1;
  int value2;
  char *cptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  char *cptr6;
  int local_18;
  uint32_t local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a9dc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = self;
  Array_Construct((void *)((intptr_t)self + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x2a8),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((intptr_t)self + 0x28),arg5,arg6,0,0);
  Dialog_InitBase(self,arg2,arg1,arg7);
  value2 = Window_LoadSpriteCached
                    (arg1,arg3,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0x54));
  if (value2 == 0) {
    local_14 = 0x140;
    local_18 = 200;
    *(uint32_t *)((intptr_t)self + 0x94) = 0;
    *(uint8_t *)((intptr_t)self + 0x54) = 0;
  }
  else {
    Sprite_GetSize(*(void **)((intptr_t)self + 0x94),(int *)&local_14,&local_18);
  }
  UI_SetWindowBounds(self,arg5,arg6,local_14,local_18);
  uvalue4 = 0xffffffff;
  cptr3 = arg3;
  do {
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cVar1 = *cptr3;
    cptr3 = cptr3 + 1;
  } while (cVar1 != '\0');
  cptr3 = operator_new(~uvalue4);
  uvalue4 = 0xffffffff;
  *(char **)((intptr_t)self + 0xf8) = cptr3;
  do {
    cptr6 = arg3;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr6 = arg3 + 1;
    cVar1 = *arg3;
    arg3 = cptr6;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr6 = cptr6 + -uvalue4;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr3 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
    cptr3 = cptr3 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr3 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr3 = cptr3 + 1;
  }
  ExceptionList = local_c;
  return self;
}
