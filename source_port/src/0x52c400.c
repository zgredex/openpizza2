// UI_MeasureTextMaxWidth: ported from Pizza Connection 2 at 0x52c400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52c400
#include "pc2_port.h"

int __fastcall UI_MeasureTextMaxWidth(int arg1)

{
  char *cptr1;
  char cVar2;
  int value3;
  char *cptr4;
  int value5;
  char *cptr6;
  
  value5 = 0;
  cptr4 = *(char **)(arg1 + 0x74);
  if (*cptr4 == '\0') {
    return 0;
  }
  do {
    cVar2 = *cptr4;
    cptr6 = cptr4;
    while (((cVar2 != '\0' && (cVar2 != '\n')) && (cVar2 != '\r'))) {
      cptr1 = cptr6 + 1;
      cptr6 = cptr6 + 1;
      cVar2 = *cptr1;
    }
    cVar2 = *cptr6;
    if (cVar2 == '\0') {
      value3 = Font_MeasureText(*(void **)(arg1 + 0x54),cptr4);
      cptr4 = cptr6;
    }
    else {
      *cptr6 = '\0';
      value3 = Font_MeasureText(*(void **)(arg1 + 0x54),cptr4);
      *cptr6 = cVar2;
      cptr4 = cptr6 + 1;
    }
    if (value5 < value3) {
      value5 = value3;
    }
  } while (*cptr4 != '\0');
  return value5;
}
