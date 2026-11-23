// MovieWindow_Construct: ported from Pizza Connection 2 at 0x52ae20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ae20
#include "pc2_port.h"

uint32_t * __thiscall
MovieWindow_Construct
          (void *self,int arg1,int arg2,int arg3,uint32_t arg4,uint32_t *arg5,
          char *arg6,uint32_t arg7,int arg8)

{
  char cVar1;
  void *this_00;
  void *pvVar2;
  int *ptr3;
  HANDLE pvVar4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  int value7;
  char *cptr8;
  uint32_t uvalue9;
  int value10;
  uint32_t uvalue11;
  char *cptr12;
  uint32_t *uptr13;
  char *cptr14;
  int64_t lvalue15;
  uint32_t local_2c [2];
  uint32_t local_24 [2];
  uint32_t local_1c [2];
  uint32_t local_14 [2];
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  value7 = arg8;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a893;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  UI_Child_Construct(self,arg1,arg2,arg3,arg8);
  cptr12 = arg6;
  *(uint8_t ***)self = &PTR_MovieWindow_Delete_0055c7b0;
  this_00 = *(void **)(value7 + 0x134);
  *(uint32_t *)((intptr_t)self + 0xac) = arg7;
  uptr13 = (uint32_t *)((intptr_t)self + 0x54);
  uvalue9 = 0xffffffff;
  local_4 = 0;
  *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  *(uint32_t *)((intptr_t)self + 0xa0) = 0;
  *(uint32_t *)((intptr_t)self + 0xb0) = 1;
  *(uint32_t *)((intptr_t)self + 0x9c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0xb4) = 0;
  *uptr13 = 0;
  *(uint32_t *)((intptr_t)self + 0xb8) = 0;
  *(uint32_t *)((intptr_t)self + 0x40) = 6;
  *(uint32_t *)((intptr_t)self + 0xa4) = arg4;
  switch(arg4) {
  case 0:
    uptr6 = arg5;
    for (value7 = 0x11; value7 != 0; value7 = value7 + -1) {
      *uptr13 = *uptr6;
      uptr6 = uptr6 + 1;
      uptr13 = uptr13 + 1;
    }
    Sprite_GetSize(*(void **)((intptr_t)self + 0x94),&arg3,&arg8);
    Sprite_GetHotspot(*(void **)((intptr_t)self + 0x94),&arg2,&arg1);
    break;
  case 1:
    if (*arg6 != '\0') {
      cptr8 = arg6;
      do {
        if (uvalue9 == 0) break;
        uvalue9 = uvalue9 - 1;
        cVar1 = *cptr8;
        cptr8 = cptr8 + 1;
      } while (cVar1 != '\0');
      cptr8 = operator_new(~uvalue9);
      uvalue9 = 0xffffffff;
      *(char **)((intptr_t)self + 0xa0) = cptr8;
      do {
        cptr14 = cptr12;
        if (uvalue9 == 0) break;
        uvalue9 = uvalue9 - 1;
        cptr14 = cptr12 + 1;
        cVar1 = *cptr12;
        cptr12 = cptr14;
      } while (cVar1 != '\0');
      uvalue9 = ~uvalue9;
      cptr12 = cptr14 + -uvalue9;
      for (uvalue11 = uvalue9 >> 2; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
        *(uint32_t *)cptr8 = *(uint32_t *)cptr12;
        cptr12 = cptr12 + 4;
        cptr8 = cptr8 + 4;
      }
      for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *cptr8 = *cptr12;
        cptr12 = cptr12 + 1;
        cptr8 = cptr8 + 1;
      }
    }
    *uptr13 = arg5;
    value7 = RecordList_FindFreeSlot(arg5,-1);
    *(int *)((intptr_t)self + 0x98) = value7;
    Sprite_DrawMasked((void *)*uptr13,&arg3,&arg8,&arg2,&arg1);
    Record_GetRect98((void *)*uptr13,0,local_2c,local_24,local_14,local_1c);
    lvalue15 = __ftol();
    arg2 = arg2 + (intptr_t)lvalue15;
    lvalue15 = __ftol();
    arg1 = arg1 + (intptr_t)lvalue15;
    break;
  case 2:
    if (*arg6 != '\0') {
      cptr8 = arg6;
      do {
        if (uvalue9 == 0) break;
        uvalue9 = uvalue9 - 1;
        cVar1 = *cptr8;
        cptr8 = cptr8 + 1;
      } while (cVar1 != '\0');
      cptr8 = operator_new(~uvalue9);
      uvalue9 = 0xffffffff;
      *(char **)((intptr_t)self + 0xa0) = cptr8;
      do {
        cptr14 = cptr12;
        if (uvalue9 == 0) break;
        uvalue9 = uvalue9 - 1;
        cptr14 = cptr12 + 1;
        cVar1 = *cptr12;
        cptr12 = cptr14;
      } while (cVar1 != '\0');
      uvalue9 = ~uvalue9;
      cptr12 = cptr14 + -uvalue9;
      for (uvalue11 = uvalue9 >> 2; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
        *(uint32_t *)cptr8 = *(uint32_t *)cptr12;
        cptr12 = cptr12 + 4;
        cptr8 = cptr8 + 4;
      }
      for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *cptr8 = *cptr12;
        cptr12 = cptr12 + 1;
        cptr8 = cptr8 + 1;
      }
    }
    *uptr13 = arg5;
    arg3 = arg5[1];
    arg8 = arg5[2];
    arg1 = 0;
    arg2 = 0;
    break;
  case 3:
    pvVar2 = operator_new(0x1c);
    *(void **)((intptr_t)self + 0xb8) = pvVar2;
    *(uint32_t *)((intptr_t)pvVar2 + 0x14) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0xb8) + 0xc) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0xb8) + 0x10) = 0;
    if (*arg6 != '\0') {
      uptr6 = *(uint32_t **)((intptr_t)self + 0xb8);
      for (value10 = 7; value10 != 0; value10 = value10 + -1) {
        *uptr6 = 0;
        uptr6 = uptr6 + 1;
      }
      ptr3 = Window_GetChildAndNotify(DAT_0057ba0c);
      *(int **)(*(int *)((intptr_t)self + 0xb8) + 4) = ptr3;
      value10 = *(int *)(*(int *)((intptr_t)self + 0xb8) + 4);
      if (value10 != 0) {
        _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,value10);
      }
      *(uint32_t **)(*(int *)((intptr_t)self + 0xb8) + 0x18) = arg5;
      *(uint32_t *)(*(int *)((intptr_t)self + 0xb8) + 0xc) = 1;
      pvVar4 = Resource_OpenNativeHandle(*(void **)(*(int *)(value7 + 0x134) + 0x10),arg6);
      uvalue5 = _BinkOpen_8(pvVar4,0x800000);
      **(uint32_t **)((intptr_t)self + 0xb8) = uvalue5;
      *(uint32_t *)((intptr_t)self + 0xac) = 1;
      if (**(int **)((intptr_t)self + 0xb8) == 0) {
        arg8 = 0;
        arg3 = 0;
        *(uint32_t *)((intptr_t)self + 0xa4) = 2;
        arg1 = 0;
        arg2 = 0;
      }
      else {
        (*(int **)((intptr_t)self + 0xb8))[3] = 1;
        ptr3 = *(int **)((intptr_t)self + 0xb8);
        arg3 = *(int *)*ptr3;
        arg8 = *(int *)(*ptr3 + 4);
        if (ptr3[6] != 0) {
          arg3 = arg3 << 1;
          arg8 = arg8 << 1;
        }
        arg6 = operator_new(0x11c);
        local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
        if (arg6 == (char *)0x0) {
          uptr6 = (uint32_t *)0x0;
        }
        else {
          uptr6 = Window_Construct(arg6,arg3,arg8,0x10);
        }
        *uptr13 = uptr6;
        local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
        MovieWindow_AdvanceFrame(self,*(int *)(*(int *)(value7 + 0x134) + 0xc));
        arg1 = 0;
        arg2 = 0;
      }
    }
  }
  *(int *)((intptr_t)self + 0x28) = *(int *)((intptr_t)self + 0x28) + arg2;
  *(int *)((intptr_t)self + 0x2c) = *(int *)((intptr_t)self + 0x2c) + arg1;
  UI_SetAbsolutePosition(self,arg3,arg8);
  if ((*(int *)((intptr_t)self + 0xa4) == 1) || (*(int *)((intptr_t)self + 0xa4) == 3)) {
    UI_AddEffectObject(this_00,self);
  }
  ExceptionList = pvStack_c;
  return self;
}
