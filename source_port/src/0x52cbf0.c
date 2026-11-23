// UI_ProcessDialogInput: ported from Pizza Connection 2 at 0x52cbf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52cbf0
#include "pc2_port.h"


int __thiscall UI_ProcessDialogInput(void *self,void *arg1,void *arg2)

{
  char cVar1;
  uint8_t flag2;
  uint8_t uvalue3;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  int value4;
  int value5;
  void *this_00;
  int value6;
  uint32_t uvalue7;
  int local_3c;
  void *local_38;
  int local_34;
  void *local_30;
  uint32_t local_2c;
  int local_28;
  int local_24;
  uint32_t local_20;
  uint32_t local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint32_t local_c;
  int local_8;
  int local_4;
  
  value6 = 0;
  this_00 = *(void **)((intptr_t)self + 0x54);
  *(uint32_t *)((intptr_t)self + 0x80) = 0;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  *(void **)(*(int *)((intptr_t)self + 0x88) + 0xc) = this_00;
  local_24 = 0;
  local_38 = self;
  if (arg1 == (void *)0x0) {
    local_3c = *(int *)((intptr_t)self + 0x38);
    local_34 = *(int *)((intptr_t)self + 0x3c);
    local_2c = *(uint32_t *)((intptr_t)self + 0x6c);
  }
  else {
    Text_GetPosition(this_00,&local_3c,&local_34);
    local_2c = *(uint32_t *)((intptr_t)this_00 + 0x9c4);
  }
  local_1c = Text_GetLineHeight((intptr_t)this_00);
  local_28 = local_34 - *(int *)((intptr_t)self + 0x60);
  local_4 = local_3c;
  do {
    local_10 = 0;
    local_14 = 0;
    local_30 = (void *)0x0;
    local_3c = local_4;
    local_34 = local_28;
    local_18 = Text_MeasureStyledRun(self,arg2,this_00,value6,&local_20,&local_2c,&local_30);
    if (local_30 == (void *)0x0) {
      local_30 = this_00;
    }
    local_8 = *(int *)((intptr_t)local_30 + 0x9b0);
    value5 = (local_8 - *(int *)((intptr_t)local_30 + 0x9b4)) + local_34;
    if (local_2c == 2) {
      value4 = (intptr_t)((intptr_t)*(short *)((intptr_t)local_38 + 100) - local_20) >> 1;
LAB_0052ccfe:
      local_3c = local_3c + value4;
    }
    else if (local_2c == 1) {
      value4 = (intptr_t)*(short *)((intptr_t)local_38 + 100) - local_20;
      goto LAB_0052ccfe;
    }
    if (*(int *)((intptr_t)local_38 + 0x80) != 0) {
      if (*(int *)((intptr_t)local_38 + 0x84) == 0) {
        if (arg1 != (void *)0x0) {
          value4 = *(int *)(*(int *)((intptr_t)local_38 + 0x88) + 8);
          Surface_DrawFilledCircle
                    (arg1,value4 + local_3c,*(int *)((intptr_t)this_00 + 0x9b0) / 2 + local_34,value4,
                     *(uint32_t *)(*(int *)((intptr_t)local_38 + 0x88) + 4));
        }
        *(uint32_t *)((intptr_t)local_38 + 0x84) = 1;
      }
      local_3c = local_3c + **(int **)((intptr_t)local_38 + 0x88);
    }
    value4 = (*(int *)((intptr_t)local_30 + 0x9b4) - *(int *)((intptr_t)this_00 + 0x9b4)) + value5;
    local_34 = value4;
    if (value6 < local_18) {
      do {
        cVar1 = *(char *)(value6 + (intptr_t)arg2);
        local_c = CONCAT31(((uint8_t)((local_c) >> 24)),cVar1);
        uvalue7 = local_c;
        if (cVar1 == '\x01') {
          cVar1 = *(char *)(value6 + 2 + (intptr_t)arg2);
          if (cVar1 == '\0') {
            flag2 = *(uint8_t *)(value6 + 3 + (intptr_t)arg2);
            if ((!(flag2 == 9 || flag2 < 9)) ||
               (this_00 = *(void **)(*(int *)((intptr_t)local_38 + 0x88) + 0xc + (uint32_t)flag2 * 4),
               this_00 == (void *)0x0)) {
              this_00 = *(void **)(*(int *)((intptr_t)local_38 + 0x88) + 0xc);
            }
            Set_Field9B8(this_00,local_1c);
            value4 = (*(int *)((intptr_t)local_30 + 0x9b4) - *(int *)((intptr_t)this_00 + 0x9b4)) + value5;
            local_34 = value4;
          }
          else if (cVar1 == '\x01') {
            local_1c = (uint32_t)CONCAT21(CONCAT11(*(uint8_t *)(value6 + 5 + (intptr_t)arg2),
                                               *(uint8_t *)(value6 + 4 + (intptr_t)arg2)),
                                      *(uint8_t *)(value6 + 3 + (intptr_t)arg2));
            Set_Field9B8(this_00,local_1c);
            value4 = local_34;
          }
          else if (cVar1 == '\x05') {
            if (local_18 <= (intptr_t)(*(uint8_t *)(value6 + 1 + (intptr_t)arg2) + 2 + value6)) {
              if (arg1 != (void *)0x0) {
                Text_SetCursor(this_00,local_3c,value4);
                Text_DrawCharAdvance(this_00,arg1,'-');
              }
              uvalue3 = Font_GetCharWidth(this_00,0x2d);
              local_3c = local_3c + CONCAT31(extraout_var,uvalue3);
              value4 = local_34;
            }
          }
          local_14 = 1;
          value6 = value6 + 1 + (uint32_t)*(uint8_t *)(value6 + 1 + (intptr_t)arg2);
        }
        else {
          local_10 = 1;
          uvalue3 = Font_GetCharWidth(this_00,local_c);
          if (CONCAT31(extraout_var_00,uvalue3) == 0) {
            uvalue7 = 0x20;
          }
          else if (arg1 != (void *)0x0) {
            Text_SetCursor(this_00,local_3c,local_34);
            Text_DrawCharAdvance(this_00,arg1,cVar1);
          }
          uvalue3 = Font_GetCharWidth(this_00,uvalue7);
          local_3c = local_3c + CONCAT31(extraout_var_01,uvalue3);
          value4 = local_34;
        }
        value6 = value6 + 1;
      } while (value6 < local_18);
    }
    if (*(char *)(value6 + (intptr_t)arg2) == '\0') {
LAB_0052cf90:
      return local_24 + *(int *)((intptr_t)this_00 + 0x9b0) * 2;
    }
    if ((local_14 == 0) || (local_10 != 0)) {
      local_28 = local_28 + local_8;
      local_24 = local_24 + local_8;
    }
    if (*(uint8_t *)(value6 + (intptr_t)arg2) < 0x21) {
      if (*(uint8_t *)(value6 + (intptr_t)arg2) == 0xd) {
        *(uint32_t *)((intptr_t)local_38 + 0x80) = 0;
        *(uint32_t *)((intptr_t)local_38 + 0x84) = 0;
        local_2c = 0;
      }
      value6 = value6 + 1;
    }
    if (*(char *)(value6 + (intptr_t)arg2) == '\n') {
      value6 = value6 + 1;
    }
    if (*(char *)(value6 + (intptr_t)arg2) == '\0') goto LAB_0052cf90;
    self = local_38;
  } while( true );
}
