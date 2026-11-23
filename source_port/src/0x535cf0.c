// PaletteList_Free: ported from Pizza Connection 2 at 0x535cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535cf0
#include "pc2_port.h"

void __fastcall PaletteList_Free(int *arg1)

{
  uint32_t *uptr1;
  int value2;
  
  if (*arg1 != 0) {
    value2 = 0;
    if (0 < arg1[2]) {
      do {
        uptr1 = *(uint32_t **)(*arg1 + value2 * 4);
        if (uptr1 != (uint32_t *)0x0) {
          Palette_Free(uptr1);
          Mem_Free(uptr1);
        }
        value2 = value2 + 1;
      } while (value2 < arg1[2]);
    }
    Mem_Free((LPVOID)*arg1);
  }
  if ((LPVOID)arg1[1] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[1]);
  }
  return;
}
