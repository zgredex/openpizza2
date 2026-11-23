// Screen_AddRecordToPanel: ported from Pizza Connection 2 at 0x509290.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509290
#include "pc2_port.h"

void __thiscall Screen_AddRecordToPanel(void *self,int arg1)

{
  List_Add((void *)((intptr_t)self + 0x114),*(uint32_t *)(arg1 + 0x164));
  return;
}
