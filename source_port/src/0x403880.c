// String_CompareLocalizedNoCase: ported from Pizza Connection 2 at 0x403880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403880
#include "pc2_port.h"

int __cdecl String_CompareLocalizedNoCase(uint32_t *arg1,int *arg2)

{
  char cVar1;
  int value2;
  int value3;
  char *cptr4;
  int value5;
  int value6;
  
  cptr4 = (char *)*arg1;
  value6 = 0;
  cVar1 = *cptr4;
  if (cVar1 != '\0') {
    value5 = *arg2 - (intptr_t)cptr4;
    do {
      value3 = (intptr_t)cptr4[value5];
      value2 = (intptr_t)cVar1;
      if ((value2 == -0x3c) || (value2 == -0x1c)) {
        value2 = 0x61;
      }
      else if ((value2 == -0x2a) || (value2 == -10)) {
        value2 = 0x6f;
      }
      else if ((value2 == -0x24) || (value2 == -4)) {
        value2 = 0x75;
      }
      if ((value3 == -0x3c) || (value3 == -0x1c)) {
        value3 = 0x61;
      }
      else if ((value3 == -0x2a) || (value3 == -10)) {
        value3 = 0x6f;
      }
      else if ((value3 == -0x24) || (value3 == -4)) {
        value3 = 0x75;
      }
      if ((0x40 < value2) && (value2 < 0x5b)) {
        value2 = value2 + 0x20;
      }
      if ((0x40 < value3) && (value3 < 0x5b)) {
        value3 = value3 + 0x20;
      }
      if (value2 != value3) {
        return ((value3 <= value2) - 1 & 0xfffffffe) + 1;
      }
      cVar1 = cptr4[1];
      value6 = value6 + 1;
      cptr4 = cptr4 + 1;
    } while (cVar1 != '\0');
  }
  return -(uint32_t)(*(char *)(*arg2 + value6) != '\0');
}
