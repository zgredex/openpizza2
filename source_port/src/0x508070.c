// Object_ScrollViewToObject: ported from Pizza Connection 2 at 0x508070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508070
#include "pc2_port.h"

void __fastcall Object_ScrollViewToObject(void *arg1)

{
  int local_8;
  int local_4;
  
  if (((*(int *)((intptr_t)arg1 + 0xc4) != 0) && (*(int *)((intptr_t)arg1 + 200) != 0)) &&
     (*(int *)(*(int *)((intptr_t)arg1 + 200) + 0x58) != 0)) {
    MapObject_GetScreenPosition
              (arg1,(uint32_t)(*(int *)((intptr_t)arg1 + 0x74) != 0),&local_4,&local_8);
    Rect_Center(&local_4,&local_8);
    Map_ScrollToClamped(DAT_0057c670,*(void **)((intptr_t)arg1 + 0xc4),local_4,local_8);
  }
  return;
}
