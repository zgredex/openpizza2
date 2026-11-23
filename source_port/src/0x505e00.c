// Object_IsVisibleThisFrame: ported from Pizza Connection 2 at 0x505e00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505e00
#include "pc2_port.h"

uint8_t __fastcall Object_IsVisibleThisFrame(int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
                    /* Tests whether a map object has drawable content self frame. */
  ptr1 = *(int **)(arg1 + 200);
  if (ptr1 != (int *)0x0) {
    if (ptr1[0x10] != -1) {
      value3 = MapActor_UpdateLinkedOverlays(*(void **)(arg1 + 0xc4),ptr1);
      if (value3 != 0) {
        return 1;
      }
    }
    value3 = **(int **)(arg1 + 200);
    value2 = (*(int **)(arg1 + 200))[0x16];
    if ((-1 < value3) && (value3 < *(int *)(value2 + 0x48))) {
      return *(uint8_t *)(*(int *)(value2 + 0x4c) + 0x3e + value3 * 0x48);
    }
  }
  return 0;
}
