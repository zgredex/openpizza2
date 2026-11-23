// StatisticsBranchBalance_DrawProfitBars: ported from Pizza Connection 2 at 0x4acb90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4acb90
#include "pc2_port.h"

void __cdecl
StatisticsBranchBalance_DrawProfitBars(void *arg1,int *arg2,int *arg3,int arg4)

{
  int *ptr1;
  int *ptr2;
  void *pvVar3;
  int value4;
  int value5;
  int value6;
  uint32_t uvalue7;
  int value8;
  int value9;
  int local_c;
  int local_8;
  int local_4;
  
  ptr1 = arg3;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  value9 = (intptr_t)arg2 - (intptr_t)arg3;
  value8 = arg4 - (intptr_t)arg3;
  arg3 = (int *)0x9;
  ptr2 = ptr1;
  do {
    value5 = *(int *)(value9 + (intptr_t)ptr2);
    if (local_c < value5) {
      local_c = value5;
    }
    if (local_8 < *ptr2) {
      local_8 = *ptr2;
    }
    value5 = *(int *)(value8 + (intptr_t)ptr2);
    if (local_4 < value5) {
      local_4 = value5;
    }
    ptr2 = ptr2 + 1;
    arg3 = (int *)((intptr_t)arg3 + -1);
  } while (arg3 != (int *)0x0);
  value5 = (intptr_t)ptr1 - (intptr_t)arg2;
  value9 = (intptr_t)&DAT_00569630 - (intptr_t)arg2;
  value6 = arg4 - (intptr_t)arg2;
  value8 = 0x8a2;
  while( true ) {
    pvVar3 = (void *)UI_GetWindowObject(arg1,*(int *)(value9 + (intptr_t)arg2));
    UI_RealizeSprite((intptr_t)pvVar3);
    if (local_c != 0) {
      value4 = (*arg2 * 100) / local_c;
      if (value4 < 0x4c) {
        uvalue7 = ((value4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uvalue7 = 0xa000;
      }
      Sprite_FillRectColor(pvVar3,0,0,(value4 * 0x24) / 100,0xf,uvalue7);
    }
    UI_ClipChildRect((intptr_t)pvVar3);
    pvVar3 = (void *)UI_GetWindowObject(arg1,value8 + -10);
    UI_RealizeSprite((intptr_t)pvVar3);
    if (local_8 != 0) {
      value4 = (*(int *)(value5 + (intptr_t)arg2) * 100) / local_8;
      if (value4 < 0x4c) {
        uvalue7 = ((value4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uvalue7 = 0xa000;
      }
      Sprite_FillRectColor(pvVar3,0,0,(value4 * 0x24) / 100,0xf,uvalue7);
    }
    UI_ClipChildRect((intptr_t)pvVar3);
    pvVar3 = (void *)UI_GetWindowObject(arg1,value8);
    UI_RealizeSprite((intptr_t)pvVar3);
    if (local_4 != 0) {
      value4 = (*(int *)(value6 + (intptr_t)arg2) * 100) / local_4;
      if (value4 < 0x4c) {
        uvalue7 = ((value4 < 0x1a) - 1 & 0xff00) + 0xff;
      }
      else {
        uvalue7 = 0xa000;
      }
      Sprite_FillRectColor(pvVar3,0,0,(value4 * 0x5e) / 100,0xf,uvalue7);
    }
    UI_ClipChildRect((intptr_t)pvVar3);
    arg2 = arg2 + 1;
    if (8 < value8 + -0x8a1) break;
    value8 = value8 + 1;
  }
  return;
}
