// List_DestroyObjects: ported from Pizza Connection 2 at 0x540f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540f60
#include "pc2_port.h"

void __fastcall List_DestroyObjects(int arg1)

{
  int *ptr1;
  uint32_t *uptr2;
  
  uptr2 = *(uint32_t **)(arg1 + 0x38);
  *(uint32_t **)(arg1 + 0x40) = uptr2;
  if (uptr2 != (uint32_t *)0x0) {
    *(uint32_t *)(arg1 + 0x40) = uptr2[1];
    while( true ) {
      ptr1 = (int *)*uptr2;
      (**(code **)(*ptr1 + 0x48))(ptr1);
      (**(code **)(*ptr1 + 8))(ptr1);
      if (*(uint32_t **)(arg1 + 0x40) == uptr2) {
        *(uint32_t *)(arg1 + 0x40) = (*(uint32_t **)(arg1 + 0x40))[1];
      }
      if (uptr2[2] == 0) {
        *(uint32_t *)(arg1 + 0x38) = uptr2[1];
      }
      else {
        *(uint32_t *)(uptr2[2] + 4) = uptr2[1];
      }
      if (uptr2 == *(uint32_t **)(arg1 + 0x3c)) {
        *(uint32_t *)(arg1 + 0x3c) = uptr2[2];
      }
      if (uptr2[1] != 0) {
        *(uint32_t *)(uptr2[1] + 8) = uptr2[2];
      }
      *(int *)(arg1 + 0x44) = *(int *)(arg1 + 0x44) + -1;
      Mem_Free(uptr2);
      uptr2 = *(uint32_t **)(arg1 + 0x40);
      if (uptr2 == (uint32_t *)0x0) break;
      *(uint32_t *)(arg1 + 0x40) = uptr2[1];
    }
  }
  return;
}
