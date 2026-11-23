// Object_PlayStateSound: ported from Pizza Connection 2 at 0x50d440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d440
#include "pc2_port.h"

void __fastcall Object_PlayStateSound(int arg1)

{
  int value1;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x110));
  switch(*(uint32_t *)(arg1 + 0x30)) {
  case 0xd:
    value1 = Object_GetClampedLevel(arg1);
    break;
  default:
    goto switchD_0050d468_caseD_e;
  case 0x17:
    value1 = *(int *)(value1 + 100);
    break;
  case 0x1d:
    value1 = *(int *)(value1 + 0x6c);
    break;
  case 0x1e:
    Sound_PlayEffectByIndex(DAT_0057ba0c,0x28);
    return;
  }
  if (value1 == 1) {
    Sound_PlayTrackIfSelected(DAT_0057ba0c,0x29);
  }
  else {
    if (value1 == 2) {
      Sound_PlayTrackIfSelected(DAT_0057ba0c,0x20);
      return;
    }
    if (value1 == 3) {
      Sound_PlayTrackIfSelected(DAT_0057ba0c,0x23);
      return;
    }
  }
switchD_0050d468_caseD_e:
  return;
}
