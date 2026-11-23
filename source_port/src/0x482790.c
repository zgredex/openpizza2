// Game_AddObjectToRegistry: ported from Pizza Connection 2 at 0x482790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482790
#include "pc2_port.h"

int __thiscall Game_AddObjectToRegistry(void *self,void *arg1)

{
  int value1;
  
  value1 = List_Add((void *)((intptr_t)self + 0x3c),arg1);
  *(int *)((intptr_t)arg1 + 0x164) = value1;
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0xe:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x22:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
    break;
  default:
    Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xcc));
  }
  return value1;
}
