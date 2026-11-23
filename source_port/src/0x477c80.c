// Stats_AddRecordValue: ported from Pizza Connection 2 at 0x477c80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477c80
#include "pc2_port.h"

void __thiscall Stats_AddRecordValue(void *self,int arg1,float arg2,int arg3)

{
  void *this_00;
  double dVar1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  int64_t lvalue6;
  
                    /* Adds a value to a statistic record, player total, and matrix. */
  value2 = Stats_FindRecordByType(self,arg3);
  value4 = *(int *)((intptr_t)self + 0x30);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value4 == value3) {
    UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x14,-1);
    UI_AppendCommandIfActive(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x17,-1);
    lvalue6 = __ftol();
    MissionGoal_HandleEvent
              (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x14,(intptr_t)lvalue6,-1);
    MissionGoal_HandleEvent
              (*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x17,(intptr_t)lvalue6,-1);
  }
  if (value2 != 0) {
    *(float *)(value2 + 0x10 + arg1 * 4) = arg2 + *(float *)(value2 + 0x10 + arg1 * 4);
    value4 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
    dVar1 = *(double *)(value4 + 0x108) + (double)arg2;
    if (999999999.0 < dVar1) {
      dVar1 = 999999999.0;
    }
    *(double *)(value4 + 0x108) = dVar1;
    if (0.0 <= dVar1) {
      Player_ResetDebtHours(value4);
    }
  }
  if (arg1 < 9) {
    uvalue5 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
    value4 = uvalue5 + arg1 * 9;
    *(float *)((intptr_t)self + value4 * 4 + 0x2cc) = arg2 + *(float *)((intptr_t)self + value4 * 4 + 0x2cc);
  }
  if (*(int *)((intptr_t)DAT_0057c670 + 600) == 0) {
    value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if ((value4 == *(int *)((intptr_t)self + 0x30)) &&
       (this_00 = *(void **)((intptr_t)DAT_0057c670 + 0x2d9c), this_00 != (void *)0x0)) {
      value4 = 0;
      lvalue6 = __ftol();
      Sound_UpdateListener(this_00,(uint32_t)lvalue6,(intptr_t)((uint64_t)lvalue6 >> 0x20),value4);
      value4 = 1;
      lvalue6 = __ftol();
      Sound_UpdateListener
                (this_00,*(uint32_t *)((intptr_t)this_00 + 0x1b0) + (uint32_t)lvalue6,
                 *(int *)((intptr_t)this_00 + 0x1b4) + (intptr_t)((uint64_t)lvalue6 >> 0x20) +
                 (uint32_t)CARRY4(*(uint32_t *)((intptr_t)this_00 + 0x1b0),(uint32_t)lvalue6),value4);
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18648,0x23,0);
    }
  }
  return;
}
