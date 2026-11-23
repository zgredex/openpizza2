// UI_ShowPanel: ported from Pizza Connection 2 at 0x4caca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4caca0
#include "pc2_port.h"

void __cdecl UI_ShowPanel(void *arg1)

{
  int local_58;
  uint32_t local_54;
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t local_48;
  uint32_t local_44;
  uint32_t local_40;
  uint32_t local_3c;
  uint32_t local_38;
  uint32_t local_34;
  uint32_t local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  local_4c = DAT_005812b8;
  local_44 = DAT_0058167c;
  local_54 = DAT_005812cc;
  local_34 = DAT_00581688;
  local_2c = DAT_00581684;
  local_3c = DAT_00581674;
  local_1c = DAT_00581690;
  local_14 = DAT_005816ac;
  local_24 = DAT_005816a0;
  local_58 = 0x5a5;
  local_50 = 0x4ac;
  local_48 = 0x5a7;
  local_40 = 0x4ae;
  local_38 = 0x4ab;
  local_30 = 0x4b0;
  local_28 = 0x4b1;
  local_20 = 0x4af;
  local_18 = 0x4aa;
  local_10 = 0x4d0;
  local_c = DAT_005821f0;
  local_8 = 0xffffffff;
  local_4 = 0;
  UI_SetMultipleLabels(arg1,&local_58);
  return;
}
