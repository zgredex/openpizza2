// Thread_ReleaseNodeValues: ported from Pizza Connection 2 at 0x54ca80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ca80
#include "pc2_port.h"

void __fastcall Thread_ReleaseNodeValues(int arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  value3 = 0;
  value1 = *(int *)(arg1 + 0x88);
  if (0 < *(int *)(value1 + 100)) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup((void *)(value1 + 0x50),value3,(int *)0x0);
      Mem_Free(pvVar2);
      value1 = *(int *)(arg1 + 0x88);
      value3 = value3 + 1;
    } while (value3 < *(int *)(value1 + 100));
  }
  List_Node_Reset(*(int *)(arg1 + 0x88) + 0x50);
  return;
}
