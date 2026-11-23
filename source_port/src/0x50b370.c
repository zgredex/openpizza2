// Object_HasNearbyType20Object: ported from Pizza Connection 2 at 0x50b370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b370
#include "pc2_port.h"

uint32_t __fastcall Object_HasNearbyType20Object(int arg1)

{
  int *ptr1;
  void *self;
  int value2;
  int value3;
  void *this_00;
  int value4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  ptr1 = *(int **)(arg1 + 200);
  if (ptr1 != (int *)0x0) {
    self = *(void **)(arg1 + 0xf4);
    Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_c,&local_4);
    value4 = 0;
    if (0 < *(int *)((intptr_t)self + 0x8c)) {
      do {
        value2 = Game_MapRecordToGlobal(self,value4);
        if ((*(int *)(value2 + 0x30) == 0x20) && (*(int *)(value2 + 0x38) == 0x20)) {
          ptr1 = *(int **)(value2 + 200);
          if (ptr1 == (int *)0x0) {
            value3 = -1;
            this_00 = (void *)0x0;
          }
          else {
            value3 = *ptr1;
            this_00 = (void *)ptr1[0x16];
          }
          Record_GetTwoFloats48(this_00,value3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 <
              (intptr_t)((-(uint32_t)(*(int *)(value2 + 0xa4) != 2) & 0xfffff510) + 0x1900)) {
            return 1;
          }
        }
        value4 = value4 + 1;
      } while (value4 < *(int *)((intptr_t)self + 0x8c));
    }
  }
  return 0;
}
