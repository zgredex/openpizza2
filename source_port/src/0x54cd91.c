// CRT_FileBuf_Construct: ported from Pizza Connection 2 at 0x54cd91.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cd91
#include "pc2_port.h"

uint32_t * __fastcall CRT_FileBuf_Construct(uint32_t *arg1)

{
  CRT_Streambuf_Construct(arg1);
  arg1[0x14] = 0;
  arg1[0x13] = 0xffffffff;
  *arg1 = &PTR_CRT_Filebuf_Delete_0055cc54;
  return arg1;
}
