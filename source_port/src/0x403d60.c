// MissionBriefing_InitList: ported from Pizza Connection 2 at 0x403d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403d60
#include "pc2_port.h"

void MissionBriefing_InitList(void)

{
  List_Construct(&DAT_0057c590,0);
  return;
}
