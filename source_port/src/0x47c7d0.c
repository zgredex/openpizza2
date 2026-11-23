// MapObject_SettlePendingAmount: ported from Pizza Connection 2 at 0x47c7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c7d0
#include "pc2_port.h"

void __fastcall MapObject_SettlePendingAmount(void *arg1)

{
                    /* Applies an object's pending cash charge or credit. */
  if (*(float *)((intptr_t)arg1 + 0x171c) < 0.0) {
    Game_CanAfford(arg1,4,*(float *)((intptr_t)arg1 + 0x171c),'\0',-1);
  }
  if (0.0 < *(float *)((intptr_t)arg1 + 0x171c)) {
    Stats_AddRecordValue(arg1,0x15,*(float *)((intptr_t)arg1 + 0x171c),-1);
  }
  Object_SetIndex171C(arg1,0);
  return;
}
