// Parse_ReadDelimitedToken: ported from Pizza Connection 2 at 0x4db380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db380
#include "pc2_port.h"

void __cdecl Parse_ReadDelimitedToken(int arg1,int *arg2,uint32_t *arg3,int arg4)

{
  int value1;
  char cVar2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  
  String_SkipDelimiters(arg1,arg2);
  value3 = 0;
  cVar2 = *(char *)(*arg2 + arg1);
  if (cVar2 != '\"') {
    while (((cVar2 != ' ' && (cVar2 = *(char *)(*arg2 + arg1), cVar2 != '\t')) &&
           (cVar2 != ','))) {
      if (value3 < arg4 + -1) {
        *(char *)(value3 + (intptr_t)arg3) = cVar2;
        *(uint8_t *)(value3 + 1 + (intptr_t)arg3) = 0;
      }
      value4 = *arg2;
      value3 = value3 + 1;
      *arg2 = value4 + 1;
      cVar2 = *(char *)(value4 + 1 + arg1);
    }
    return;
  }
  value3 = *arg2 + 1;
  cVar2 = *(char *)(value3 + arg1);
  value4 = value3;
  while ((cVar2 != '\0' && (cVar2 != '\"'))) {
    value1 = value4 + 1;
    value4 = value4 + 1;
    cVar2 = *(char *)(value1 + arg1);
  }
  uvalue6 = arg4 - 1;
  uvalue5 = value4 - value3;
  if ((value4 - value3 < (intptr_t)uvalue6) || (uvalue5 = uvalue6, SBORROW4(uvalue6,uvalue6))) {
  }
  uptr7 = (uint32_t *)(value3 + arg1);
  uptr8 = arg3;
  for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *uptr8 = *uptr7;
    uptr7 = uptr7 + 1;
    uptr8 = uptr8 + 1;
  }
  for (uvalue6 = uvalue5 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(uint8_t *)uptr8 = *(uint8_t *)uptr7;
    uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
    uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
  }
  *(uint8_t *)(uvalue5 + (intptr_t)arg3) = 0;
  return;
}
