// CompanyOverview_InitWindow: ported from Pizza Connection 2 at 0x4b3fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b3fb0
#include "pc2_port.h"


void __cdecl CompanyOverview_InitWindow(void *arg1,char arg2)

{
  int value1;
  void *extraout_ECX;
  void *self;
  int value2;
  uint32_t uvalue3;
  uint32_t unaff_EDI;
  int *ptr4;
  uint8_t local_20 [32];
  
                    /* Initializes the company-overview page, rows, slider, and chart. */
  UI_SetPosition(arg1,&LAB_004b3d20,0);
  if (DAT_0057d698 != 0) {
    UI_ReleaseRefCount(DAT_0057c5e0,DAT_0057d698);
  }
  DAT_0057d698 = UI_LoadFontByName(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  if (arg2 != '\0') {
    UI_Group_Create(arg1,0,3,0x3f8);
  }
  Window_GadgetNotify_Button_SetState(arg1,DAT_0057d69c + 0x3f8,1);
  value2 = 0;
  ptr4 = &DAT_0056a7b0;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value2 + 0x3fb,(uint32_t)(uint8_t)(&DAT_0056a734)[*ptr4]);
    ptr4 = ptr4 + 1;
    value2 = value2 + 1;
  } while ((intptr_t)ptr4 < 0x56a7d4);
  _param_2 = Game_CountActiveCompanies
                       (*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if (DAT_0056a7d4 != -1) {
    value2 = *(int *)(DAT_0057c670 + 0x9c);
    if (value2 != 0) {
      DAT_0056a7d4 = *(int *)(value2 + 0x3c);
      Gadget_SetText(arg1,0x3f6,value2 + 4);
      if (*(int *)(value2 + 0x14dc) != 0) {
        _param_2 = _param_2 + 1;
      }
      goto LAB_004b40e1;
    }
    DAT_0056a7d4 = -1;
  }
  Gadget_SetText(arg1,0x3f6,DAT_00581004);
LAB_004b40e1:
  String_Format(local_20,DAT_00582e4c,unaff_EDI);
  Window_GadgetNotify_Text_SetText(arg1,0x41e,local_20);
  Window_GadgetNotify_Text_SetText(arg1,0x41f,local_20);
  uvalue3 = (uint32_t)(_param_2 != 0);
  UI_SetChildVisibleByID(arg1,0x3f2,uvalue3);
  DAT_0057d694 = 0;
  ptr4 = &DAT_0056a740;
  value2 = 0x3ea;
  do {
    UI_SetChildVisibleByID(arg1,value2 + 0x23,uvalue3);
    UI_SetChildVisibleByID(arg1,value2,uvalue3);
    UI_SetChildVisibleByID(arg1,*ptr4,uvalue3);
    UI_SetChildVisibleByID(arg1,value2 + 6999,uvalue3);
    ptr4 = ptr4 + 1;
    value1 = value2 + -0x3e9;
    value2 = value2 + 1;
  } while (value1 < 8);
  self = (void *)0x0;
  if (DAT_0057d6a4 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057d6a4)(1);
    DAT_0057d6a4 = (uint32_t *)0x0;
    self = extraout_ECX;
  }
  if (0 < _param_2) {
    CompanyOverview_BuildCompanyList(self,arg1);
    if (_param_2 < 9) {
      UI_RemoveObjectByKey(arg1,0x3f2);
      _param_2 = 8 - _param_2;
      if (0 < _param_2) {
        value2 = 0x414;
        ptr4 = &DAT_0056a75c;
        do {
          UI_RemoveObjectByKey(arg1,value2 + -0x23);
          UI_RemoveObjectByKey(arg1,value2);
          UI_RemoveObjectByKey(arg1,*ptr4);
          UI_RemoveObjectByKey(arg1,value2 + 0x1b34);
          ptr4 = ptr4 + -1;
          value2 = value2 + -1;
          _param_2 = _param_2 + -1;
        } while (_param_2 != 0);
      }
    }
    else {
      DAT_0057d694 = 0;
      if (_param_2 < 8) {
        DAT_0057d694 = _param_2 + -8;
      }
      Window_GadgetNotify_Slider_SetRange(arg1,0x3f2,0,(_param_2 * 5 + -0x28) * 0x14,0);
      Window_GadgetNotify_Slider_SetValue(arg1,0x3f2,DAT_0057d694 * 100,0);
      Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x3f2,1);
    }
    CompanyOverview_UpdateCompanyRows(arg1,DAT_0057d694);
  }
  CompanyOverview_DrawQuarterChart(arg1);
  return;
}
