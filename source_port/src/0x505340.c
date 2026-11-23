// MapObject_ReadRenderRecord: ported from Pizza Connection 2 at 0x505340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x505340
#include "pc2_port.h"

void __thiscall MapObject_ReadRenderRecord(void *self,int arg1,void *arg2)

{
  int value1;
  uint32_t uvalue2;
  void *local_4;
  
                    /* Reads a map object's optional render-sprite record. */
  local_4 = self;
  if (*(int *)((intptr_t)self + 0x30) == 0x10) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((intptr_t)self + 0x50),(int *)0x0);
    uvalue2 = (uint32_t)*(uint8_t *)(value1 + 0x824);
  }
  else {
    uvalue2 = 0xffffffff;
  }
  MapObject_InitRenderRecord(self,arg1,*(int *)((intptr_t)self + 0x30),uvalue2);
  CRT_Istream_Read(arg2,&local_4,4);
  if (local_4 == (void *)0x1) {
    MapActor_ReadFromStream(arg2,*(uint32_t **)((intptr_t)self + 200));
    return;
  }
  *(uint32_t *)((intptr_t)self + 200) = 0;
  return;
}
