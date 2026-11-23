// Personnel_GetTrainingLevel: ported from Pizza Connection 2 at 0x4a8450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a8450
#include "pc2_port.h"

int __cdecl Personnel_GetTrainingLevel(int arg1)

{
  if (arg1 == 0) {
    return 0;
  }
  return *(int *)(&DAT_0057d298 + arg1 * 4) + 1;
}
