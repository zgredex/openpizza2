// Game_CloseSelectionDialog: ported from Pizza Connection 2 at 0x482890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482890
#include "pc2_port.h"

void __fastcall Game_CloseSelectionDialog(int arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
  if (*(int *)(arg1 + 0x27c) != 0) {
    value1 = *(int *)(*(int *)(arg1 + 0x27c) + 0x14);
    value3 = 0;
    if (0 < value1) {
      do {
        uptr2 = (uint32_t *)IDMap_Lookup(*(void **)(arg1 + 0x27c),value3,(int *)0x0);
        if (uptr2 != (uint32_t *)0x0) {
          (**(code **)*uptr2)(1);
        }
        value3 = value3 + 1;
      } while (value3 < value1);
    }
    if (*(uint32_t **)(arg1 + 0x27c) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 0x27c))(1);
    }
    *(uint32_t *)(arg1 + 0x27c) = 0;
  }
  UI_DestroyWindowAt((uint32_t *)(arg1 + 0x268));
  *(uint32_t *)(arg1 + 0x270) = 0;
  *(uint32_t *)(arg1 + 0x280) = 0;
  return;
}
