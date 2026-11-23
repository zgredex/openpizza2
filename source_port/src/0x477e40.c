// Game_CanAfford: ported from Pizza Connection 2 at 0x477e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477e40
#include "pc2_port.h"

uint32_t __thiscall Game_CanAfford(void *self,int arg1,float arg2,char arg3,int arg4)

{
  void *this_00;
  double dVar1;
  int value2;
  void *pvVar3;
  int64_t lvalue4;
  
  if (arg3 != '\0') {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
    dVar1 = *(double *)(value2 + 0x108) - (double)arg2;
    if (dVar1 < 0.0) {
      return CONCAT22((short)((uint32_t)value2 >> 0x10),
                      (uint16_t)(dVar1 < 0.0) << 8 | (uint16_t)NAN(dVar1) << 10 |
                      (uint16_t)(dVar1 == 0.0) << 0xe);
    }
  }
  value2 = Stats_FindRecordByType(self,arg4);
  if (value2 != 0) {
    *(float *)(value2 + 0x78 + arg1 * 4) = arg2 + *(float *)(value2 + 0x78 + arg1 * 4);
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
    *(double *)(value2 + 0x108) = *(double *)(value2 + 0x108) - (double)arg2;
  }
  pvVar3 = *(void **)((intptr_t)DAT_0057c670 + 600);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (pvVar3 == *(void **)((intptr_t)self + 0x30)) {
      this_00 = *(void **)((intptr_t)DAT_0057c670 + 0x2d9c);
      pvVar3 = DAT_0057c670;
      if (this_00 != (void *)0x0) {
        value2 = 0;
        lvalue4 = __ftol();
        Sound_UpdateListener(this_00,(uint32_t)lvalue4,(intptr_t)((uint64_t)lvalue4 >> 0x20),value2);
        value2 = 1;
        lvalue4 = __ftol();
        pvVar3 = (void *)Sound_UpdateListener
                                   (this_00,*(uint32_t *)((intptr_t)this_00 + 0x1b0) - (uint32_t)lvalue4,
                                    (*(int *)((intptr_t)this_00 + 0x1b4) -
                                    (intptr_t)((uint64_t)lvalue4 >> 0x20)) -
                                    (uint32_t)(*(uint32_t *)((intptr_t)this_00 + 0x1b0) < (uint32_t)lvalue4),value2);
      }
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
      pvVar3 = (void *)UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18648,0x23,0)
      ;
    }
  }
  return CONCAT31((int3)((uint32_t)pvVar3 >> 8),1);
}
