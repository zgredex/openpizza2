// Company_GenerateNameFromTopProduct: ported from Pizza Connection 2 at 0x513a90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513a90
#include "pc2_port.h"

void __thiscall Company_GenerateNameFromTopProduct(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  uint32_t unaff_EDI;
  int value5;
  char local_50 [80];
  
  value4 = 0;
  value2 = 0;
  ptr3 = (int *)((intptr_t)self + 100);
  value5 = arg1;
  do {
    if (((value2 != 0) && (value1 = *ptr3, 0 < value1)) && (value4 < value1)) {
      value4 = value1;
      value5 = value2;
    }
    value2 = value2 + 1;
    ptr3 = ptr3 + 1;
  } while (value2 < 0x56);
  String_Format(local_50,(uint8_t *)(*(int *)(DAT_0057c670 + 0xa8 + value5 * 4) + 0x88),unaff_EDI);
  Company_GenerateUniqueName(arg1,self,local_50);
  return;
}
