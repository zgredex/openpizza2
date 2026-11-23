// List_FreeContainerValues: ported from Pizza Connection 2 at 0x54c830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c830
#include "pc2_port.h"

void __fastcall List_FreeContainerValues(int *arg1)

{
  LPVOID pvVar1;
  void *self;
  int value2;
  
  self = (void *)*arg1;
  if (self != (void *)0x0) {
    value2 = 0;
    if (0 < *(int *)((intptr_t)self + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(self,value2,(int *)0x0);
        Mem_Free(pvVar1);
        self = (void *)*arg1;
        value2 = value2 + 1;
      } while (value2 < *(int *)((intptr_t)self + 0x14));
    }
    List_Node_Reset(*arg1);
  }
  if (arg1[1] != 0) {
    arg1[1] = 0;
    arg1[2] = 0;
  }
  return;
}
