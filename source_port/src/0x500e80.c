// Game_GetPlayerSubrecord: ported from Pizza Connection 2 at 0x500e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500e80
#include "pc2_port.h"

int __thiscall Game_GetPlayerSubrecord(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)(*(int *)((intptr_t)self + arg1 * 0x168 + 0x70) + 0x148),arg2,
                       (int *)0x0);
  if (((arg3 != 0) && (value1 != 0)) && (*(char *)(value1 + 0x16f5) != '\0')) {
    value1 = 0;
  }
  return value1;
}
