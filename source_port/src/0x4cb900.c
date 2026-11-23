// FreePlaySetup_ShowMapPreview: ported from Pizza Connection 2 at 0x4cb900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb900
#include "pc2_port.h"

void __cdecl FreePlaySetup_ShowMapPreview(void *arg1)

{
  uint8_t *uptr1;
  char local_40 [64];
  
  uptr1 = NameMap_GetRecordString(&DAT_0057de38,DAT_0057bb40);
  String_Format(local_40,(uint8_t *)s_maps__s_spr_0056b330,uptr1);
  UI_SetButtonSpriteByName(arg1,0x4e4,local_40);
  Sound_PlayBuildingSpecialSfx(DAT_0057ba0c,DAT_0057bb40);
  return;
}
