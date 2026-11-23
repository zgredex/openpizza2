// FUN_00555fd6: ported from Pizza Connection 2 at 0x555fd6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555fd6
#include "pc2_port.h"

void FUN_00555fd6(void)

{
  code *cptr1;
  
  CRT_NMsgWrite(10);
  FUN_00556a1e((DWORD *)0x16);
  __exit(3);
  cptr1 = (code *)swi(3);
  (*cptr1)();
  return;
}
