// Person_CanContinuePath: ported from Pizza Connection 2 at 0x50e7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e7a0
#include "pc2_port.h"

uint32_t __fastcall Person_CanContinuePath(int arg1)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  
                    /* Tests whether a person's current path step is walkable. */
  if (*(int *)(arg1 + 200) != 0) {
    uvalue1 = Object_IsVisibleThisFrame(arg1);
    if ((CONCAT31(extraout_var,uvalue1) != 0) && (*(short *)(*(int *)(arg1 + 200) + 0x28) != -1)) {
      return 1;
    }
  }
  return 0;
}
