// Car_Destroy: ported from Pizza Connection 2 at 0x4d3280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3280
#include "pc2_port.h"

void __fastcall Car_Destroy(uint32_t *arg1)

{
  void *self;
  LPVOID pvVar1;
  
  *arg1 = &PTR_Car_Delete_0055c4f8;
  self = (void *)((int *)arg1[2])[0x16];
  if (self != (void *)0x0) {
    Record_Clear48(self,*(int *)arg1[2]);
  }
  pvVar1 = (LPVOID)arg1[2];
  if (pvVar1 != (LPVOID)0x0) {
    MapSprite_ReleaseRecordList((intptr_t)pvVar1);
    Mem_Free(pvVar1);
  }
  if (arg1[4] != -1) {
    Record_Clear48(*(void **)(DAT_0057c5cc + 0x2c180 + arg1[3] * 4),arg1[4]);
  }
  return;
}
