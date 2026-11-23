// UI_RemoveProfileStatElements: ported from Pizza Connection 2 at 0x4a5360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a5360
#include "pc2_port.h"

void __cdecl UI_RemoveProfileStatElements(void *arg1)

{
  UI_RemoveObjectByKey(arg1,0x1f67);
  UI_RemoveObjectByKey(arg1,0x1f66);
  UI_RemoveObjectByKey(arg1,0x433);
  UI_RemoveObjectByKey(arg1,0x43a);
  UI_RemoveObjectByKey(arg1,0x1f61);
  UI_RemoveObjectByKey(arg1,0x1f63);
  UI_RemoveObjectByKey(arg1,0x1f62);
  UI_RemoveObjectByKey(arg1,0x1f65);
  UI_RemoveObjectByKey(arg1,0x1f64);
  UI_RemoveObjectByKey(arg1,0x439);
  return;
}
