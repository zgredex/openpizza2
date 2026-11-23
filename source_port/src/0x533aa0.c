// Record_SelectVariant: ported from Pizza Connection 2 at 0x533aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533aa0
#include "pc2_port.h"

bool __thiscall Record_SelectVariant(void *self,int arg1,int arg2)

{
  int *ptr1;
  int value2;
  
                    /* Selects and applies a sprite variant for a render record. */
  ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48);
  if ((*(char *)((intptr_t)ptr1 + 0x3e) == '\x01') && (arg2 == *ptr1)) {
    return true;
  }
  if (arg2 != -1) {
    Record_AssignVariant(self,arg1,arg2);
  }
  value2 = Record_ApplyVariantState(self,arg1,0,0);
  return value2 != 0;
}
