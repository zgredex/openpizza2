// MapObject_ComputeBlitRect: ported from Pizza Connection 2 at 0x509e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509e20
#include "pc2_port.h"

void __fastcall MapObject_ComputeBlitRect(int arg1)

{
  int *ptr1;
  void *self;
  int local_8;
  int local_4;
  
  ptr1 = *(int **)(arg1 + 200);
  if (ptr1 == (int *)0x0) {
    return;
  }
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_4,&local_8);
  if (*(int *)(*(int *)(arg1 + 200) + 4) == -1) {
    Map_ComputeBlitRect(*(void **)(arg1 + 0xc4),local_4 + 0xa0,local_8 + 0xd0,(int *)0x1,0);
    return;
  }
  self = *(void **)(arg1 + 0xc4);
  Map_ComputeBlitRect(self,*(int *)((intptr_t)self + 0xf8) + local_4,*(int *)((intptr_t)self + 0xfc) + local_8
                      ,(int *)0x1,0);
  return;
}
