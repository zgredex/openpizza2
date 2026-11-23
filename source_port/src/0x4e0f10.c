// Game_IsRecordLinked: ported from Pizza Connection 2 at 0x4e0f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0f10
#include "pc2_port.h"

bool __thiscall Game_IsRecordLinked(void *self,int arg1)

{
  uint32_t uvalue1;
  
  if (*(char *)(arg1 + 0x1dc) == '\0') {
    uvalue1 = Game_HasRecordField14DC(self,arg1);
    return (char)uvalue1 != '\0';
  }
  return true;
}
