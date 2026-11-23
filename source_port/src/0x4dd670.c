// GameClock_Destroy: ported from Pizza Connection 2 at 0x4dd670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd670
#include "pc2_port.h"

void __fastcall GameClock_Destroy(uint32_t *arg1)

{
  int value1;
  int value2;
  
  value1 = arg1[9];
  *arg1 = &PTR_GameClock_Delete_0055c564;
  arg1[8] = 1;
                    /* Stops the game clock worker and restores its vtable. */
  for (value2 = 400; (value1 == 0 && (0 < value2)); value2 = value2 + -1) {
    Sleep(10);
    value1 = arg1[9];
  }
  return;
}
