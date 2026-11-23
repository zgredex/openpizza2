// UI_GetObjectNameById: ported from Pizza Connection 2 at 0x527170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527170
#include "pc2_port.h"

void __thiscall UI_GetObjectNameById(void *self,int arg1,char *arg2)

{
  char *cptr1;
  char *_Str;
  
  _Str = *(char **)((intptr_t)self + 0x82c4);
  while( true ) {
    if (_Str == (char *)0x0) {
      *arg2 = '\0';
      return;
    }
    if (*(int *)(_Str + 0x104) == arg1) break;
    _Str = *(char **)(_Str + 0x10c);
  }
  cptr1 = _strrchr(_Str,0x5c);
  if (cptr1 != (char *)0x0) {
    _Str = cptr1 + 1;
  }
  _strncpy(arg2,_Str,0x3f);
  arg2[0x3f] = '\0';
  return;
}
