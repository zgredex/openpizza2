// UI_RemoveObjectByOffsetKey: ported from Pizza Connection 2 at 0x49f1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f1c0
#include "pc2_port.h"

void __cdecl UI_RemoveObjectByOffsetKey(void *arg1,int arg2)

{
  UI_RemoveObjectByKey(arg1,arg2 + 100000);
  return;
}
