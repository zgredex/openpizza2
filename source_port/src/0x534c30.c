// UI_SetListEntryPosition: ported from Pizza Connection 2 at 0x534c30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534c30
#include "pc2_port.h"

void __thiscall UI_SetListEntryPosition(int arg1,int arg2,uint64_t arg3)

{
  int value1;
  int64_t lvalue2;
  
  if ((-1 < arg2) || (arg2 < *(int *)(arg1 + 0x48))) {
    *(uint64_t *)(*(int *)(arg1 + 0x4c) + 0x28 + arg2 * 0x48) = arg3;
    value1 = *(int *)(arg1 + 0x4c);
    lvalue2 = __ftol();
    *(short *)(value1 + arg2 * 0x48 + 0x3a) = (short)lvalue2;
  }
  return;
}
