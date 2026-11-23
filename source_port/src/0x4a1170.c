// SoundOptions_Init: ported from Pizza Connection 2 at 0x4a1170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1170
#include "pc2_port.h"


void __cdecl SoundOptions_Init(void *arg1)

{
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  Options_GetGlobalSettings(&local_10);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43a,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x43a,local_c,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43a,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43b,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x43b,local_8,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43b,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43c,0,10000,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x43c,local_4,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43c,1);
  Window_GadgetNotify_Button_SetState(arg1,0x1f53,(uint32_t)(((uint8_t)((local_10) >> 8)) == '\0'));
  return;
}
