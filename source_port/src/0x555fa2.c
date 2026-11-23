// FUN_00555fa2: ported from Pizza Connection 2 at 0x555fa2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555fa2
#include "pc2_port.h"

bool __cdecl FUN_00555fa2(LPVOID arg1,UINT_PTR arg2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(arg1,arg2);
  return BVar1 == 0;
}
