// AutosaveOptions_Init: ported from Pizza Connection 2 at 0x4a21f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a21f0
#include "pc2_port.h"

void __cdecl AutosaveOptions_Init(void *arg1)

{
  int *ptr1;
  int value2;
  
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f57,0,10,0);
  value2 = 0;
  ptr1 = &DAT_00568d88;
  do {
    if (DAT_0057b9f0 == *ptr1) break;
    ptr1 = ptr1 + 1;
    value2 = value2 + 1;
  } while ((intptr_t)ptr1 < 0x568db4);
  if (value2 == 0xb) {
    value2 = 2;
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f57,value2,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f57,1);
  Gadget_SetTextf(arg1,0x1f60,(uint8_t *)s__d__s_00568324,(&DAT_00568d88)[value2]);
  Gadget_SetTextf(arg1,0x1f5b,&DAT_005686f4,DAT_0057b9f8);
  Window_GadgetNotify_Button_SetState(arg1,0x1f5d,DAT_0057ba08);
  UI_DisableButton(arg1,0x1f5a);
  UI_DisableButton(arg1,0x1f5c);
  return;
}
