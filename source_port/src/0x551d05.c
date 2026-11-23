// CRT_Cftog: ported from Pizza Connection 2 at 0x551d05.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551d05
#include "pc2_port.h"

void __cdecl CRT_Cftog(uint64_t *arg1,char *arg2,size_t arg3,int arg4)

{
  int value1;
  char *cptr2;
  char *cptr3;
  uint32_t local_2c [6];
  int local_14;
  int local_10;
  
  FUN_00555bce((uint32_t)*arg1,(intptr_t)((uint64_t)*arg1 >> 0x20),&local_14,local_2c);
  value1 = local_10 + -1;
  FUN_00555b57(arg2 + (local_14 == 0x2d),arg3,(intptr_t)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((intptr_t)arg3 <= local_10)) {
    CRT_FormatExponent(arg2,arg3,arg4,&local_14,'\x01');
  }
  else {
    cptr2 = arg2 + (local_14 == 0x2d);
    if (value1 < local_10) {
      do {
        cptr3 = cptr2;
        cptr2 = cptr3 + 1;
      } while (*cptr3 != '\0');
      cptr3[-1] = '\0';
    }
    CRT_InsertDecimalPoint(arg2,arg3,&local_14,'\x01');
  }
  return;
}
