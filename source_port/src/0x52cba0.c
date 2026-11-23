// Dialog_ParseInteger: ported from Pizza Connection 2 at 0x52cba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52cba0
#include "pc2_port.h"

uint32_t Dialog_ParseInteger(void *arg1,int *arg2)

{
  int value1;
  char cVar2;
  int value3;
  uint32_t uvalue4;
  int value5;
  
  value3 = *arg2;
  if ((*(char *)(value3 + (intptr_t)arg1) != '}') && (*(char *)(value3 + (intptr_t)arg1) != '\0')) {
    cVar2 = *(char *)(value3 + (intptr_t)arg1);
    value5 = value3;
    while (('/' < cVar2 && (cVar2 < ':'))) {
      value1 = value5 + 1;
      value5 = value5 + 1;
      cVar2 = *(char *)(value1 + (intptr_t)arg1);
    }
    if (value5 != value3) {
      uvalue4 = CRT_AtoiThunk(arg1,(uint8_t *)(value3 + (intptr_t)arg1));
      *arg2 = value5;
      return uvalue4;
    }
  }
  return 0xffffffff;
}
