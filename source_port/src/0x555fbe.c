// FUN_00555fbe: ported from Pizza Connection 2 at 0x555fbe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555fbe
#include "pc2_port.h"

bool __cdecl FUN_00555fbe(FARPROC arg1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr(arg1);
  return BVar1 == 0;
}
