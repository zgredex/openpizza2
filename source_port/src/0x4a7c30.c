// Mission_UpdateObjectivesPanel: ported from Pizza Connection 2 at 0x4a7c30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a7c30
#include "pc2_port.h"

void __cdecl Mission_UpdateObjectivesPanel(int *arg1,char arg2)

{
  int value1;
  int *ptr2;
  int *self;
  int value3;
  int value4;
  int64_t lvalue5;
  int value6;
  uint32_t uvalue7;
  int local_8;
  int local_4;
  
                    /* Fills the mission objectives page with goals, time, and reward. */
  self = arg1;
  value3 = 0;
  ptr2 = *(int **)(*(int *)(DAT_0057c670 + 0x224) + 0xac);
  local_8 = 0;
  local_4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (local_4 == 0) {
    local_4 = 0;
  }
  else {
    local_4 = local_4 + 4;
  }
  value4 = 0x1f44;
  do {
    Window_GadgetNotify_Text_SetText(arg1,value4,DAT_00582adc);
    Window_GadgetNotify_Text_SetTextColor(arg1,value4,0);
    Window_GadgetNotify_Text_SetTextColor(arg1,value4 + 3,0);
    value1 = value4 + -0x1f43;
    value4 = value4 + 1;
  } while (value1 < 3);
  value4 = 0x1f44;
  arg1 = ptr2;
  do {
    arg1 = arg1 + 1;
    value1 = *arg1;
    if (value1 < 0) {
      local_8 = local_8 + 1;
    }
    else {
      if (*(int *)(&DAT_00571e0c + value1 * 4) == 0) {
        if (*(char *)((intptr_t)ptr2 + value3 + 0xc4) == '\0') {
          Window_GadgetNotify_Text_SetTextColor(self,value4 + 3,0xff);
          uvalue7 = 0xff;
          value6 = value4;
        }
        else {
          Window_GadgetNotify_Text_SetTextColor(self,value4,0xa000);
          uvalue7 = 0xa000;
          value6 = value4 + 3;
        }
LAB_004a7d7b:
        Window_GadgetNotify_Text_SetTextColor(self,value6,uvalue7);
        if ((value1 == 0) && (DAT_0057bb20 == '\0')) {
          Window_GadgetNotify_Text_SetText(self,value4,DAT_00580de8);
          value4 = value4 + 1;
          goto LAB_004a7da5;
        }
      }
      else {
        if (value1 != 0xf) {
          Window_GadgetNotify_Text_SetTextColor(self,value4,0xa000);
          value6 = value4 + 3;
          uvalue7 = 0xa000;
          goto LAB_004a7d7b;
        }
        if (ptr2[0x13] < 2) {
          Window_GadgetNotify_Text_SetTextColor(self,value4,0xa000);
          uvalue7 = 0xa000;
        }
        else {
          Window_GadgetNotify_Text_SetTextColor(self,value4,0xff);
          uvalue7 = 0xff;
        }
        Window_GadgetNotify_Text_SetTextColor(self,value4 + 3,uvalue7);
      }
      Window_GadgetNotify_Text_SetText(self,value4,*(uint32_t *)(&DAT_00583384 + value1 * 4));
      value4 = value4 + 1;
    }
LAB_004a7da5:
    value3 = value3 + 1;
  } while (value3 < 3);
  if (local_8 == 3) {
    Window_GadgetNotify_Text_SetText(self,0x1f43,DAT_005818e0);
    value3 = 0x1f44;
    do {
      UI_RemoveObjectByKey(self,value3);
      value3 = value3 + 1;
    } while (value3 < 0x1f4a);
LAB_004a7de9:
    UI_RemoveObjectByKey(self,0x1f4b);
    Window_GadgetNotify_Text_SetText(self,0x1f4a,DAT_00582b28);
  }
  else {
    if (DAT_0057bb2c == 0xb) goto LAB_004a7de9;
    Gadget_SetTextf(self,0x1f4b,(uint8_t *)s__d__s_00568324,ptr2[0x30]);
  }
  if (DAT_0057bb20 == '\0') {
    if ((char)ptr2[0x33] != '\0') {
      Window_GadgetNotify_Text_SetText(self,0x42b,local_4 + 0x818);
      if (arg2 != '\0') {
        Sound_PlayMissionSpeech(DAT_0057ba0c,DAT_0057bb40,'\x01');
      }
      goto LAB_004a7eae;
    }
    local_4 = local_4 + 0x418;
  }
  else if ((char)ptr2[0x33] == '\0') {
    local_4 = DAT_005811dc;
  }
  else {
    local_4 = DAT_005818f8;
  }
  Window_GadgetNotify_Text_SetText(self,0x42b,local_4);
LAB_004a7eae:
  value3 = 0x1f42;
  if ((char)ptr2[0x33] != '\0') {
    UI_ShowChildByID(self,0x1f42);
    Gadget_SetText(self,0x1f42,DAT_00582e70);
    UI_RemoveObjectByKey(self,0x1f43);
    UI_RemoveObjectByKey(self,0x1f4a);
    value3 = 0x1f4b;
  }
  UI_RemoveObjectByKey(self,value3);
  if (DAT_0057bb40 == 8) {
    UI_ShowChildByID(self,0x1f4c);
    UI_ShowChildByID(self,0x1f4d);
    Stats_SumFilteredFloats3
              (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),0x19,-1,-1);
    lvalue5 = __ftol();
    Gadget_SetTextf(self,0x1f4d,&DAT_005683a4,(intptr_t)lvalue5);
    return;
  }
  UI_RemoveObjectByKey(self,0x1f4c);
  UI_RemoveObjectByKey(self,0x1f4d);
  return;
}
