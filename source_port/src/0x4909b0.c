// FurnitureMenu_UpdatePage: ported from Pizza Connection 2 at 0x4909b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4909b0
#include "pc2_port.h"

void __cdecl FurnitureMenu_UpdatePage(void *arg1)

{
  int value1;
  int value2;
  int *ptr3;
  uint32_t uvalue4;
  int value5;
  
                    /* Refreshes the furniture/decoration page. */
  DAT_0057c6a0 = *(void **)(DAT_0057c670 + 0x9c);
  IsoMap_MarkPlayerFootprints(*(void **)((intptr_t)DAT_0057c6a0 + 0x14e0),(intptr_t)DAT_0057c6a0);
  DAT_00568404 = 0xffffffff;
  DAT_0057c6a4 = *(int *)((intptr_t)DAT_0057c6a0 + 0x14d8);
  if (DAT_0057c6a4 == -1) {
    uvalue4 = DAT_00582afc;
  }
  else {
    uvalue4 = (&DAT_0058374c)[DAT_0057c6a4];
  }
  Gadget_SetText(arg1,0x4d1,uvalue4);
  value2 = 0x1f59;
  do {
    Array_SetField14ByKey(arg1,value2,0);
    value2 = value2 + 1;
  } while (value2 < 0x1f65);
  ptr3 = &DAT_00568420;
  do {
    UI_SetChildLabelText(arg1,*ptr3,1,(char *)0x0);
    ptr3 = ptr3 + 1;
  } while ((intptr_t)ptr3 < 0x568450);
  Window_GadgetNotify_Text_SetText(arg1,0x562,DAT_00582e4c);
  FurnitureMenu_RefreshSlots(arg1);
  UI_FillObjectWithPaletteColor(arg1,0x589,DAT_0057c6ac);
  Array_SetField14ByKey(arg1,0x589,0);
  Window_GadgetNotify_Text_SetText(arg1,0x5a2,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x5a3,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x5a5,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(arg1,0x5a4,DAT_00582e4c);
  value2 = 0;
  do {
    value5 = DAT_00582320;
    value1 = Branch_ComputeBuildingRating(DAT_0057c6a0,DAT_00582320,value2);
    Rating_UpdateBarByKey(arg1,0x559,value2,value1,value5);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
