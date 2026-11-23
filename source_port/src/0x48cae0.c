// Game_SetObjectInfoWindowVisible: ported from Pizza Connection 2 at 0x48cae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cae0
#include "pc2_port.h"

void __thiscall Game_SetObjectInfoWindowVisible(void *self,int arg1)

{
  int value1;
  
  if (*(int *)((intptr_t)self + 0x26c) != 0) {
    value1 = Object_GetId(*(int *)((intptr_t)self + 0x26c));
    if (*(int *)(*(int *)((intptr_t)self + 0x26c) + 0x4c) != arg1) {
      if (arg1 != 0) {
        Window_ShowWindowById(DAT_0057c5e0,value1);
        return;
      }
      Window_HideWindowById(DAT_0057c5e0,value1);
    }
  }
  return;
}
