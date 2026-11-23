// MessageList_FindKeyByValue: ported from Pizza Connection 2 at 0x54b110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b110
#include "pc2_port.h"

int __thiscall MessageList_FindKeyByValue(void *self,int arg1,int *arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value2 = arg1;
  value1 = *(int *)((intptr_t)self + 0x18);
  value4 = 0;
  if (0 < value1) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 4),value4,&arg1);
      if ((value3 != 0) && (*(int *)(value3 + 8) == value2)) {
        *arg2 = arg1;
        return value3;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  return 0;
}
