// SubStartMenu_FillOptions: ported from Pizza Connection 2 at 0x4c7d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c7d80
#include "pc2_port.h"

void __cdecl SubStartMenu_FillOptions(void *arg1)

{
  int *ptr1;
  int value2;
  uint8_t local_10 [4];
  uint8_t local_c;
  uint32_t uStack_b;
  uint32_t local_8;
  uint32_t local_4;
  
  Options_GetGlobalSettings((uint32_t *)local_10);
  Window_GadgetNotify_Slider_SetRange(arg1,8000,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,8000,CONCAT31(uStack_b,local_c),0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,8000,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f41,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f41,local_8,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f41,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f42,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f42,local_4,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f42,1);
  Window_GadgetNotify_Button_SetState(arg1,0x1f44,stack0xfffffff1 & 0xff);
  if (DAT_0057b9dc < 0) {
    value2 = 0;
  }
  else {
    value2 = DAT_0057b9dc;
    if (3 < DAT_0057b9dc) {
      value2 = 3;
    }
  }
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f45,0,3,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f45,1);
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f45,value2,0);
  Window_GadgetNotify_Text_SetText(arg1,0x1f46,(&DAT_00583878)[value2]);
  Window_GadgetNotify_Slider_SetRange(arg1,0x1f47,0,10,0);
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
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f47,value2,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x1f47,1);
  Gadget_SetTextf(arg1,0x1f48,(uint8_t *)s__d__s_00568324,(&DAT_00568d88)[value2]);
  return;
}
