// FUN_00555f86: ported from Pizza Connection 2 at 0x555f86.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555f86
#include "pc2_port.h"

bool __cdecl FUN_00555f86(void *arg1,UINT_PTR arg2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(arg1,arg2);
  return BVar1 == 0;
}
