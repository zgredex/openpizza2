// Stats_FreeRecordMap: ported from Pizza Connection 2 at 0x510600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510600
#include "pc2_port.h"

void __fastcall Stats_FreeRecordMap(int arg1)

{
  int value1;
  LPVOID pvVar2;
  
  if (*(int *)(arg1 + 0x304) != 0) {
    value1 = *(int *)(*(int *)(arg1 + 0x304) + 0x14);
    while (value1 = value1 + -1, -1 < value1) {
      pvVar2 = (LPVOID)IDMap_Lookup(*(void **)(arg1 + 0x304),value1,(int *)0x0);
      if (pvVar2 != (LPVOID)0x0) {
        Mem_Free(pvVar2);
      }
    }
    List_Node_Reset(*(int *)(arg1 + 0x304));
  }
  return;
}
