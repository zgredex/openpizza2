// List_FreeValuesAndObject: ported from Pizza Connection 2 at 0x54c810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c810
#include "pc2_port.h"

void __fastcall List_FreeValuesAndObject(int *arg1)

{
  List_FreeContainerValues(arg1);
  if ((uint32_t *)*arg1 != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)*arg1)(1);
    *arg1 = 0;
  }
  return;
}
