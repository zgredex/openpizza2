// Game_HandleMapClickCloseSubmenu: ported from Pizza Connection 2 at 0x4c3000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3000
#include "pc2_port.h"

void __cdecl Game_HandleMapClickCloseSubmenu(uint32_t *arg1)

{
  void *self;
  int value1;
  int value2;
  
                    /* Handles map clicks that close a building submenu. */
  self = *(void **)(DAT_0057c670 + 0x9c);
  value1 = *(int *)((intptr_t)self + 0x14e0);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),arg1[1],(int *)0x0);
  if (((*(int *)(value2 + 8) == 1) || (*(int *)(value2 + 8) == 2)) &&
     (value2 = UI_IsClickOccluded(self,(intptr_t)arg1), value2 != 0)) {
    return;
  }
  *(uint32_t *)(DAT_0057c670 + 0x344) = 0xffffffff;
  *(uint32_t *)(value1 + 0x60) = 0;
  MapObject_RemoveFromMap(self,arg1);
  *(uint32_t *)(value1 + 0xf4) = 1;
  return;
}
