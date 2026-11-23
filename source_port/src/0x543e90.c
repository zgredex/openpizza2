// Sound_QueryFormatType: ported from Pizza Connection 2 at 0x543e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x543e90
#include "pc2_port.h"

uint32_t __fastcall Sound_QueryFormatType(int arg1)

{
  int value1;
  
  value1 = (**(code **)(**(int **)(arg1 + 0x48) + 0xc))(*(int **)(arg1 + 0x48));
  if (value1 < 0) {
    return 0;
  }
  return 0xc;
}
