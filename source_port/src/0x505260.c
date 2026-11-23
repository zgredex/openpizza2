// UI_DestroyChildObject: ported from Pizza Connection 2 at 0x505260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505260
#include "pc2_port.h"

uint32_t __fastcall UI_DestroyChildObject(int arg1)

{
  void *self;
  LPVOID pvVar1;
  uint32_t uvalue2;
  
  if (*(int *)(arg1 + 200) == 0) {
    return 0;
  }
  uvalue2 = List_RemoveObject(*(void **)(arg1 + 0xc4),*(int *)(arg1 + 200));
  self = (void *)(*(int **)(arg1 + 200))[0x16];
  if (self != (void *)0x0) {
    Record_Clear48(self,**(int **)(arg1 + 200));
  }
  Record_Clear48(*(void **)(DAT_0057c5cc + 0x2c3b4),*(int *)(*(int *)(arg1 + 200) + 4));
  pvVar1 = *(LPVOID *)(arg1 + 200);
  if (pvVar1 != (LPVOID)0x0) {
    MapSprite_ReleaseRecordList((intptr_t)pvVar1);
    Mem_Free(pvVar1);
  }
  *(uint32_t *)(arg1 + 200) = 0;
  return uvalue2;
}
