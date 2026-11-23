// DeliveryMenu_FillProductRows: ported from Pizza Connection 2 at 0x4c1ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c1ae0
#include "pc2_port.h"

void __cdecl DeliveryMenu_FillProductRows(void *arg1,int arg2)

{
  int value1;
  bool flag2;
  int value3;
  int value4;
  int value5;
  uint32_t unaff_EDI;
  int local_4;
  
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_4 = *(int *)(value1 + 0x15c);
  if (local_4 < 9) {
    arg2 = 0;
  }
  else {
    local_4 = 8;
  }
  if (0 < local_4) {
    value4 = arg2 * 4;
    value5 = 0x4b0;
    do {
      value3 = IDMap_Lookup((void *)(value1 + 0x148),*(int *)(DAT_0057d72c + value4),(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,value5,value3 + 4);
      flag2 = LookupTable_HasKey(DAT_0057d724,*(int *)(value3 + 0x3c));
      if (flag2) {
        Window_GadgetNotify_Text_SetTextColor(arg1,value5,0);
        Window_GadgetNotify_Button_SetState(arg1,value5 + -0x7a,1);
        value3 = Storage_GetSlotShare(DAT_0057d724,*(int *)(value3 + 0x3c));
        Gadget_SetTextf(arg1,value5 + 100,(uint8_t *)s__d____00568834,value3);
      }
      else {
        Window_GadgetNotify_Text_SetTextColor(arg1,value5,0xff);
        Window_GadgetNotify_Button_SetState(arg1,value5 + -0x7a,0);
        Gadget_SetTextf(arg1,value5 + 100,&DAT_0056ad74,unaff_EDI);
      }
      value4 = value4 + 4;
      value3 = value5 + -0x4af;
      value5 = value5 + 1;
    } while (value3 < local_4);
  }
  return;
}
