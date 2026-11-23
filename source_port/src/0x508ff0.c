// Map_DetachObjectFromTile: ported from Pizza Connection 2 at 0x508ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508ff0
#include "pc2_port.h"

void __fastcall Map_DetachObjectFromTile(int arg1)

{
  void *self;
  int value1;
  
  self = (void *)Game_GetPlayerSubmapValue
                           (DAT_0057c670,*(int *)(*(int *)(arg1 + 0xf4) + 8),
                            *(int *)(*(int *)(arg1 + 0xf4) + 0x2c));
  if (self != (void *)0x0) {
    value1 = *(int *)(*(int *)(arg1 + 0xc4) + 0x1c);
    value1 = Game_FindRecordByPair
                      (self,*(int *)(arg1 + 0x88) % value1,*(int *)(arg1 + 0x88) / value1);
    if ((value1 != 0) && (*(int *)(value1 + 0x10) == *(int *)(arg1 + 0x164))) {
      *(uint32_t *)(value1 + 0x10) = 0;
    }
  }
  return;
}
