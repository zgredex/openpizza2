// UI_BriefingList_Construct: ported from Pizza Connection 2 at 0x54a880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a880
#include "pc2_port.h"

uint32_t * __fastcall UI_BriefingList_Construct(uint32_t *arg1)

{
  List_Construct(arg1 + 1,0);
  *arg1 = &PTR_UI_BriefingList_Delete_0055cb40;
  arg1[8] = 0x122;
  arg1[9] = 0x22d;
  arg1[10] = 0x20;
  arg1[0xd] = 0;
  arg1[0xc] = 0;
  return arg1;
}
