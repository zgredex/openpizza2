// Sound_DestroyObject: ported from Pizza Connection 2 at 0x54c5b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c5b0
#include "pc2_port.h"

void __fastcall Sound_DestroyObject(int arg1)

{
  ResourceCache_FreeEntryMaps(arg1);
  if (*(uint32_t **)(arg1 + 0x2c) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x2c))(1);
    *(uint32_t *)(arg1 + 0x2c) = 0;
  }
  if (*(uint32_t **)(arg1 + 4) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 4))(1);
    *(uint32_t *)(arg1 + 4) = 0;
  }
  if (*(uint32_t **)(arg1 + 0xc) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0xc))(1);
    *(uint32_t *)(arg1 + 0xc) = 0;
  }
  if (*(uint32_t **)(arg1 + 0x10) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x10))(1);
    *(uint32_t *)(arg1 + 0x10) = 0;
  }
  if (*(uint32_t **)(arg1 + 0x14) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x14))(1);
    *(uint32_t *)(arg1 + 0x14) = 0;
  }
  if (*(uint32_t **)(arg1 + 8) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 8))(1);
    *(uint32_t *)(arg1 + 8) = 0;
  }
  if (*(uint32_t **)(arg1 + 0x28) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x28))(1);
    *(uint32_t *)(arg1 + 0x28) = 0;
  }
  return;
}
