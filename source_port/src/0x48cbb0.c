// Sound_RefreshMusicSelection: ported from Pizza Connection 2 at 0x48cbb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cbb0
#include "pc2_port.h"

void __fastcall Sound_RefreshMusicSelection(int arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  
  value1 = *(int *)(arg1 + 0x200 + *(int *)(arg1 + 0x2ec) * 4);
  if ((value1 != 0) && (0 < *(int *)(value1 + 0x15c))) {
    if ((*(int *)(arg1 + 0x9c) != 0) &&
       (value2 = *(int *)(*(int *)(arg1 + 0x9c) + 0x30),
       value3 = Game_GetCurrentPlayerCompanyName(arg1), value2 == value3)) {
      return;
    }
    uvalue4 = IDMap_Lookup((void *)(value1 + 0x148),0,(int *)0x0);
    *(uint32_t *)(arg1 + 0x9c) = uvalue4;
    Sound_SelectCurrentTrack(DAT_0057ba0c);
  }
  return;
}
