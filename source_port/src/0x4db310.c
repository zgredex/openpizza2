// Parse_ReadIntToken: ported from Pizza Connection 2 at 0x4db310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db310
#include "pc2_port.h"

int __cdecl Parse_ReadIntToken(int arg1,int *arg2)

{
  int value1;
  char cVar2;
  uint8_t flag3;
  int value4;
  void *self;
  int value5;
  
  String_SkipDelimiters(arg1,arg2);
  cVar2 = *(char *)(*arg2 + arg1);
  if ((cVar2 == '-') || (cVar2 == '+')) {
    *arg2 = *arg2 + 1;
  }
  String_SkipDelimiters(arg1,arg2);
  value5 = *arg2;
  value4 = CRT_AtoiThunk(self,(uint8_t *)(value5 + arg1));
  flag3 = *(uint8_t *)(value5 + arg1);
  while (('/' < (char)flag3 && ((char)flag3 < ':'))) {
    value1 = value5 + 1;
    value5 = value5 + 1;
    flag3 = *(uint8_t *)(value1 + arg1);
  }
  *arg2 = value5 + 1;
  if (cVar2 == '-') {
    value4 = -value4;
  }
  return value4;
}
