// Game_IsValueAssignedToCompany: ported from Pizza Connection 2 at 0x4e2e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2e40
#include "pc2_port.h"

uint32_t __thiscall Game_IsValueAssignedToCompany(void *self,int arg1)

{
  int value1;
  uint32_t in_EAX;
  int *ptr2;
  int value3;
  int value4;
  
  if (arg1 != 0) {
    value4 = 0;
    if (0 < *(int *)((intptr_t)self + 0x1cc)) {
      do {
        ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value4,(int *)0x0);
        value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
        if (*(int *)(value3 + 0xa4) != -1) {
          if (*(int *)(value3 + 0x74) == 0) {
            value1 = *(int *)(value3 + 0xfc);
          }
          else {
            value1 = *(int *)(value3 + 0xf4);
          }
          if (value1 == arg1) goto LAB_004e2f1d;
        }
        value4 = value4 + 1;
      } while (value4 < *(int *)((intptr_t)self + 0x1cc));
    }
    value4 = 0;
    in_EAX = DAT_0057c670;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value4,(int *)0x0);
        if (((*(int *)(value3 + 0xa4) != -1) &&
            (*(int *)(value3 + 0x110) == *(int *)((intptr_t)self + 0x48))) &&
           (*(int *)(value3 + 0x30) == 0x16)) {
          if (*(int *)(value3 + 0x74) == 0) {
            value1 = *(int *)(value3 + 0xfc);
          }
          else {
            value1 = *(int *)(value3 + 0xf4);
          }
          if (value1 == arg1) {
LAB_004e2f1d:
            return CONCAT31((int3)((uint32_t)value3 >> 8),1);
          }
        }
        value4 = value4 + 1;
        in_EAX = DAT_0057c670;
      } while (value4 < *(int *)(DAT_0057c670 + 0x50));
    }
  }
  return in_EAX & 0xffffff00;
}
