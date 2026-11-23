// Object_CanDetach: ported from Pizza Connection 2 at 0x50abc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50abc0
#include "pc2_port.h"

uint32_t __fastcall Object_CanDetach(void *arg1)

{
  if ((*(int *)((intptr_t)arg1 + 0x38) == 0x2e) || (*(int *)((intptr_t)arg1 + 0x38) == 0x1f)) {
    if (*(int *)((intptr_t)arg1 + 0x74) != 0) {
      Game_RemoveObjectFromList(*(void **)((intptr_t)arg1 + 0xf4),arg1,0);
      return 1;
    }
    if (*(char *)((intptr_t)arg1 + 0x104) != '\0') {
      if (*(void **)((intptr_t)arg1 + 0xfc) != (void *)0x0) {
        Game_RemoveObjectFromList(*(void **)((intptr_t)arg1 + 0xfc),arg1,0);
      }
      return 1;
    }
  }
  if (((*(int *)((intptr_t)arg1 + 0x30) == 0x23) && (*(char *)((intptr_t)arg1 + 0x104) != '\0')) &&
     (*(int *)((intptr_t)arg1 + 0x74) == 0)) {
    return 1;
  }
  return 0;
}
