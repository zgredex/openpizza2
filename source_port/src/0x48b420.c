// Game_ReassignDestroyedObjectReferences: ported from Pizza Connection 2 at 0x48b420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b420
#include "pc2_port.h"

void __thiscall Game_ReassignDestroyedObjectReferences(void *self,int arg1)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  int *ptr4;
  int local_c;
  
  value1 = *(int *)((intptr_t)self + 0x50);
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  local_c = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),local_c,(int *)0x0);
      if (*(int *)(value2 + 0x30) != 0x2e) {
        if (*(int *)(value2 + 0xcc) == arg1) {
          value3 = Map_GetRandomBuildingOfType(this_00,*(int *)(arg1 + 4),arg1,'\0');
          if (value3 == 0) {
            value3 = Map_GetRandomBuildingOfType(this_00,0,0,'\0');
          }
          *(int *)(value2 + 0xcc) = value3;
          ptr4 = (int *)(value2 + 0xd4);
          value2 = 8;
          do {
            if (*ptr4 == arg1) {
              *ptr4 = value3;
            }
            ptr4 = ptr4 + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
        }
        else {
          ptr4 = (int *)(value2 + 0xd4);
          value2 = 8;
          do {
            if ((*ptr4 == arg1) &&
               (value3 = Map_GetRandomBuildingOfType(this_00,*(int *)(arg1 + 4),arg1,'\0'),
               value3 != 0)) {
              *ptr4 = value3;
            }
            ptr4 = ptr4 + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
        }
      }
      local_c = local_c + 1;
    } while (local_c < value1);
  }
  return;
}
