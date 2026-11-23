// ContestRecipePage_FillIngredientDetails: ported from Pizza Connection 2 at 0x49d300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d300
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ContestRecipePage_FillIngredientDetails(void *arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int64_t lvalue5;
  uint8_t local_40 [64];
  
                    /* Fills the contest recipe ingredient detail pane. */
  value3 = 0;
  value4 = 1;
  value1 = DAT_00568af4;
  if (((DAT_00568af4 < 0) && (value1 = arg2, arg2 < 0)) ||
     (value3 = IDMap_Lookup(DAT_0057cac8,value1,(int *)0x0), value3 == 0)) {
    value4 = 0;
  }
  UI_SetChildVisibleByID(arg1,0x4fa,value4);
  UI_SetChildVisibleByID(arg1,0x4f9,value4);
  UI_SetChildVisibleByID(arg1,0x4e9,value4);
  UI_SetChildVisibleByID(arg1,0x4ea,value4);
  UI_SetChildVisibleByID(arg1,0x449,value4);
  UI_SetChildVisibleByID(arg1,0x44c,value4);
  if (value3 == 0) {
    return;
  }
  value1 = *(int *)(value3 + 0xac + _DAT_0057cacc * 4);
  Window_GadgetNotify_Text_SetText(arg1,0x4fa,value3 + 0x88);
  String_Format(local_40,(uint8_t *)s__0_2f___005688b0,
                SUB84(*(double *)(value3 + 0xc0) * (double)value1 * 0.001,0));
  Window_GadgetNotify_Text_SetText(arg1,0x4e9,local_40);
  lvalue5 = __ftol();
  String_Format(local_40,&DAT_00568930,(intptr_t)lvalue5);
  Window_GadgetNotify_Text_SetText(arg1,0x4ea,local_40);
  switch(_DAT_0057cacc) {
  case 0:
    uvalue2 = DAT_00582094;
    goto LAB_0049d45a;
  case 1:
    uvalue2 = DAT_0058175c;
    break;
  case 2:
    uvalue2 = DAT_00582004;
    break;
  case 3:
    uvalue2 = DAT_00582568;
LAB_0049d45a:
    break;
  default:
    goto switchD_0049d421_default;
  }
  String_Format(local_40,&DAT_005630d0,uvalue2);
switchD_0049d421_default:
  Window_GadgetNotify_Text_SetText(arg1,0x4f9,local_40);
  return;
}
