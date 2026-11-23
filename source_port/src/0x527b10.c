// UI_UpdateScene: ported from Pizza Connection 2 at 0x527b10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527b10
#include "pc2_port.h"

void __fastcall UI_UpdateScene(void *arg1)

{
  int value1;
  int value2;
  DWORD DVar3;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  int value7;
  uint32_t *uptr8;
  int local_c;
  int local_8;
  int local_4;
  
  value6 = 0;
  value7 = *(int *)((intptr_t)arg1 + 0x8334);
  local_4 = value7;
  if (*(int *)((intptr_t)arg1 + 0x83a8) != 0) {
    Sprite_GetSize(*(void **)((intptr_t)arg1 + 0x839c),&local_8,&local_c);
    value1 = *(int *)((intptr_t)arg1 + 0x83a0);
    if (value1 != -9999) {
      Rect_Union(arg1,value1,*(int *)((intptr_t)arg1 + 0x83a4),local_8 + value1,
                 local_c + *(int *)((intptr_t)arg1 + 0x83a4));
    }
    value1 = *(int *)((intptr_t)arg1 + 0x24c);
    value2 = *(int *)((intptr_t)arg1 + 0x248);
    *(int *)((intptr_t)arg1 + 0x83a4) = value1;
    *(int *)((intptr_t)arg1 + 0x83a0) = value2;
    Rect_Union(arg1,value2,value1,local_8 + value2,local_c + value1);
  }
  DVar3 = timeGetTime();
  if (DAT_00573ddc == 0) {
    uvalue5 = DVar3 - DAT_005841f4;
    if (10000 < uvalue5) {
      uvalue5 = 0;
    }
  }
  else {
    uvalue5 = 0;
    DAT_00573ddc = 0;
  }
  DAT_005841f4 = DVar3;
  if (0 < value7) {
    do {
      ptr4 = (int *)Array_GetPtr((void *)((intptr_t)arg1 + 0x8324),value6);
      if (ptr4 != (int *)0x0) {
        (**(code **)(*ptr4 + 0x18))(uvalue5);
      }
      value6 = value6 + 1;
    } while (value6 < local_4);
  }
  if (*(int **)((intptr_t)arg1 + 0x833c) != (int *)0x0) {
    value7 = *(int *)((intptr_t)arg1 + 0x8348) - uvalue5;
    *(int *)((intptr_t)arg1 + 0x8348) = value7;
    if (value7 < 1) {
      *(int *)((intptr_t)arg1 + 0x8348) = *(int *)((intptr_t)arg1 + 0x8344) + value7;
      (**(code **)(**(int **)((intptr_t)arg1 + 0x833c) + 0xc))(0x3c,0,0);
    }
  }
  value7 = 0;
  if (0 < *(int *)((intptr_t)arg1 + 0x23c)) {
    uptr8 = (uint32_t *)((intptr_t)arg1 + 0x14);
    do {
      if ((void *)*uptr8 != (void *)0x0) {
        UI_TickChildRepeatTimer((void *)*uptr8,uvalue5);
      }
      value7 = value7 + 1;
      uptr8 = uptr8 + 1;
    } while (value7 < *(int *)((intptr_t)arg1 + 0x23c));
  }
  return;
}
