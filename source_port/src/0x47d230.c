// Screen_AddRecordToList: ported from Pizza Connection 2 at 0x47d230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d230
#include "pc2_port.h"

void __thiscall Screen_AddRecordToList(void *self,int arg1)

{
  List_Add((void *)((intptr_t)self + 0x1744),*(uint32_t *)(arg1 + 0x164));
  return;
}
