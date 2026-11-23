// UI_FindFreeBriefing: ported from Pizza Connection 2 at 0x54b160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b160
#include "pc2_port.h"

uint32_t __fastcall UI_FindFreeBriefing(void *arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)arg1 + 0x18);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)arg1 + 4),value3,(int *)0x0);
      if (*(int *)(value2 + 0x14) == 0) {
        Sound_GetChannelObject(arg1,value3,0);
        return 1;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return 0;
}
