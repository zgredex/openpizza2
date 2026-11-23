// Options_GetGlobalSettings: ported from Pizza Connection 2 at 0x547770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547770
#include "pc2_port.h"

void Options_GetGlobalSettings(uint32_t *arg1)

{
  *arg1 = DAT_00575090;
  arg1[1] = DAT_00575094;
  arg1[2] = DAT_00575098;
  arg1[3] = DAT_0057509c;
  return;
}
