// CRT_Streambuf_Construct: ported from Pizza Connection 2 at 0x54dac6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dac6
#include "pc2_port.h"

uint32_t * __fastcall CRT_Streambuf_Construct(uint32_t *arg1)

{
  arg1[3] = 0xffffffff;
  arg1[0xc] = 0xffffffff;
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[4] = 0;
  arg1[5] = 0;
  arg1[6] = 0;
  arg1[7] = 0;
  arg1[8] = 0;
  arg1[9] = 0;
  arg1[10] = 0;
  arg1[0xb] = 0;
  *arg1 = &PTR_CRT_Streambuf_Delete_0055ccc8;
  CS_Initialize((LPCRITICAL_SECTION)(arg1 + 0xd));
  return arg1;
}
