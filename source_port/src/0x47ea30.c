// Branch_UpdateConstructionQueue: ported from Pizza Connection 2 at 0x47ea30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ea30
#include "pc2_port.h"

void __fastcall Branch_UpdateConstructionQueue(void *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
  value2 = 0;
  value3 = *(int *)((intptr_t)arg1 + 0x19ac) + -1;
  if (-1 < value3) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1998),value3,(int *)0x0);
      if (*ptr1 < 1) {
        Branch_CancelConstructionAt(arg1,(intptr_t)ptr1);
      }
      if (ptr1[7] != 0) {
        value2 = value2 + *ptr1;
      }
      value3 = value3 + -1;
    } while (-1 < value3);
    if (49999 < value2) {
      *(uint32_t *)((intptr_t)arg1 + 0x1a24) = 0;
    }
  }
  if ((*(void **)(DAT_0057c670 + 0x9c) == arg1) &&
     (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x1860c,0x23,0);
  }
  Game_UpdateObjectList2((intptr_t)arg1);
  return;
}
