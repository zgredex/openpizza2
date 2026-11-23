// Game_GetContextCompanyRating: ported from Pizza Connection 2 at 0x480760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480760
#include "pc2_port.h"

int64_t __fastcall Game_GetContextCompanyRating(int arg1,uint32_t arg2,int arg3)

{
  int64_t lvalue1;
  
  if (*(int *)(arg1 + 0x14c4) == 0) {
    return (uint64_t)arg2 << 0x20;
  }
  if (((arg3 != 0x11) && (arg3 != 0x13)) && (arg3 != 0x14)) {
    return (uint64_t)arg2 << 0x20;
  }
  arg3 = 3;
  do {
    arg3 = arg3 + -1;
  } while (arg3 != 0);
  Rating_GetComposite(*(int *)(arg1 + 0x14c4));
  lvalue1 = __ftol();
  return lvalue1;
}
