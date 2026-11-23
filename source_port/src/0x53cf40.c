// Sprite_Destruct: ported from Pizza Connection 2 at 0x53cf40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53cf40
#include "pc2_port.h"


void __fastcall Sprite_Destruct(uint32_t *arg1)

{
  uint32_t *uptr1;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys an 8-bit sprite and its palette and pixel buffers. */
  puStack_8 = &LAB_0055adc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_Sprite_ScalarDeletingDestructor_0055c82c;
  local_4 = 0;
  if (*(char *)(arg1 + 0xd) == '\x01') {
    uptr1 = (uint32_t *)arg1[8];
    if (((uptr1 != (uint32_t *)0x0) && (*(short *)((intptr_t)uptr1 + 0x206) == -1)) &&
       (uptr1 != (uint32_t *)0x0)) {
      Palette_Free(uptr1);
      Mem_Free(uptr1);
    }
  }
  else {
    value2 = 0;
    if (*(char *)(arg1 + 0xd) != '\0') {
      do {
        uptr1 = *(uint32_t **)(arg1[9] + value2 * 4);
        if (((uptr1 != (uint32_t *)0x0) && (*(short *)((intptr_t)uptr1 + 0x206) == -1)) &&
           (uptr1 != (uint32_t *)0x0)) {
          Palette_Free(uptr1);
          Mem_Free(uptr1);
        }
        value2 = value2 + 1;
      } while (value2 < (intptr_t)(uint32_t)*(uint8_t *)(arg1 + 0xd));
    }
  }
  if ((LPVOID)arg1[0xb] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xb]);
  }
  if ((LPVOID)arg1[0xc] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xc]);
  }
  if ((LPVOID)arg1[0xf] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0xf]);
  }
  if ((LPVOID)arg1[9] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[9]);
  }
  local_4 = 0xffffffff;
  SpriteBase_Destructor(arg1);
  ExceptionList = local_c;
  return;
}
