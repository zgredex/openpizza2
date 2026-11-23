// Game_CenterViewOnObject: ported from Pizza Connection 2 at 0x4d23b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d23b0
#include "pc2_port.h"

void __fastcall Game_CenterViewOnObject(int arg1)

{
  void *pvVar1;
  int value2;
  int local_8;
  int local_4;
  
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(arg1 + 0x28),(int *)0x0);
  pvVar1 = *(void **)(value2 + 0xfa8);
  if (pvVar1 != (void *)0x0) {
    local_4 = Game_GetObjectCenterY(arg1);
    local_8 = Game_GetObjectBottom(arg1);
    Rect_Center(&local_4,&local_8);
    Map_ScrollToClamped(DAT_0057c670,pvVar1,local_4,local_8);
  }
  return;
}
