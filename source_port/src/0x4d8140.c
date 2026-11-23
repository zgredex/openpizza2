// Game_FindBestCompositeRatedBranch: ported from Pizza Connection 2 at 0x4d8140.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8140
#include "pc2_port.h"

void * Game_FindBestCompositeRatedBranch(int arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  int value4;
  int value5;
  int local_10;
  int local_c;
  void *local_8;
  
  local_10 = -1;
  local_8 = (void *)0x0;
  local_c = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,local_c);
    if ((value1 != 0) && (value4 = 0, 0 < *(int *)(value1 + 0x15c))) {
      do {
        self = (void *)IDMap_Lookup((void *)(value1 + 0x148),value4,(int *)0x0);
        if (self != (void *)0x0) {
          if (arg1 == -1) {
            value3 = 0;
            value5 = 0;
            do {
              value2 = Branch_GetCustomerGroupRating(self,value5,1);
              value3 = value3 + value2;
              value5 = value5 + 1;
            } while (value5 < 8);
            value3 = (intptr_t)(value3 + (value3 >> 0x1f & 7U)) >> 3;
          }
          else {
            value3 = Branch_GetCustomerGroupRating(self,arg1,1);
          }
          if (local_10 < value3) {
            local_10 = value3;
            local_8 = self;
          }
        }
        value4 = value4 + 1;
      } while (value4 < *(int *)(value1 + 0x15c));
    }
    local_c = local_c + 1;
  } while (local_c < 6);
  if (local_10 < 0x1e) {
    return (void *)0x0;
  }
  return local_8;
}
