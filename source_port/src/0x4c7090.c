// FreePlaySetup_SetDifficultyText: ported from Pizza Connection 2 at 0x4c7090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c7090
#include "pc2_port.h"

void __cdecl FreePlaySetup_SetDifficultyText(void *arg1,int arg2)

{
  Window_GadgetNotify_Text_SetText(arg1,0x408,*(uint32_t *)(&DAT_005840a8 + arg2 * 4));
  return;
}
