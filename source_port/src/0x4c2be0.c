// Window_UpdateFurniturePage: ported from Pizza Connection 2 at 0x4c2be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c2be0
#include "pc2_port.h"

void __cdecl Window_UpdateFurniturePage(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  void *pvVar4;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint8_t flag5;
  int value6;
  int value7;
  int local_118;
  int local_114;
  int local_110;
  void *local_10c;
  int local_108;
  int local_104;
  char local_100 [256];
  
                    /* Updates the furniture page's selected item and totals. */
  pvVar4 = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
  local_10c = pvVar4;
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar4 + 0x30));
  local_108 = Game_GetPlayerCity(value2);
  self = *(void **)((intptr_t)DAT_0057c670 + 0x220);
  if (DAT_0056adec == 2) {
    uvalue3 = Game_ContainsObjectPointer(pvVar4,(intptr_t)self);
    if ((char)uvalue3 != '\0') {
      flag5 = 1;
      goto LAB_004c2c35;
    }
  }
  flag5 = 0;
LAB_004c2c35:
  uvalue1 = (uint32_t)flag5;
  UI_SetChildVisibleByID(arg1,0x1f46,uvalue1);
  UI_SetChildVisibleByID(arg1,0x589,uvalue1);
  UI_SetChildVisibleByID(arg1,0x58a,uvalue1);
  UI_SetChildVisibleByID(arg1,0x58b,uvalue1);
  UI_SetChildVisibleByID(arg1,0x58e,uvalue1);
  UI_SetChildVisibleByID(arg1,0x58f,uvalue1);
  UI_SetChildVisibleByID(arg1,0x590,uvalue1);
  UI_SetChildVisibleByID(arg1,0x591,uvalue1);
  if (flag5 != 0) {
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),*(int *)((intptr_t)self + 4),(int *)0x0);
    if ((*(int *)(value2 + 8) < 1) || (2 < *(int *)(value2 + 8))) {
      String_Format(local_100,(uint8_t *)s_Moebel__s_spr_00568450,value2 + 0x40);
    }
    else {
      String_Format(local_100,(uint8_t *)s_Moebel__s__c_spr_00568460,value2 + 0x40);
    }
    UI_SetButtonSpriteByName(arg1,0x1f46,local_100);
    Window_GadgetNotify_Text_SetText(arg1,0x589,value2 + 0x18);
    Window_GadgetNotify_Text_SetText(arg1,0x58b,(&DAT_0058319c)[*(int *)(value2 + 0x10)]);
    value2 = Game_ComputeEventValue(self,local_108,&local_114);
    Gadget_SetTextf(arg1,0x58f,&DAT_005683a4,local_114 + value2);
    Gadget_SetTextf(arg1,0x591,&DAT_005683a4,local_114);
  }
  value2 = *(int *)((intptr_t)local_10c + 0x170c);
  local_104 = value2;
  Gadget_SetTextf(arg1,0x5c2,(uint8_t *)s__d__s_00568324,value2);
  value7 = 0;
  value6 = 0;
  local_110 = 0;
  local_118 = 0;
  if (0 < value2) {
    do {
      pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)local_10c + 0x16f8),value7,(int *)0x0);
      value2 = Game_ComputeEventValue(pvVar4,local_108,&local_114);
      local_110 = local_110 + value2;
      value6 = value6 + local_114;
      local_118 = local_118 + *(int *)((intptr_t)pvVar4 + 0xc);
      value7 = value7 + 1;
    } while (value7 < local_104);
    value2 = local_104;
  }
  Gadget_SetTextf(arg1,0x5c3,&DAT_005683a4,value6 + local_110);
  Gadget_SetTextf(arg1,0x5c4,&DAT_005683a4,value6);
  Gadget_SetTextf(arg1,0x5bc,&DAT_005683a4,local_110);
  pvVar4 = local_10c;
  value6 = Rating_GetInverse100((intptr_t)local_10c);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f49,value6,0);
  if (value2 == 0) {
    local_118 = 0;
  }
  else {
    local_118 = local_118 / value2;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x5b9,local_118,0);
  value2 = 0;
  uvalue3 = extraout_EDX;
  do {
    value6 = Branch_ComputeBuildingRating(pvVar4,uvalue3,value2);
    Rating_UpdateBarByKey(arg1,0x559,value2,value6,DAT_00582320);
    value2 = value2 + 1;
    uvalue3 = extraout_EDX_00;
  } while (value2 < 8);
  return;
}
