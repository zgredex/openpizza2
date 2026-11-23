// BinarySearch8: ported from Pizza Connection 2 at 0x531330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531330
#include "pc2_port.h"

int __thiscall BinarySearch8(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value1 = *(int *)((intptr_t)self + 0xf0);
  if (value1 < 1) {
    return (arg2 != '\0') - 1;
  }
  value5 = 0;
  value3 = value1;
  if (0 < value1 + -1) {
    do {
      value4 = value3 + value5 >> 1;
      value2 = *(int *)(*(int *)((intptr_t)self + 0xe8) + 4 + value4 * 8);
      if (value2 == arg1) {
        return value4;
      }
      if (value2 < arg1) {
        value5 = value4;
      }
      else {
        value3 = value4;
      }
    } while (value5 < value3 + -1);
  }
  value2 = *(int *)(*(int *)((intptr_t)self + 0xe8) + 4 + value5 * 8);
  if (value2 != arg1) {
    if ((value3 < value1) && (*(int *)(*(int *)((intptr_t)self + 0xe8) + 4 + value3 * 8) == arg1)) {
      return value3;
    }
    if (arg2 == '\0') {
      return -1;
    }
    if (value2 < arg1) {
      return value3;
    }
  }
  return value5;
}
