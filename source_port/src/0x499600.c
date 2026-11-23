// CreateRecipePage_FillIngredientDetails: ported from Pizza Connection 2 at 0x499600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x499600
#include "pc2_port.h"

void __cdecl CreateRecipePage_FillIngredientDetails(void *arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int64_t lvalue5;
  uint8_t local_40 [64];
  
                    /* Fills the create-recipe ingredient detail pane. */
  value3 = 0;
  value4 = 1;
  value1 = DAT_00568914;
  if (((DAT_00568914 < 0) && (value1 = arg2, arg2 < 0)) ||
     (value3 = IDMap_Lookup(DAT_0057ca20,value1,(int *)0x0), value3 == 0)) {
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
  value1 = *(int *)(value3 + 0xac + DAT_0057ca28 * 4);
  Window_GadgetNotify_Text_SetText(arg1,0x4fa,value3 + 0x88);
  String_Format(local_40,(uint8_t *)s__0_2f___005688b0,
                SUB84(*(double *)(value3 + 0xc0) * (double)value1 * 0.001,0));
  Window_GadgetNotify_Text_SetText(arg1,0x4e9,local_40);
  lvalue5 = __ftol();
  String_Format(local_40,&DAT_00568930,(intptr_t)lvalue5);
  Window_GadgetNotify_Text_SetText(arg1,0x4ea,local_40);
  switch(DAT_0057ca28) {
  case 0:
    uvalue2 = DAT_00582094;
    goto LAB_0049975a;
  case 1:
    uvalue2 = DAT_0058175c;
    break;
  case 2:
    uvalue2 = DAT_00582004;
    break;
  case 3:
    uvalue2 = DAT_00582568;
LAB_0049975a:
    break;
  default:
    goto switchD_00499721_default;
  }
  String_Format(local_40,&DAT_005630d0,uvalue2);
switchD_00499721_default:
  Window_GadgetNotify_Text_SetText(arg1,0x4f9,local_40);
  return;
}
