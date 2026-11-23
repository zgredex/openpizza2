// CRT_Ios_Construct: ported from Pizza Connection 2 at 0x54d85d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d85d
#include "pc2_port.h"

uint32_t * __fastcall CRT_Ios_Construct(uint32_t *arg1)

{
  int value1;
  
  arg1[0xd] = 0xffffffff;
  arg1[1] = 0;
  arg1[3] = 0;
  arg1[4] = 0;
  arg1[8] = 0;
  arg1[9] = 0;
  arg1[0xc] = 0;
  arg1[7] = 0;
  *arg1 = &PTR_CRT_Ios_Delete_0055ccc0;
  arg1[2] = 4;
  arg1[10] = 6;
  *(uint8_t *)(arg1 + 0xb) = 0x20;
  CS_Initialize((LPCRITICAL_SECTION)(arg1 + 0xe));
  value1 = DAT_005855d0;
  DAT_005855d0 = DAT_005855d0 + 1;
  if (value1 == 0) {
    CS_Initialize((LPCRITICAL_SECTION)&DAT_00585598);
  }
  return arg1;
}
