// UI_Group_RemoveAt: ported from Pizza Connection 2 at 0x5324c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5324c0
#include "pc2_port.h"

uint32_t __thiscall UI_Group_RemoveAt(void *self,int arg1)

{
  LPVOID pvVar1;
  uint32_t uvalue2;
  
  pvVar1 = (LPVOID)Array_GetPtr((void *)((intptr_t)self + 0x148),arg1);
  if (pvVar1 == (LPVOID)0x0) {
    return 0;
  }
  uvalue2 = Array_RemoveAt((void *)((intptr_t)self + 0x148),arg1);
  UI_Group_DestroyMemberList((intptr_t)pvVar1);
  Mem_Free(pvVar1);
  return uvalue2;
}
