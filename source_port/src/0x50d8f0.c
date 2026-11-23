// Object_SyncScreenY: ported from Pizza Connection 2 at 0x50d8f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d8f0
#include "pc2_port.h"

void __fastcall Object_SyncScreenY(int arg1)

{
  int *ptr1;
  void *self;
  int value2;
  uint32_t local_8;
  uint32_t local_4;
  
  ptr1 = *(int **)(arg1 + 200);
  if (ptr1 == (int *)0x0) {
    value2 = -1;
    self = (void *)0x0;
  }
  else {
    value2 = *ptr1;
    self = (void *)ptr1[0x16];
  }
  Record_GetTwoFloats48(self,value2,&local_4,&local_8);
  *(uint32_t *)(arg1 + 0x98) = local_8;
  return;
}
