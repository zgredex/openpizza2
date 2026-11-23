// Sound_UpdatePositionCountdown: ported from Pizza Connection 2 at 0x548510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548510
#include "pc2_port.h"

void __fastcall Sound_UpdatePositionCountdown(void *arg1)

{
  if ((*(char *)((intptr_t)arg1 + 0xfc) != '\0') && (*(char *)((intptr_t)arg1 + 0x169) == '\0')) {
    Sound_SetPosition(arg1,*(uint32_t *)((intptr_t)arg1 + 0x84));
    if (0 < *(int *)((intptr_t)arg1 + 0x144)) {
      *(uint8_t *)((intptr_t)arg1 + 0x169) = 1;
      *(int *)((intptr_t)arg1 + 0x144) = *(int *)((intptr_t)arg1 + 0x144) + -1;
      return;
    }
    *(uint32_t *)((intptr_t)arg1 + 0x144) = 3;
    *(uint8_t *)((intptr_t)arg1 + 0x169) = 1;
  }
  return;
}
