// Company_AddLedgerAmount: ported from Pizza Connection 2 at 0x4e0c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0c40
#include "pc2_port.h"

void __thiscall
Company_AddLedgerAmount(void *self,int arg1,float arg2,uint32_t arg3,char arg4)

{
  void *this_00;
  float fVar1;
  int value2;
  int value3;
  int64_t lvalue4;
  
                    /* Adds an amount to company cash and the period ledger, then refreshes HUD. */
  if (arg3 == 0xffffffff) {
    value3 = *(int *)((intptr_t)self + 0x48);
    arg3 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if ((value3 == value2) && (arg4 == '\0')) {
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x14,-1);
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x17,-1);
      lvalue4 = __ftol();
      MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x14,(intptr_t)lvalue4,-1);
      MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x17,(intptr_t)lvalue4,-1);
    }
  }
  value3 = Game_FindRecordByField4(self,arg3);
  if (value3 != 0) {
    fVar1 = arg2 + (float)*(double *)((intptr_t)self + 0x108);
    *(double *)((intptr_t)self + 0x108) = (double)fVar1;
    if (1e+09 < fVar1) {
      *(uint32_t *)((intptr_t)self + 0x108) = 0xff800000;
      *(uint32_t *)((intptr_t)self + 0x10c) = 0x41cdcd64;
    }
    *(float *)(value3 + 0x10 + arg1 * 4) = arg2 + *(float *)(value3 + 0x10 + arg1 * 4);
    if (0.0 <= *(double *)((intptr_t)self + 0x108)) {
      Player_ResetDebtHours((intptr_t)self);
    }
  }
  if (*(int *)(DAT_0057c670 + 600) == 0) {
    value3 = *(int *)((intptr_t)self + 0x48);
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if ((value2 == value3) && (this_00 = *(void **)(DAT_0057c670 + 0x2d9c), this_00 != (void *)0x0)) {
      value3 = 0;
      lvalue4 = __ftol();
      Sound_UpdateListener(this_00,(uint32_t)lvalue4,(intptr_t)((uint64_t)lvalue4 >> 0x20),value3);
      value3 = 1;
      lvalue4 = __ftol();
      Sound_UpdateListener
                (this_00,*(uint32_t *)((intptr_t)this_00 + 0x1b0) + (uint32_t)lvalue4,
                 *(int *)((intptr_t)this_00 + 0x1b4) + (intptr_t)((uint64_t)lvalue4 >> 0x20) +
                 (uint32_t)CARRY4(*(uint32_t *)((intptr_t)this_00 + 0x1b0),(uint32_t)lvalue4),value3);
    }
    if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18648,0x23,0);
    }
  }
  return;
}
