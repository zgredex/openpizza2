// Game_MoveTypeBObjectsToStateList: ported from Pizza Connection 2 at 0x50ad80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ad80
#include "pc2_port.h"

void __thiscall Game_MoveTypeBObjectsToStateList(void *self,void *arg1)

{
  int value1;
  int value2;
  
  if (0 < *(int *)((intptr_t)self + 0x128)) {
    value2 = 0;
    if (0 < *(int *)((intptr_t)self + 0x128)) {
      do {
        value1 = IDMap_Lookup((void *)((intptr_t)self + 0x114),value2,(int *)0x0);
        value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value1,(int *)0x0);
        if (*(int *)(value1 + 0x38) == 0xb) {
          Game_AddObjectToStateList(arg1,value1);
        }
        value2 = value2 + 1;
      } while (value2 < *(int *)((intptr_t)self + 0x128));
    }
    List_Node_Reset((intptr_t)self + 0x114);
  }
  return;
}
