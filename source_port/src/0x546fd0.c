// Random_Range: ported from Pizza Connection 2 at 0x546fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x546fd0
#include "pc2_port.h"

int __thiscall Random_Range(void *self,int arg1,int arg2)

{
  DWORD DVar1;
  int value2;
  
  DVar1 = GetCurrentThreadId();
  if (*(DWORD *)self != DVar1) {
    DVar1 = timeGetTime();
    CRT_Srand(DVar1);
    DVar1 = GetCurrentThreadId();
    *(DWORD *)self = DVar1;
  }
  value2 = _rand();
  value2 = value2 * ((arg2 - arg1) + 1);
  value2 = ((intptr_t)(value2 + (value2 >> 0x1f & 0x7fffU)) >> 0xf) + arg1;
  if (value2 < arg1) {
    return arg1;
  }
  if (arg2 < value2) {
    value2 = arg2;
  }
  return value2;
}
