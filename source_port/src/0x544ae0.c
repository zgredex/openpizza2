// List_UnlinkNode: ported from Pizza Connection 2 at 0x544ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544ae0
#include "pc2_port.h"

void __cdecl List_UnlinkNode(void *arg1,uint32_t *arg2)

{
  List_RemoveNodeLocked(arg1,arg2);
  return;
}
