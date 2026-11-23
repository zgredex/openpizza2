// Dialog_ConstructWithPicture: ported from Pizza Connection 2 at 0x52eca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52eca0
#include "pc2_port.h"

uint32_t * __thiscall
Dialog_ConstructWithPicture
          (void *self,uint32_t arg1,void *arg2,char *arg3,void *arg4,
          uint32_t arg5)

{
  char cVar1;
  void *this_00;
  uint32_t *this_01;
  char *cptr2;
  uint32_t uvalue3;
  int value4;
  char *cptr5;
  uint32_t uvalue6;
  int local_14;
  void *local_10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa17;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_10 = self;
  Array_Construct((void *)((intptr_t)self + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x2a8),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  *(uint8_t ***)self = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((intptr_t)self + 0x28),0,0,0,0);
  Dialog_InitBase(self,arg2,arg1,arg5);
  this_00 = operator_new(0x11c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  if (this_00 == (void *)0x0) {
    this_01 = (uint32_t *)0x0;
  }
  else {
    this_01 = FullscreenImage_Load(this_00,arg3,arg2,arg4,&local_14,(uint8_t *)0x0);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint32_t **)((intptr_t)self + 0x138) = this_01;
  if (local_14 == 0) {
    uvalue6 = this_01[1];
    value4 = this_01[2];
    Sprite_ConvertTo16Bit(this_01,(intptr_t)arg2,1,1);
  }
  else {
    DebugConsole_Errorf(arg1,1,(uint8_t *)s_Unable_to_load_requester_backgro_0057441c,arg3);
    uvalue6 = 0x140;
    value4 = 200;
    if (*(uint32_t **)((intptr_t)self + 0x138) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)self + 0x138))(1);
    }
    *(uint32_t *)((intptr_t)self + 0x138) = 0;
  }
  UI_SetWindowBounds(self,0,0,uvalue6,value4);
  uvalue6 = 0xffffffff;
  cptr2 = arg3;
  do {
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cVar1 = *cptr2;
    cptr2 = cptr2 + 1;
  } while (cVar1 != '\0');
  cptr2 = operator_new(~uvalue6);
  uvalue6 = 0xffffffff;
  *(char **)((intptr_t)self + 0xf8) = cptr2;
  do {
    cptr5 = arg3;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr5 = arg3 + 1;
    cVar1 = *arg3;
    arg3 = cptr5;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  cptr5 = cptr5 + -uvalue6;
  for (uvalue3 = uvalue6 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr2 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr2 = cptr2 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *cptr2 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr2 = cptr2 + 1;
  }
  ExceptionList = pvStack_c;
  return self;
}
