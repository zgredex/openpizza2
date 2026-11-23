// GangsterWeaponPanel_RefreshWithSound: ported from Pizza Connection 2 at 0x4befd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4befd0
#include "pc2_port.h"

void __cdecl GangsterWeaponPanel_RefreshWithSound(void *arg1)

{
                    /* Plays a gangster weapon sound and refreshes its panel. */
  Sound_ProcessEvent(DAT_0057ba0c,*(int *)(*(int *)(DAT_0057c670 + 0x21c) + 0x30),0,'\x01');
  CriminalsPage_FillUnitDetails(arg1);
  return;
}
