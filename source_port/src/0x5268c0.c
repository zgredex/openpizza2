// UI_ShowChoiceMessageBox: ported from Pizza Connection 2 at 0x5268c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5268c0
#include "pc2_port.h"


int __cdecl UI_ShowChoiceMessageBox(void *arg1,char *arg2,int arg3,uint32_t arg4)

{
  uint32_t *uptr1;
  void *self;
  char *cptr2;
  uint32_t *uptr3;
  DWORD DVar4;
  uint32_t uvalue5;
  char cVar6;
  int value7;
  int value8;
  int value9;
  int64_t lvalue10;
  int *local_c4;
  int local_c0;
  int local_bc;
  int local_b4;
  int local_b0;
  int local_ac;
  double local_a8;
  uint32_t local_a0 [10];
  int local_78 [10];
  uint32_t local_50 [20];
  
                    /* Creates a modal choice message box and returns the selected button. */
  cVar6 = '\0';
  if (0 < arg3) {
    uptr1 = &arg4;
    uptr3 = local_a0;
    uvalue5 = arg4;
    value9 = arg3;
    do {
      *uptr3 = uvalue5;
      uvalue5 = uptr1[1];
      uptr1 = uptr1 + 1;
      uptr3 = uptr3 + 1;
      value9 = value9 + -1;
    } while (value9 != 0);
  }
  self = (void *)UI_LoadFontByName(arg1,*(char **)((intptr_t)arg1 + 0x288));
  if (self == (void *)0x0) {
    return -1;
  }
  if (*(int *)((intptr_t)arg1 + 0x278) == 1) {
    return -1;
  }
  *(uint32_t *)((intptr_t)arg1 + 0x278) = 1;
  while (arg2 != (char *)0x0) {
    local_50[cVar6] = arg2;
    cVar6 = cVar6 + '\x01';
    cptr2 = _strchr(arg2,10);
    if (cptr2 == (char *)0x0) break;
    *cptr2 = '\0';
    arg2 = cptr2 + 1;
  }
  value7 = (intptr_t)cVar6;
  local_a8 = (double)value7;
  lvalue10 = __ftol();
  value9 = 0;
  local_c0 = 0;
  if (0 < value7) {
    uptr3 = local_50;
    value8 = value7;
    do {
      local_b0 = Font_MeasureText(self,(char *)*uptr3);
      if (value9 < local_b0) {
        value9 = local_b0;
        local_c0 = local_b0;
      }
      uptr3 = uptr3 + 1;
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  if (0 < arg3) {
    uptr3 = local_a0;
    local_bc = arg3;
    do {
      value8 = Font_MeasureText(self,(char *)*uptr3);
      local_b0 = (value8 + 0x14) * arg3;
      if (value9 < local_b0) {
        value9 = local_b0;
        local_c0 = local_b0;
      }
      uptr3 = uptr3 + 1;
      local_bc = local_bc + -1;
    } while (local_bc != 0);
  }
  *(uint32_t *)((intptr_t)arg1 + 0x280) = 0;
  local_ac = UI_CreateFixedWindow
                       (arg1,*(int *)((intptr_t)arg1 + 0x270) - value9 >> 1,
                        *(int *)((intptr_t)arg1 + 0x274) - (intptr_t)lvalue10 >> 1,value9,(intptr_t)lvalue10,
                        &LAB_00526830,0,*(uint32_t *)((intptr_t)arg1 + 0x29c),
                        *(uint32_t *)((intptr_t)arg1 + 0x2a0),*(uint32_t *)((intptr_t)arg1 + 0x2a4),
                        *(uint32_t *)((intptr_t)arg1 + 0x2a8));
  uptr3 = (uint32_t *)UI_FindWindowByID(arg1,local_ac,(int *)0x0);
  value8 = 0;
  if (0 < value7) {
    uptr1 = local_50;
    do {
      UI_AddText(uptr3,value8,0,0,*(char **)((intptr_t)arg1 + 0x288),(char *)*uptr1);
      lvalue10 = __ftol();
      UI_CenterChildVertically(uptr3,value8,(intptr_t)lvalue10);
      Window_GadgetNotify_Text_SetTextColor(uptr3,value8,*(uint32_t *)((intptr_t)arg1 + 0x298));
      value8 = value8 + 1;
      uptr1 = uptr1 + 1;
    } while (value8 < value7);
    value9 = local_c0;
  }
  lvalue10 = __ftol();
  value7 = (intptr_t)lvalue10;
  local_b4 = 0;
  if (0 < arg3) {
    local_c4 = (int *)0x0;
    value9 = 1000;
    do {
      UI_AddTextButton(uptr3,value9,0,value7,*(char **)((intptr_t)arg1 + 0x288),
                       *(char **)((intptr_t)local_a0 + (intptr_t)local_c4),0,(char *)0x0);
      Gadget_SetButtonColors
                (uptr3,value9,*(uint32_t *)((intptr_t)arg1 + 0x28c),
                 *(uint32_t *)((intptr_t)arg1 + 0x290),*(uint32_t *)((intptr_t)arg1 + 0x294));
      Array_GetRectByKey(uptr3,value9,(int *)((intptr_t)local_78 + (intptr_t)local_c4),&local_b0);
      value8 = *(int *)((intptr_t)local_78 + (intptr_t)local_c4);
      if (local_b4 < value8) {
        local_b4 = value8;
      }
      local_c4 = (int *)((intptr_t)local_c4 + 4);
      value8 = value9 + -999;
      value9 = value9 + 1;
    } while (value8 < arg3);
    value9 = local_c0;
  }
  if (arg3 == 1) {
    UI_CenterChildVertically(uptr3,1000,value7);
    UI_AddUniquePair(uptr3,1000,0xd);
    value9 = 1000;
  }
  else {
    value8 = 0;
    if (0 < arg3) {
      local_c4 = local_78;
      local_c0 = 0;
      do {
        UI_SetObjectRangeByKey
                  (uptr3,value8 + 1000,(value9 / arg3 - *local_c4) / 2 + local_c0,value7);
        value8 = value8 + 1;
        local_c4 = local_c4 + 1;
        local_c0 = local_c0 + value9 / arg3;
      } while (value8 < arg3);
    }
    if (arg3 != 2) goto LAB_00526c5d;
    UI_AddUniquePair(uptr3,1000,0xd);
    value9 = 0x3e9;
  }
  UI_AddUniquePair(uptr3,value9,0x1b);
LAB_00526c5d:
  Window_ShowWindowById(arg1,local_ac);
  Set_Field228(arg1,uptr3);
  value9 = *(int *)((intptr_t)arg1 + 0x280);
  while ((value9 == 0 && (DVar4 = WaitForSingleObject(DAT_0057c0d8,0), DVar4 != 0))) {
    Window_ProcessMessageQueue(arg1,0);
    Sleep(10);
    value9 = *(int *)((intptr_t)arg1 + 0x280);
  }
  Clear_Field228((intptr_t)arg1);
  Window_DestroyChild(arg1,uptr3);
  *(uint32_t *)((intptr_t)arg1 + 0x278) = 0;
  UI_ReleaseRefCount(arg1,(intptr_t)self);
  return *(int *)((intptr_t)arg1 + 0x27c) + -1000;
}
