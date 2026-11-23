// Sound_ReloadSpeechSetIfNeeded: ported from Pizza Connection 2 at 0x547580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547580
#include "pc2_port.h"

void __fastcall Sound_ReloadSpeechSetIfNeeded(int *arg1)

{
  if (*(char *)((intptr_t)arg1 + 0xfe) != '\0') {
    Sound_LoadSpeechSet(arg1);
    *(uint8_t *)((intptr_t)arg1 + 0xfe) = 0;
  }
  return;
}
