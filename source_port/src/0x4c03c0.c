// ConstructionMenu_Fill: ported from Pizza Connection 2 at 0x4c03c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c03c0
#include "pc2_port.h"

void __cdecl ConstructionMenu_Fill(void *arg1)

{
  int value1;
  int value2;
  void *self;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  int64_t lvalue8;
  uint8_t local_80 [128];
  
  DAT_0057d708 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
  value7 = 0;
  if ((*(int *)(DAT_0057d708 + 8) == -1) || (*(int *)(DAT_0057d708 + 4) == 0x11)) {
    value2 = -1;
  }
  else {
    value7 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(DAT_0057d708 + 8));
    value2 = Game_FindCityIndex(value7);
    value2 = value2 + 1;
  }
  switch(*(uint32_t *)(DAT_0057d708 + 0x30)) {
  case 0xf:
    value3 = *(int *)(DAT_0057d708 + 0x48);
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    value3 = value3 + 0x858;
    uvalue4 = DAT_005820a4;
    break;
  case 0x10:
    value3 = DAT_0057d708;
    self = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(DAT_0057d708 + 8));
    value3 = Game_FindRecordByField34(self,value3);
    if (value3 == 0) {
      value3 = *(int *)(DAT_0057d708 + 0x48);
      if ((-1 < value3) && (value3 < 4)) {
        value3 = *(int *)(&DAT_00568188 + value3 * 4);
      }
      value3 = value3 + 0x834;
    }
    else {
      value1 = *(int *)(DAT_0057d708 + 0x48);
      if ((value1 < 0) || (3 < value1)) {
        value3 = Get_Field2C(value3);
        value3 = value1 + 0x838 + value3 * 4;
      }
      else {
        value1 = *(int *)(&DAT_00568188 + value1 * 4);
        value3 = Get_Field2C(value3);
        value3 = value1 + 0x838 + value3 * 4;
      }
    }
    uvalue4 = DAT_00582158;
    break;
  case 0x11:
    value3 = *(int *)(DAT_0057d708 + 0x34);
    value2 = -1;
    uvalue4 = DAT_00582134;
    break;
  default:
    value3 = *(int *)(DAT_0057d708 + 0x34);
    uvalue4 = DAT_00582e4c;
    break;
  case 0x1c:
    value3 = *(int *)(DAT_0057d708 + 0x34);
    Game_GetPlayerFieldC20(value7);
    String_Format(local_80,(uint8_t *)s__s__s_d_0056acc0,DAT_0058223c);
    goto LAB_004c053b;
  }
  String_Format(local_80,&DAT_005630d0,uvalue4);
LAB_004c053b:
  Window_GadgetNotify_Text_SetText(arg1,0x1f55,local_80);
  Submenu_SetObjectPicture(arg1,value3,1,0x1f54,value2,DAT_0057d708);
  if (value7 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x41b,DAT_00580d40);
  }
  else {
    Gadget_SetTextf(arg1,0x41b,&DAT_005630d0,value7 + 8);
  }
  ConstructionMenu_FillTimeLeft(arg1);
  uvalue5 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 8);
  value2 = (uint32_t)*(uint8_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 7) + *(int *)(DAT_0057d708 + 0x38);
  if (0x18 < value2) {
    uvalue6 = (value2 - 1U) / 0x18;
    do {
      uvalue5 = uvalue5 + 1;
      if (3 < (intptr_t)uvalue5) {
        uvalue5 = 0;
      }
      uvalue6 = uvalue6 - 1;
    } while (uvalue6 != 0);
  }
  Gadget_SetTextf(arg1,0x41a,(uint8_t *)s__d__d_00568ef8,uvalue5 + 1);
  if (value7 == 0) {
    UI_RemoveObjectByKey(arg1,0x419);
    UI_RemoveObjectByKey(arg1,0x40f);
    goto LAB_004c0713;
  }
  if (*(int *)(DAT_0057d708 + 0x30) == 0xf) {
    value7 = *(int *)(DAT_0057d708 + 0x34) + -0x858 >> 2;
    if (value7 == 1) {
      IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    }
    else {
      if (value7 != 2) goto LAB_004c0619;
      IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    }
LAB_004c06e0:
    lvalue8 = __ftol();
    uvalue4 = (uint32_t)lvalue8;
  }
  else {
    if (*(int *)(DAT_0057d708 + 0x30) == 0x10) {
      value7 = *(int *)(DAT_0057d708 + 0x34) + -0x834 >> 2;
      if (value7 == 1) {
        IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0)
        ;
      }
      else {
        if (value7 != 2) goto LAB_004c0619;
        IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0)
        ;
      }
      goto LAB_004c06e0;
    }
LAB_004c0619:
    uvalue4 = *(uint32_t *)(DAT_0057d708 + 0x3c);
  }
  Gadget_SetTextf(arg1,0x419,&DAT_005683a4,uvalue4);
LAB_004c0713:
  UI_DrawNeighborhoodCustomerIcons(arg1,0x1f42);
  return;
}
