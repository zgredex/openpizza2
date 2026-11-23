// CriminalsPage_FillRecruitOptions: ported from Pizza Connection 2 at 0x4bf980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf980
#include "pc2_port.h"

void __cdecl CriminalsPage_FillRecruitOptions(void *arg1)

{
  int value1;
  int value2;
  uint8_t *uptr3;
  int value4;
  int value5;
  
                    /* Fills the criminal recruitment costs and counts. */
  DAT_0057d704 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value1 = Game_GetPlayerCity((intptr_t)DAT_0057d704);
  value4 = (10 - *(int *)(value1 + 0x58)) - *(int *)(value1 + 0x40);
  value1 = *(int *)((intptr_t)DAT_0057d704 + 0x48);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  value1 = *(int *)(value2 + 0xc20 + value1 * 4);
  value5 = (value4 * 50000) / 100;
  value2 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value2 + 0x8c) == 0) {
    if (*(int *)(value2 + 0x170) != 0) {
      value5 = (value5 * 0xf) / 10;
    }
  }
  else {
    value5 = 0;
  }
  Gadget_SetTextf(arg1,0x1f85,&DAT_005683a4,value5);
  value2 = Game_CountUnassignedObjectsByClass(DAT_0057c670,0x1f,'\x01');
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f98,0);
  Gadget_SetTextf(arg1,0x1f98,&DAT_005686f4,value2);
  UI_SetChildVisibleByID(arg1,0x1f86,(uint32_t)(0 < value2));
  if (value1 < 4) {
    UI_RemoveObjectByKey(arg1,0x1fa0);
    UI_RemoveObjectByKey(arg1,0x1fa3);
    UI_RemoveObjectByKey(arg1,0x1fa2);
    UI_RemoveObjectByKey(arg1,0x1fa1);
    UI_RemoveObjectByKey(arg1,0x1fa5);
    UI_RemoveObjectByKey(arg1,0x1fa4);
  }
  else {
    value5 = (value4 * 100000) / 100;
    value2 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value2 + 0x90) == 0) {
      if (*(int *)(value2 + 0x174) != 0) {
        value5 = (value5 * 0xf) / 10;
      }
    }
    else {
      value5 = 0;
    }
    Gadget_SetTextf(arg1,0x1fa2,&DAT_005683a4,value5);
    value2 = Game_CountUnassignedObjectsByClass(DAT_0057c670,0x1e,'\x01');
    UI_SetChildVisibleByID(arg1,0x1fa3,(uint32_t)(0 < value2));
    Window_GadgetNotify_Text_SetTextColor(arg1,0x1fa5,0);
    Gadget_SetTextf(arg1,0x1fa5,&DAT_005686f4,value2);
  }
  if (value1 < 5) {
    UI_RemoveObjectByKey(arg1,0x1f9a);
    UI_RemoveObjectByKey(arg1,0x1f9d);
    UI_RemoveObjectByKey(arg1,0x1f9b);
    UI_RemoveObjectByKey(arg1,0x1f9c);
    UI_RemoveObjectByKey(arg1,0x1f9f);
    UI_RemoveObjectByKey(arg1,0x1f9e);
  }
  else {
    value2 = (value4 * 200000) / 100;
    value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(value1 + 0x94) == 0) {
      if (*(int *)(value1 + 0x178) != 0) {
        value2 = (value2 * 0xf) / 10;
      }
    }
    else {
      value2 = 0;
    }
    Gadget_SetTextf(arg1,0x1f9c,&DAT_005683a4,value2);
    value1 = Game_CountUnassignedObjectsByClass(DAT_0057c670,0x1d,'\x01');
    UI_SetChildVisibleByID(arg1,0x1f9d,(uint32_t)(0 < value1));
    Window_GadgetNotify_Text_SetTextColor(arg1,0x1f9f,0);
    Gadget_SetTextf(arg1,0x1f9f,&DAT_005686f4,value1);
  }
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1e,0);
  Gadget_SetTextf(arg1,0x1f77,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1e,1);
  Gadget_SetTextf(arg1,0x1f76,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1e,2);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1d,0);
  Gadget_SetTextf(arg1,0x1f7d,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1d,1);
  Gadget_SetTextf(arg1,0x1f7c,&DAT_005686f4,uptr3);
  uptr3 = Economy_GetModifier(DAT_0057d704,0x1d,2);
  Gadget_SetTextf(arg1,0x1f7e,&DAT_005686f4,uptr3);
  SyndicateMenu_FillStaffCounts(arg1);
  return;
}
