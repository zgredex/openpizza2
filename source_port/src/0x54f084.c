// CRT_Vsprintf: ported from Pizza Connection 2 at 0x54f084.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f084
#include "pc2_port.h"

int __cdecl CRT_Vsprintf(uint8_t *arg1,uint8_t *arg2,uint32_t *arg3)

{
  int value1;
  uint8_t *local_24;
  int local_20;
  uint8_t *local_1c;
  uint32_t local_18;
  
  local_1c = arg1;
  local_24 = arg1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  value1 = CRT_Output((int *)&local_24,arg2,arg3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    CRT_FlushStreamBuffer(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return value1;
}
