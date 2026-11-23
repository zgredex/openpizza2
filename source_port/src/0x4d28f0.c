// Game_AddObjectToList: ported from Pizza Connection 2 at 0x4d28f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d28f0
#include "pc2_port.h"

void __thiscall Game_AddObjectToList(void *self,void *arg1)

{
  int value1;
  int value2;
  
  value2 = *(int *)((intptr_t)arg1 + 0x164);
  value1 = Map_LookupLinear((void *)((intptr_t)self + 0x78),value2);
  if (value1 == -1) {
    List_Add((void *)((intptr_t)self + 0x78),value2);
    Set_Field168(arg1,self);
    if (*(int *)((intptr_t)self + 0x8c) == 1) {
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
      Map_SetCellObjectFrame(*(void **)(value2 + 0xfa8),*(int *)((intptr_t)self + 0x24),'\x02');
    }
  }
  return;
}
