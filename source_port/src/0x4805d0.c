// Stats_ResetAverages: ported from Pizza Connection 2 at 0x4805d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4805d0
#include "pc2_port.h"

void __fastcall Stats_ResetAverages(void *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  uint32_t *uptr5;
  int value6;
  
  uptr5 = (uint32_t *)((intptr_t)arg1 + 0x1a08);
  for (value3 = 6; value3 != 0; value3 = value3 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  value3 = *(int *)((intptr_t)arg1 + 0x1514);
  value6 = 0;
  if (0 < value3) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value6,(int *)0x0);
      if (*(char *)(*ptr1 + 0x824) == '\0') {
        value4 = 9;
        value2 = ptr1[1] * 3;
        do {
          *(uint8_t *)((intptr_t)arg1 + 0x1a08 + value2) = 1;
          value2 = value2 + 1;
          if (0x17 < value2) {
            value2 = 0;
          }
          value4 = value4 + -1;
        } while (value4 != 0);
      }
      value6 = value6 + 1;
    } while (value6 < value3);
  }
  if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18693,0x23,0);
  }
  if (*(void **)(DAT_0057c670 + 0x25c) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18693,0x23,0);
  }
  Stats_BuildRanking(arg1);
  return;
}
