// Game_RenderFrame: ported from Pizza Connection 2 at 0x485140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485140
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t __fastcall Game_RenderFrame(void *arg1)

{
  void *pvVar1;
  DWORD DVar2;
  int value3;
  uint32_t uvalue4;
  int value5;
  uint8_t flag6;
  int value7;
  int value8;
  int value9;
  bool flag10;
  double extraout_ST0;
  double fVar11;
  int64_t lvalue12;
  int64_t lvalue13;
  uint32_t local_38;
  LARGE_INTEGER local_28;
  LARGE_INTEGER local_20;
  tagRECT local_18;
  
                    /* Renders and updates one game frame. */
  if ((DAT_0057c634 & 1) == 0) {
    DAT_0057c634 = DAT_0057c634 | 1;
    DVar2 = timeGetTime();
    DAT_0057c654 = DVar2 + 10000;
  }
  CS_Enter(*(int *)((intptr_t)arg1 + 0x240));
  if (DAT_0057c5e8 != 0) {
    QueryPerformanceCounter(&local_20);
  }
  if (*(int *)((intptr_t)arg1 + 0x1508) == 0) {
    Game_TickWorldObjects((intptr_t)DAT_0057c5cc);
  }
  if ((*(int *)((intptr_t)arg1 + 0x300) != 0) && (DAT_0057c674 != (void *)0x0)) {
    value3 = Array_GetRecordByKeyPtr(DAT_0057c674,0x2a);
    if (value3 != 0) {
      value3 = UI_GetWindowObject(DAT_0057c674,0x2a);
      UI_ClipChildRect(value3);
      uvalue4 = Object_GetActiveValue(value3);
      Sprite_Blit24Bit(*(void **)((intptr_t)arg1 + 0x300),uvalue4,0,0,-9999,-9999,0,0);
      SetEvent(DAT_0057c5ac);
    }
    CS_Leave(*(int *)((intptr_t)arg1 + 0x240));
    return 1;
  }
  pvVar1 = *(void **)((intptr_t)arg1 + 0x2fc);
  if (pvVar1 == (void *)0x0) goto LAB_004855e5;
  value3 = *(int *)((intptr_t)arg1 + 0x2da0);
  flag10 = value3 != DAT_00580a50;
  if (flag10) {
    value7 = *(int *)((intptr_t)pvVar1 + 0x24);
    value5 = *(int *)((intptr_t)pvVar1 + 0x28);
    value9 = (intptr_t)DAT_00571950 >> 1;
    value8 = (intptr_t)DAT_00571954 >> 1;
    DAT_00571954 = DAT_0057195c << ((uint8_t)value3 & 0x1f);
    DAT_00571950 = DAT_00571958 << ((uint8_t)value3 & 0x1f);
    DAT_00580a50 = value3;
    Game_ResizeZoomSurfaces(DAT_0057c5cc,DAT_0057c5c8,DAT_00571950,DAT_00571954,0,0,0);
    Map_UpdateObjectScreenBounds(pvVar1);
    Map_ScrollToClamped(arg1,pvVar1,(value9 + value7) - ((intptr_t)DAT_00571950 >> 1),
                        (value8 + value5) - ((intptr_t)DAT_00571954 >> 1));
  }
  flag6 = (uint8_t)DAT_00580a50;
  if (*(int *)((intptr_t)arg1 + 0x2d98) == 2) {
    DVar2 = timeGetTime();
    value3 = *(int *)((intptr_t)pvVar1 + 0x28);
    value7 = *(int *)((intptr_t)pvVar1 + 0x24);
    if ((float)(DVar2 - DAT_0057c630) <= 0.0) {
      flag6 = (uint8_t)DAT_00580a50;
    }
    else {
      _DAT_0057c648 = (float)(intptr_t)(DAT_0057c660) * (float)(DVar2 - DAT_0057c630) * 0.001 + _DAT_0057c648;
      lvalue12 = __ftol();
      lvalue13 = __ftol();
      _DAT_0057c648 = _DAT_0057c648 - (float)(intptr_t)lvalue12;
      _DAT_0057c64c = (float)(extraout_ST0 - (double)(intptr_t)lvalue13);
      Map_ScrollToClamped(arg1,pvVar1,((intptr_t)lvalue12 << ((uint8_t)DAT_00580a50 & 0x1f)) + value7,
                          ((intptr_t)lvalue13 << ((uint8_t)DAT_00580a50 & 0x1f)) + value3);
      flag6 = (uint8_t)DAT_00580a50;
      DAT_0057c630 = DVar2;
    }
  }
  if (*(int *)((intptr_t)arg1 + 0x2d98) == 1) {
    if (DAT_0057ba08 == 0) {
      value3 = (DAT_0057c660 << (flag6 & 0x1f)) + *(int *)((intptr_t)pvVar1 + 0x24);
      value7 = (DAT_0057c664 << (flag6 & 0x1f)) + *(int *)((intptr_t)pvVar1 + 0x28);
    }
    else {
      value3 = *(int *)((intptr_t)pvVar1 + 0x24) - (DAT_0057c660 << (flag6 & 0x1f));
      value7 = *(int *)((intptr_t)pvVar1 + 0x28) - (DAT_0057c664 << (flag6 & 0x1f));
    }
    Map_ScrollToClamped(arg1,pvVar1,value3,value7);
    DAT_0057c664 = 0;
    DAT_0057c660 = 0;
  }
  value3 = *(int *)((intptr_t)arg1 + 0x21c);
  if ((value3 != 0) && (*(int *)((intptr_t)arg1 + 0x2da8) != 0)) {
    if (*(int *)(value3 + 0x74) == 0) {
      value7 = IDMap_Lookup((void *)((intptr_t)arg1 + 4),*(int *)((intptr_t)arg1 + 0x2f4),(int *)0x0);
      if (*(void **)(value7 + 0xfa8) != pvVar1) {
        *(int *)((intptr_t)arg1 + 0x21c) = value3;
        *(uint32_t *)((intptr_t)arg1 + 0x2da8) = 1;
        if (*(int *)((intptr_t)arg1 + 0x2dc) != 1) {
          value3 = -0x18607;
          goto LAB_0048550c;
        }
      }
    }
    else {
      value7 = *(int *)(value3 + 0xf4);
      value5 = *(int *)(value7 + 0x2c);
      value8 = Game_GetPlayerSubmapValue(arg1,*(int *)(value7 + 8),value5);
      if (*(void **)(value8 + 0x14e0) != pvVar1) {
        value7 = Game_GetPlayerSubmapValue(arg1,*(int *)(value7 + 8),value5);
        *(int *)((intptr_t)arg1 + 0x9c) = value7;
        Sound_SelectCurrentTrack(DAT_0057ba0c);
        value7 = *(int *)(value7 + 0x30);
        value5 = Game_GetCurrentPlayerCompanyName((intptr_t)arg1);
        if (value7 == value5) {
          *(uint32_t *)((intptr_t)arg1 + 0x2c8) = *(uint32_t *)((intptr_t)arg1 + 0x2a8);
        }
        else {
          *(uint32_t *)((intptr_t)arg1 + 0x2c8) = *(uint32_t *)((intptr_t)arg1 + 0x2a8);
        }
        *(uint32_t *)((intptr_t)arg1 + 0x2a8) = 1;
        *(int *)((intptr_t)arg1 + 0x21c) = value3;
        *(uint32_t *)((intptr_t)arg1 + 0x2da8) = 1;
        if (*(int *)((intptr_t)arg1 + 0x2dc) != 4) {
          value3 = -0x18608;
LAB_0048550c:
          UI_QueueChildCommand(DAT_0057c5e0,value3,0);
        }
      }
    }
    Object_ScrollViewToObject(*(void **)((intptr_t)arg1 + 0x21c));
  }
  value3 = Game_UpdateAmbientLight(arg1,(intptr_t)pvVar1);
  if (value3 != 0) {
    *(uint32_t *)((intptr_t)pvVar1 + 0xf4) = 1;
  }
  SetRect(&local_18,0,0,DAT_00571950,DAT_00571954);
  IsoMap_RenderFrame(pvVar1,DAT_0057c5d0,(int *)0x0,0,&local_18.left);
  if ((flag10) &&
     (((value3 = *(int *)((intptr_t)arg1 + 0x290), value3 == 1 || (value3 == 2)) || (value3 == 3)))) {
    pvVar1 = *(void **)((intptr_t)arg1 + 0x25c);
    UI_SetChildVisibleByID(pvVar1,0x1f4e,(uint32_t)(DAT_00580a50 == 2));
    UI_SetChildVisibleByID(pvVar1,0x1f4f,(uint32_t)(DAT_00580a50 == 2));
  }
  Rect_Set1A4(DAT_0057c5e0,&local_18.left);
  DAT_0057c678 = DAT_0057c678 + 1;
LAB_004855e5:
  CS_Leave(*(int *)((intptr_t)arg1 + 0x240));
  if (DAT_0057c5e8 != 0) {
    QueryPerformanceCounter(&local_28);
    fVar11 = UI_GetScrollRatio((intptr_t)DAT_0057c5e0,local_20.s.LowPart,local_20.s.HighPart,
                               local_28.s.LowPart,local_28.s.HighPart);
    _DAT_0057c680 = (double)(fVar11 + (double)_DAT_0057c680);
    DVar2 = timeGetTime();
    if (DAT_0057c654 < DVar2) {
      DAT_0057c654 = DAT_0057c654 + 10000;
      local_38 = SUB84((double)((float)(intptr_t)(DAT_0057c678) * 0.1),0);
      DebugConsole_Printf(DAT_0057c1e0,0x80,(uint8_t *)s_Iso_fps___1f___1f_d___2f_005680f4,local_38);
      DAT_0057c678 = 0;
      _DAT_0057c680 = 0.0;
    }
  }
  SetEvent(DAT_0057c5ac);
  return 1;
}
