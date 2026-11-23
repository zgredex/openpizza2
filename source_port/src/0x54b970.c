// UI_ComposeOverlayWindow: ported from Pizza Connection 2 at 0x54b970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b970
#include "pc2_port.h"


uint32_t
UI_ComposeOverlayWindow
          (void *arg1,int arg2,int arg3,void *arg4,int arg5,int arg6,int arg7)

{
  short svalue1;
  void *pvVar2;
  void *self;
  int value3;
  char *cptr4;
  uint32_t *this_00;
  uint32_t *uptr5;
  uint32_t uvalue6;
  uint16_t uvalue7;
  int local_28;
  int local_24;
  void *local_20;
  int local_1c [4];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  value3 = arg2;
  self = arg1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b9db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cptr4 = (char *)UI_GetButtonSpriteRecord(arg1,arg2);
  if (cptr4 == (char *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  this_00 = Renderer_CreateChild(DAT_0057c5c8);
  if (*cptr4 == '\0') {
    pvVar2 = *(void **)(cptr4 + 0x40);
    if (*(char *)((intptr_t)pvVar2 + 0x39) == '\0') {
      Sprite_RealizeLazy(pvVar2);
    }
    svalue1 = *(short *)((intptr_t)pvVar2 + 6);
    uvalue7 = *(uint16_t *)((intptr_t)pvVar2 + 8);
    uvalue6 = *(uint32_t *)((intptr_t)pvVar2 + 0x2c);
  }
  else {
    Sprite_GetSize(*(void **)(cptr4 + 0x40),(int *)&arg1,&arg2);
    Array_GetPairByKey(self,value3,&local_24,&local_28);
    local_20 = operator_new(0x50);
    uptr5 = (uint32_t *)0x0;
    local_4 = 0;
    if (local_20 != (void *)0x0) {
      uptr5 = Sprite_CreateRaw(local_20,(uint32_t)arg1,arg2,0,0x10,0);
    }
    local_4 = 0xffffffff;
    UI_RemoveObject(self,value3);
    UI_CreateMovieWindow(self,value3,local_24,local_28,uptr5,1);
    if (*(char *)((intptr_t)uptr5 + 0x39) == '\0') {
      Sprite_RealizeLazy(uptr5);
    }
    svalue1 = *(short *)((intptr_t)uptr5 + 6);
    uvalue7 = *(uint16_t *)(uptr5 + 2);
    uvalue6 = uptr5[0xb];
  }
  Surface_Configure(this_00,uvalue6,(uint16_t)((intptr_t)svalue1 >> 1),uvalue7,(intptr_t)svalue1);
  UI_DrawOverlaySprites(DAT_0057c5ec,(intptr_t)this_00,arg3,arg4,arg5,arg6,arg7);
  Array_GetBoundsByKey(self,value3,local_1c);
  UI_ClipRect(self,local_1c,1);
  if (this_00 != (uint32_t *)0x0) {
    (**(code **)*this_00)(1);
  }
  ExceptionList = local_c;
  return 1;
}
