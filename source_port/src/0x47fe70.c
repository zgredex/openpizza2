// Game_HideBuildingOverlay: ported from Pizza Connection 2 at 0x47fe70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fe70
#include "pc2_port.h"

void __thiscall Game_HideBuildingOverlay(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  int value3;
  
  if (arg1 == 1) {
    this_00 = *(void **)((intptr_t)self + 0x16f0);
    *(uint8_t *)((intptr_t)self + 0x1a20) = 0;
    value3 = 0;
    if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
      do {
        value1 = Game_MapRecordToGlobal(this_00,value3);
        value2 = State_Is1A1B1C(value1);
        if ((value2 != 0) && (*(int *)(value1 + 200) != 0)) {
          Object_SetChildShort(value1);
        }
        this_00 = *(void **)((intptr_t)self + 0x16f0);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)this_00 + 0x8c));
    }
  }
  return;
}
