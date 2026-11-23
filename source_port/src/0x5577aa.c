// FUN_005577aa: ported from Pizza Connection 2 at 0x5577aa.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5577aa
#include "pc2_port.h"

int __cdecl FUN_005577aa(char *arg1,int arg2)

{
  char *cptr1;
  int value2;
  
  value2 = arg2;
  for (cptr1 = arg1; (value2 != 0 && (value2 = value2 + -1, *cptr1 != '\0')); cptr1 = cptr1 + 1)
  {
  }
  if (*cptr1 == '\0') {
    return (intptr_t)cptr1 - (intptr_t)arg1;
  }
  return arg2;
}
