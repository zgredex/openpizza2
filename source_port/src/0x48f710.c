// CompanyRating_InitHeaderRow: ported from Pizza Connection 2 at 0x48f710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48f710
#include "pc2_port.h"

void __cdecl CompanyRating_InitHeaderRow(void *arg1)

{
  int value1;
  int64_t lvalue2;
  int value3;
  
                    /* Fills the rating header rank and selected rating value. */
  value1 = *(int *)(DAT_0057c670 + 0x9c);
  if ((*(char *)(value1 + 0x16f5) == '\0') && (*(int *)(value1 + 0x2c) == 0)) {
    if ((*(int *)(value1 + 0x38) == 0) || (*(int *)(value1 + 0x38) == 1)) {
      Gadget_SetTextf(arg1,0x4eb,(uint8_t *)s__d__s_00568324,2);
    }
    UI_ShowChildByID(arg1,0x44f);
  }
  else {
    UI_RemoveObjectByKey(arg1,0x44f);
    value3 = *(int *)(*(int *)(value1 + 0x16f0) + 0x38);
    if (value3 == 0) {
      if ((*(int *)(value1 + 0x38) != 0) && (*(int *)(value1 + 0x38) != 1)) goto LAB_0048f7c6;
      value3 = 2;
    }
    Gadget_SetTextf(arg1,0x4eb,(uint8_t *)s__d__s_00568324,value3);
  }
LAB_0048f7c6:
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(value1 + 0x34),(int *)0x0);
  lvalue2 = Stats_GetCombinedValue(1,*(int *)(value1 + 0x38));
  value3 = (intptr_t)lvalue2;
  value1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x11c) == 0) {
    if (*(int *)(value1 + 0x200) != 0) {
      value3 = (value3 * 0xf) / 10;
    }
  }
  else {
    value3 = (value3 * 5) / 10;
  }
  Gadget_SetTextf(arg1,0x4ee,&DAT_005683a4,value3);
  return;
}
