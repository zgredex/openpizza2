// CRT_ExceptionTypeMatch: ported from Pizza Connection 2 at 0x552f6c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552f6c
#include "pc2_port.h"

uint32_t __cdecl CRT_ExceptionTypeMatch(uint8_t *arg1,uint8_t *arg2,uint32_t *arg3)

{
  int value1;
  uint32_t uvalue2;
  
  value1 = *(int *)(arg1 + 4);
  if ((value1 == 0) || (*(char *)(value1 + 8) == '\0')) {
LAB_00552fc3:
    uvalue2 = 1;
  }
  else {
    if (value1 == *(int *)(arg2 + 4)) {
LAB_00552f9d:
      if (((((*arg2 & 2) == 0) || ((*arg1 & 8) != 0)) &&
          (((*arg3 & 1) == 0 || ((*arg1 & 1) != 0)))) &&
         (((*arg3 & 2) == 0 || ((*arg1 & 2) != 0)))) goto LAB_00552fc3;
    }
    else {
      value1 = _strcmp((char *)(value1 + 8),(char *)(*(int *)(arg2 + 4) + 8));
      if (value1 == 0) goto LAB_00552f9d;
    }
    uvalue2 = 0;
  }
  return uvalue2;
}
