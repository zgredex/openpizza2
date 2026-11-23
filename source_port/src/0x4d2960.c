// Game_RemoveObjectFromList: ported from Pizza Connection 2 at 0x4d2960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2960
#include "pc2_port.h"

uint32_t __thiscall Game_RemoveObjectFromList(void *self,void *arg1,int arg2)

{
  uint32_t uvalue1;
  int value2;
  
  uvalue1 = IDMap_RemoveByKey((void *)((intptr_t)self + 0x78),*(int *)((intptr_t)arg1 + 0x164));
  Set_Field168(arg1,0);
  if (arg2 == 0) {
    Object_SetFieldFC(arg1,0);
  }
  if (*(int *)((intptr_t)self + 0x8c) == 0) {
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
    Map_SetCellObjectFrame(*(void **)(value2 + 0xfa8),*(int *)((intptr_t)self + 0x24),'\x01');
  }
  return uvalue1;
}
