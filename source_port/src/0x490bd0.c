// FurnitureMenu_ShowItemDetails: ported from Pizza Connection 2 at 0x490bd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x490bd0
#include "pc2_port.h"

void __cdecl FurnitureMenu_ShowItemDetails(void *arg1,int arg2)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  uint32_t uvalue4;
  double fVar5;
  uint8_t local_20 [32];
  
  if (arg2 == -1) {
    Window_GadgetNotify_Text_SetText(arg1,0x5a2,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x5a3,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x5a5,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,0x5a4,DAT_00582e4c);
    return;
  }
  value3 = arg2 / 3;
  uvalue4 = arg2 % 3;
  uvalue1 = DAT_00582638;
  if (DAT_0057c6a8 == 4) {
    if (uvalue4 == 0) {
      arg2 = 100;
    }
    else {
      if (uvalue4 != 1) {
        if (uvalue4 != 2) goto LAB_00490d59;
        arg2 = 6;
        goto LAB_00490d62;
      }
      arg2 = 200;
LAB_00490c9b:
      uvalue1 = DAT_00582010;
    }
LAB_00490ca0:
    String_Format(local_20,&DAT_005630d0,uvalue1);
    Window_GadgetNotify_Text_SetText(arg1,0x5a2,local_20);
    String_Format(local_20,&DAT_005630d0,DAT_00582850);
    Window_GadgetNotify_Text_SetText(arg1,0x5a5,local_20);
    String_Format(local_20,&DAT_005630d0,(&DAT_0058319c)[value3]);
    Window_GadgetNotify_Text_SetText(arg1,0x5a3,local_20);
    if ((float)arg2 == 100.0) {
      fVar5 = Building_GetAreaByLevel(value3);
    }
    else {
      fVar5 = Stats_GetAmountByType(value3);
    }
    String_Format(local_20,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar5,0));
    Window_GadgetNotify_Text_SetText(arg1,0x5a4,local_20);
  }
  else {
    if (DAT_0057c6a8 == 5) {
      arg2 = 5;
    }
    else {
      arg2 = DAT_0057c6a8 + 1;
LAB_00490d59:
      if (99 < arg2) {
        if (arg2 != 100) goto LAB_00490c9b;
        goto LAB_00490ca0;
      }
    }
LAB_00490d62:
    value2 = Game_FindRecordByTripleKey(DAT_0057c670,arg2,value3,uvalue4,(int *)0x0);
    if (value2 != 0) {
      String_Format(local_20,&DAT_005630d0,value2 + 0x18);
      Window_GadgetNotify_Text_SetText(arg1,0x5a2,local_20);
      String_Format(local_20,&DAT_005630d0,DAT_00582850);
      Window_GadgetNotify_Text_SetText(arg1,0x5a5,local_20);
      String_Format(local_20,&DAT_005630d0,(&DAT_0058319c)[value3]);
      Window_GadgetNotify_Text_SetText(arg1,0x5a3,local_20);
      value3 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                         *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      fVar5 = Game_ComputePrice(value2,value3);
      String_Format(local_20,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar5,0));
      Window_GadgetNotify_Text_SetText(arg1,0x5a4,local_20);
      return;
    }
  }
  return;
}
