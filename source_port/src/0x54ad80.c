// UI_DestroyBriefingList: ported from Pizza Connection 2 at 0x54ad80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ad80
#include "pc2_port.h"

void __fastcall UI_DestroyBriefingList(void *arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  UI_RemoveAllById(arg1,1);
  value1 = *(int *)((intptr_t)arg1 + 0x18);
  value3 = 0;
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup((void *)((intptr_t)arg1 + 4),value3,(int *)0x0);
      Mem_Free(pvVar2);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  List_Node_Reset((intptr_t)arg1 + 4);
  return;
}
