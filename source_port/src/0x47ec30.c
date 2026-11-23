// IDMap_FreeValuesAndReset: ported from Pizza Connection 2 at 0x47ec30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ec30
#include "pc2_port.h"

void IDMap_FreeValuesAndReset(void *arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  value3 = 0;
  value1 = *(int *)((intptr_t)arg1 + 0x14);
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1,value3,(int *)0x0);
      if (pvVar2 != (LPVOID)0x0) {
        Mem_Free(pvVar2);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  List_Node_Reset((intptr_t)arg1);
  return;
}
