// Record_AssignVariant: ported from Pizza Connection 2 at 0x534bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534bc0
#include "pc2_port.h"

void __thiscall Record_AssignVariant(void *self,int arg1,int arg2)

{
  char cVar1;
  
                    /* Assigns a valid variant to a render record and re-applies it. */
  if (((-1 < arg2) && (arg2 < *(int *)((intptr_t)self + 100))) &&
     (*(char *)(*(int *)((intptr_t)self + 0x50) + 0x80 + arg2 * 0x98) != '\0')) {
    cVar1 = *(char *)(*(int *)((intptr_t)self + 0x4c) + 0x3e + arg1 * 0x48);
    if (cVar1 != '\0') {
      Record_ClearFlags48(self,arg1);
    }
    *(int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48) = arg2;
    if (cVar1 != '\0') {
      Record_SelectVariant(self,arg1,-1);
    }
  }
  return;
}
