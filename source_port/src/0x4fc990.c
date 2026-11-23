// UI_ShiftRowData: ported from Pizza Connection 2 at 0x4fc990.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc990
#include "pc2_port.h"

void __thiscall UI_ShiftRowData(void *self,void *arg1,int arg2)

{
  int value1;
  void *this_00;
  int value2;
  uint32_t *uptr3;
  int value4;
  
  if ((arg2 != 0) ||
     (1 < (intptr_t)((uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) -
               *(int *)((intptr_t)arg1 + 0x40)))) {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
    value1 = *(int *)(value1 + 0x4c);
    value2 = *(int *)((intptr_t)arg1 + 0x34);
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),value2,(int *)0x0);
    value4 = 3;
    value1 = value1 * 0x168 + value2 * 0x10;
    uptr3 = (uint32_t *)((intptr_t)self + value1 + 0x144);
    do {
      *uptr3 = uptr3[-1];
      uptr3 = uptr3 + -1;
      value4 = value4 + -1;
    } while (value4 != 0);
    value2 = Array_FindIndexByPtr(this_00,*(int *)((intptr_t)arg1 + 0x16f0));
    *(int *)((intptr_t)self + value1 + 0x138) = value2;
    Game_MarkObjectsDirtyForState(arg1,6);
    Array_ClearStride34((intptr_t)arg1);
  }
  return;
}
