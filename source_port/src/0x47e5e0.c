// Game_GetSizeName: ported from Pizza Connection 2 at 0x47e5e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e5e0
#include "pc2_port.h"

void __thiscall Game_GetSizeName(void *self,int arg1)

{
  char *local_a0 [4];
  uint8_t *local_90;
  uint8_t *local_8c;
  uint8_t *local_88;
  uint8_t *local_84;
  CHAR local_80 [128];
  
  local_a0[0] = s_KLEIN_00567cd4;
  local_a0[1] = s_MITTEL_00567ccc;
  local_a0[2] = s_GROSS_00567cc4;
  local_a0[3] = &DAT_00567cbc;
  local_90 = &DAT_00567cb4;
  local_8c = &DAT_00567cac;
  local_88 = &DAT_00567ca4;
  local_84 = &DAT_00567ca0;
  if (arg1 == 4) {
    String_Format(local_80,(uint8_t *)s_FILIALE__s_BODENROH00_spr_00567c68,
                  local_a0[*(int *)((intptr_t)self + 0x38)]);
  }
  else {
    String_Format(local_80,(uint8_t *)s_FILIALE__s_BODEN_s_02d_spr_00567c84,
                  local_a0[*(int *)((intptr_t)self + 0x38)]);
  }
  Sprite_LoadIntoSlot78(*(void **)((intptr_t)self + 0x14e0),local_80);
  return;
}
