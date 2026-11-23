// Object_HideLinkedElements: ported from Pizza Connection 2 at 0x4f13b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f13b0
#include "pc2_port.h"

void __fastcall Object_HideLinkedElements(int arg1)

{
  int *ptr1;
  
  for (ptr1 = *(int **)(arg1 + 0xbc); ptr1 != (int *)0x0; ptr1 = (int *)ptr1[0x1c]) {
    Record_ClearActive48((void *)ptr1[0x16],*ptr1);
  }
  return;
}
