// Game_EndOfQuarter: ported from Pizza Connection 2 at 0x4867e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4867e0
#include "pc2_port.h"

void __thiscall Game_EndOfQuarter(void *self,char *arg1)

{
  int value1;
  void *this_00;
  int value2;
  int *ptr3;
  uint32_t *uptr4;
  int value5;
  
                    /* Processes end-of-quarter updates for cities and companies. */
  ptr3 = (int *)((intptr_t)self + 0x200);
  value5 = 6;
  do {
    if (*ptr3 != 0) {
      Stats_AppendPeriodReport(*ptr3);
    }
    ptr3 = ptr3 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  value5 = *(int *)((intptr_t)self + 0x34);
  value2 = 0;
  if (0 < value5) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x20),value2,(int *)0x0);
      if (value1 != 0) {
        Rating_StoreDailyResults(value1);
      }
      value2 = value2 + 1;
    } while (value2 < value5);
  }
  ptr3 = (int *)((intptr_t)self + 0x224);
  value5 = 6;
  do {
    if (*ptr3 != 0) {
      NoOp_2();
    }
    ptr3 = ptr3 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  value2 = 0;
  value5 = *(int *)((intptr_t)self + 0x18);
  if (0 < value5) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),value2,(int *)0x0);
      if (this_00 != (void *)0x0) {
        City_ProcessQuarterEnd(this_00,(intptr_t)arg1);
      }
      value2 = value2 + 1;
    } while (value2 < value5);
  }
  value5 = 6;
  uptr4 = (uint32_t *)((intptr_t)self + 0x200);
  do {
    if ((void *)*uptr4 != (void *)0x0) {
      Company_ProcessDailyAccounting((void *)*uptr4,arg1);
    }
    uptr4 = uptr4 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  value5 = 6;
  uptr4 = (uint32_t *)((intptr_t)self + 0x200);
  do {
    if ((uint32_t *)*uptr4 != (uint32_t *)0x0) {
      Company_RecordDailyStatistics((uint32_t *)*uptr4);
    }
    uptr4 = uptr4 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  Game_DispatchQuarterlyVisitors((intptr_t)self);
  DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_EndofQuarter___d___0056813c,
                      (uint32_t)*(uint16_t *)(*(int *)((intptr_t)self + 0x94) + 10));
  if (*(void **)((intptr_t)self + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((intptr_t)self + 0x264),-0x1863c,0x23,0);
  }
  return;
}
