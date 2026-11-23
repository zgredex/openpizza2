// SoundBuffer_ConstructBase: ported from Pizza Connection 2 at 0x53fc40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fc40
#include "pc2_port.h"

uint32_t * __fastcall SoundBuffer_ConstructBase(uint32_t *arg1)

{
  uint32_t *uptr1;
  int value2;
  
  arg1[1] = 1;
  *arg1 = &PTR_LAB_0055c840;
  arg1[0x8e] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x8f));
  arg1[0x18a] = 0;
  *arg1 = &PTR_LAB_0055c864;
  *(uint8_t *)(arg1 + 0x149) = 0;
  uptr1 = arg1 + 0x9a;
  value2 = 0x14;
  do {
    *uptr1 = 0;
    uptr1 = uptr1 + 9;
    value2 = value2 + -1;
  } while (value2 != 0);
  return arg1;
}
