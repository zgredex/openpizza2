// UI_DestroyWindowAt: ported from Pizza Connection 2 at 0x482860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482860
#include "pc2_port.h"

void UI_DestroyWindowAt(uint32_t *arg1)

{
  uint32_t *uptr1;
  
  uptr1 = (uint32_t *)*arg1;
  *arg1 = 0;
  Window_DestroyChild(DAT_0057c5e0,uptr1);
  return;
}
