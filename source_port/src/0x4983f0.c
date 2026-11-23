// RecipeListPanel_Update: ported from Pizza Connection 2 at 0x4983f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4983f0
#include "pc2_port.h"


void __cdecl RecipeListPanel_Update(int *arg1)

{
  void *pvVar1;
  uint32_t *uptr2;
  int *self;
  uint32_t uvalue3;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  int value7;
  
                    /* Fills the company recipe list page and summary. */
  self = arg1;
  UI_SetPosition(arg1,&LAB_00498160,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uptr2 = *(uint32_t **)((intptr_t)pvVar1 + 0x124);
  Game_ResizeGlobalArray3(uptr2);
  DAT_0057c9fc = Game_FindCompanyIndex(pvVar1,*(int *)(DAT_0057c670 + 0x98));
  if ((DAT_0057c9fc < 0) && (0 < (intptr_t)uptr2)) {
    uvalue3 = IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x110),0,(int *)0x0);
    *(uint32_t *)(DAT_0057c670 + 0x98) = uvalue3;
    DAT_0057c9fc = Game_FindCompanyIndex(pvVar1,*(int *)(DAT_0057c670 + 0x98));
  }
  uvalue5 = (uint32_t)(uptr2 != (uint32_t *)0x0);
  UI_SetChildVisibleByID(arg1,0x428,uvalue5);
  UI_SetChildVisibleByID(arg1,0x454,uvalue5);
  UI_SetChildVisibleByID(arg1,0x455,uvalue5);
  UI_SetChildVisibleByID(arg1,0x4f9,uvalue5);
  UI_SetChildVisibleByID(arg1,0x4fa,uvalue5);
  UI_SetChildVisibleByID(arg1,0x4fb,uvalue5);
  UI_SetChildVisibleByID(arg1,0x44e,uvalue5);
  UI_SetChildVisibleByID(arg1,0x451,uvalue5);
  UI_SetChildVisibleByID(arg1,0x452,uvalue5);
  DAT_0057ca00 = (uint32_t *)0x0;
  arg1 = &DAT_00568890;
  value6 = 0x505;
  do {
    UI_SetChildVisibleByID(self,value6 + -0xa4,uvalue5);
    UI_SetChildVisibleByID(self,value6,uvalue5);
    UI_SetChildVisibleByID(self,*arg1,uvalue5);
    arg1 = arg1 + 1;
    value7 = value6 + -0x504;
    value6 = value6 + 1;
  } while (value7 < 8);
  if (uptr2 == (uint32_t *)0x0) {
    value6 = 0;
    do {
      Rating_UpdateBarByKey(self,0x4f0,value6,0,0);
      value6 = value6 + 1;
    } while (value6 < 8);
  }
  else {
    if ((intptr_t)uptr2 < 9) {
      UI_RemoveObjectByKey(self,0x428);
      value6 = 8 - (intptr_t)uptr2;
      if (0 < value6) {
        value7 = 0x50c;
        ptr4 = &DAT_005688ac;
        do {
          UI_RemoveObjectByKey(self,value7 + -0xa4);
          UI_RemoveObjectByKey(self,value7);
          UI_RemoveObjectByKey(self,*ptr4);
          value7 = value7 + -1;
          ptr4 = ptr4 + -1;
          value6 = value6 + -1;
        } while (value6 != 0);
      }
    }
    else {
      DAT_0057ca00 = (uint32_t *)GlobalArray_FindInt(DAT_0057c9fc,(intptr_t)uptr2);
      if ((intptr_t)uptr2 < (intptr_t)(DAT_0057ca00 + 2)) {
        DAT_0057ca00 = uptr2 + -2;
      }
      Window_GadgetNotify_Slider_SetRange(self,0x428,0,((intptr_t)uptr2 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(self,0x428,(intptr_t)DAT_0057ca00 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(self,0x428,1);
    }
    BranchList_UpdateRows(self,(intptr_t)DAT_0057ca00);
    BranchList_UpdateSummary(self);
    pvVar1 = *(void **)(DAT_0057c670 + 0x98);
    if (pvVar1 == (void *)0x0) {
      value6 = 0;
      do {
        Rating_UpdateBarByKey(self,0x4f0,value6,0,0);
        value6 = value6 + 1;
      } while (value6 < 8);
    }
    else {
      value6 = 0;
      do {
        value7 = Game_MapInputIndex(pvVar1,value6);
        Rating_UpdateBarByKey(self,0x4f0,value6,value7,DAT_0058155c);
        value6 = value6 + 1;
      } while (value6 < 8);
    }
  }
  Window_GadgetNotify_Text_SetText(self,0x44d,DAT_00581e34);
  return;
}
