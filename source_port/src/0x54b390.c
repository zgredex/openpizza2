// MessageList_Construct: ported from Pizza Connection 2 at 0x54b390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b390
#include "pc2_port.h"

uint32_t * __fastcall MessageList_Construct(uint32_t *arg1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xf0);
  *arg1 = pvVar1;
  arg1[2] = 0x3c;
  arg1[1] = 0;
  return arg1;
}
