// Game_UpdateObjectList2: ported from Pizza Connection 2 at 0x47ed20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ed20
#include "pc2_port.h"

void __fastcall Game_UpdateObjectList2(int arg1)

{
  void *self;
  int value1;
  void *pvVar2;
  int value3;
  int *ptr4;
  int value5;
  
  self = *(void **)(arg1 + 0x16f0);
  value3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  value1 = *(int *)(arg1 + 0x19ac);
  pvVar2 = *(void **)(value3 + 0xfa8);
  value3 = 0;
  value5 = 0;
  if (0 < value1) {
    do {
      if (399999 < value3) goto LAB_0047ed8b;
      ptr4 = (int *)IDMap_Lookup((void *)(arg1 + 0x1998),value5,(int *)0x0);
      if (ptr4[7] != 0) {
        value3 = value3 + *ptr4;
      }
      value5 = value5 + 1;
    } while (value5 < value1);
    if (399999 < value3) {
LAB_0047ed8b:
      Map_ClearObjectFlags(self,pvVar2,0x40);
      return;
    }
  }
  Map_SetObjectFlags(self,pvVar2,0x40);
  return;
}
