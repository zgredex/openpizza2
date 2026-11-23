// UI_Child_Activate: ported from Pizza Connection 2 at 0x520e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520e30
#include "pc2_port.h"

void __fastcall UI_Child_Activate(int arg1)

{
                    /* Activates a UI child once, selecting its group member and dirtying its rect.
                        */
  if (*(int *)(arg1 + 0x20) == 0) {
    *(uint32_t *)(arg1 + 0x20) = 1;
    UI_Group_SelectMemberByKey(*(void **)(arg1 + 8),*(int *)(arg1 + 4));
    UI_ClipRect(*(void **)(arg1 + 8),(int *)(arg1 + 0x28),1);
  }
  return;
}
