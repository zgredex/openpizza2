// FUN_00555b57: ported from Pizza Connection 2 at 0x555b57.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555b57
#include "pc2_port.h"

void __cdecl FUN_00555b57(char *arg1,int arg2,int arg3)

{
  char *_Str;
  char *cptr1;
  char *cptr2;
  size_t svalue3;
  char *cptr4;
  char cVar5;
  
  cptr1 = arg1;
  cptr4 = *(char **)(arg3 + 0xc);
  _Str = arg1 + 1;
  *arg1 = '0';
  cptr2 = _Str;
  if (0 < arg2) {
    arg1 = (char *)arg2;
    arg2 = 0;
    do {
      cVar5 = *cptr4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        cptr4 = cptr4 + 1;
      }
      *cptr2 = cVar5;
      cptr2 = cptr2 + 1;
      arg1 = arg1 + -1;
    } while (arg1 != (char *)0x0);
  }
  *cptr2 = '\0';
  if ((-1 < arg2) && ('4' < *cptr4)) {
    while (cptr2 = cptr2 + -1, *cptr2 == '9') {
      *cptr2 = '0';
    }
    *cptr2 = *cptr2 + '\x01';
  }
  if (*cptr1 == '1') {
    *(int *)(arg3 + 4) = *(int *)(arg3 + 4) + 1;
  }
  else {
    svalue3 = _strlen(_Str);
    _memmove((uint32_t *)cptr1,(uint32_t *)_Str,svalue3 + 1);
  }
  return;
}
