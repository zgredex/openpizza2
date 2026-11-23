// CRT_Filebuf_Delete: ported from Pizza Connection 2 at 0x54cdab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cdab
#include "pc2_port.h"

LPVOID __thiscall CRT_Filebuf_Delete(void *self,uint8_t arg1)

{
  CRT_Filebuf_Destroy();
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
