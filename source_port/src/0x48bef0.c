// Game_OpenObjectView: ported from Pizza Connection 2 at 0x48bef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bef0
#include "pc2_port.h"

void __thiscall Game_OpenObjectView(void *self,int arg1)

{
  int value1;
  
                    /* Opens the city or branch view for a selected object or person. */
  *(int *)((intptr_t)self + 0x21c) = arg1;
  *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
  if (*(int *)(arg1 + 0x74) == 0) {
    value1 = *(int *)((intptr_t)self + 0x290);
    if (((value1 != 1) && (value1 != 3)) && (value1 != 2)) {
      Game_SetViewMode(self,1,1);
      return;
    }
  }
  else {
    value1 = Game_GetPlayerSubmapValue
                      (self,*(int *)(*(int *)(arg1 + 0xfc) + 8),
                       *(int *)(*(int *)(arg1 + 0xfc) + 0x2c));
    if (value1 == 0) {
      return;
    }
    if (*(int *)((intptr_t)self + 0x290) != 4) {
      *(int *)((intptr_t)self + 0x9c) = value1;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
      Game_SetViewMode(self,4,1);
      return;
    }
  }
  SubMenu_SetSelection(self,0,arg1,0,1);
  return;
}
