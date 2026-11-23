// String_MakeRoomAtFront: ported from Pizza Connection 2 at 0x551de9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551de9
#include "pc2_port.h"

void __cdecl String_MakeRoomAtFront(char *arg1,int arg2)

{
  size_t svalue1;
  
  if (arg2 != 0) {
    svalue1 = _strlen(arg1);
    _memmove((uint32_t *)(arg1 + arg2),(uint32_t *)arg1,svalue1 + 1);
  }
  return;
}
