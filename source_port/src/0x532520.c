// UI_Group_ClearAll: ported from Pizza Connection 2 at 0x532520.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532520
#include "pc2_port.h"

uint32_t __fastcall UI_Group_ClearAll(int arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  value1 = *(int *)(arg1 + 0x158);
  value3 = 0;
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)Array_GetPtr((void *)(arg1 + 0x148),value3);
      if (pvVar2 != (LPVOID)0x0) {
        UI_Group_DestroyMemberList((intptr_t)pvVar2);
        Mem_Free(pvVar2);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  Array_Clear(arg1 + 0x148);
  return 0;
}
