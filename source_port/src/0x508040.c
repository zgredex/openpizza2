// UI_ResetChildRecord: ported from Pizza Connection 2 at 0x508040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508040
#include "pc2_port.h"

void __fastcall UI_ResetChildRecord(int arg1)

{
  int *ptr1;
  int value2;
  void *self;
  
  ptr1 = *(int **)(arg1 + 200);
  if (ptr1 == (int *)0x0) {
    self = (void *)0x0;
    value2 = -1;
  }
  else {
    self = (void *)ptr1[0x16];
    value2 = *ptr1;
  }
  if (self != (void *)0x0) {
    Record_ClearActive48(self,value2);
  }
  return;
}
