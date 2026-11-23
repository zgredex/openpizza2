// UI_ShowDialog: ported from Pizza Connection 2 at 0x4c89b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c89b0
#include "pc2_port.h"

void __cdecl UI_ShowDialog(void *arg1)

{
  int local_80;
  uint32_t local_7c;
  uint32_t local_78;
  uint32_t local_74;
  uint32_t local_70;
  uint32_t local_6c;
  uint32_t local_68;
  uint32_t local_64;
  uint32_t local_60;
  uint32_t local_5c;
  uint32_t local_58;
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
  
  local_7c = DAT_005810c4;
  local_74 = DAT_0058110c;
  local_6c = DAT_0058110c;
  local_64 = DAT_0058110c;
  local_5c = DAT_0058110c;
  local_54 = DAT_0058110c;
  local_4c = DAT_0058110c;
  local_44 = DAT_0058110c;
  local_3c = DAT_0058110c;
  local_80 = 0x59a;
  local_78 = 0x4ac;
  local_70 = 0x59b;
  local_68 = 0x4ae;
  local_60 = 0x4ab;
  local_58 = 0x4b0;
  local_50 = 0x4b1;
  local_48 = 0x4af;
  local_40 = 0x4aa;
  local_38 = 0x4b8;
  local_34 = DAT_005810f8;
  local_30 = 0x4b9;
  local_2c = DAT_005810f8;
  local_28 = 0x4ba;
  local_24 = DAT_005810f8;
  local_20 = 0x4bb;
  local_1c = DAT_005810f8;
  local_18 = 0x4bc;
  local_14 = DAT_005810f8;
  local_10 = 0x4bd;
  local_c = DAT_005810f8;
  local_8 = 0xffffffff;
  local_4 = 0;
  UI_SetMultipleLabels(arg1,&local_80);
  return;
}
