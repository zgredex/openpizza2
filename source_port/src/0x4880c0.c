// Game_UpdateLoadProgress: ported from Pizza Connection 2 at 0x4880c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4880c0
#include "pc2_port.h"

int64_t __cdecl Game_UpdateLoadProgress(int *arg1,int arg2)

{
  int value1;
  int64_t lvalue2;
  
  value1 = Stream_GetReadPosition(arg1);
  if (arg2 < 1) {
    value1 = 0x14;
  }
  else {
    value1 = (value1 * 0x50) / arg2 + 0x14;
  }
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,value1,0);
  lvalue2 = Window_ProcessMessageQueue(DAT_0057c5e0,0);
  return lvalue2;
}
