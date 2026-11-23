// IDMap_DeleteContents: ported from Pizza Connection 2 at 0x54b930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b930
#include "pc2_port.h"

void IDMap_DeleteContents(void *arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  
  value3 = 0;
  value1 = *(int *)((intptr_t)arg1 + 0x14);
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1,value3,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  List_Node_Reset((intptr_t)arg1);
  return;
}
