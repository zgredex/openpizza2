// FurnitureMenu_InitChairPage: ported from Pizza Connection 2 at 0x4c3070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3070
#include "pc2_port.h"


void __cdecl FurnitureMenu_InitChairPage(void *arg1)

{
  void *pvVar1;
  int value2;
  uint32_t extraout_EDX;
  uint32_t uvalue3;
  uint32_t extraout_EDX_00;
  int value4;
  
                    /* Initializes the chair-selection submenu page. */
  *(uint32_t *)(DAT_0057c5e0 + 0x831c) = 1;
  UI_Group_ClearAll((intptr_t)arg1);
  UI_Group_Create(arg1,0,3,0x1f63);
  DAT_0056adec = 2;
  Window_GadgetNotify_Button_SetState(arg1,0x1f65,1);
  UI_SetPosition(arg1,&LAB_004c2ba0,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x9c);
  Window_UpdateFurniturePage(arg1);
  value4 = 0;
  uvalue3 = extraout_EDX;
  do {
    value2 = Branch_ComputeBuildingRating(pvVar1,uvalue3,value4);
    Rating_UpdateBarByKey(arg1,0x559,value4,value2,DAT_00582320);
    value4 = value4 + 1;
    uvalue3 = extraout_EDX_00;
  } while (value4 < 8);
  return;
}
