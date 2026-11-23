// Array_PickRandomActiveRecord28: ported from Pizza Connection 2 at 0x4f12c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f12c0
#include "pc2_port.h"

void __thiscall Array_PickRandomActiveRecord28(void *self,int *arg1)

{
  int value1;
  
  do {
    value1 = Array_GetRandomRecord28B(self,arg1);
  } while (*(char *)(value1 + 6) != '\0');
  return;
}
