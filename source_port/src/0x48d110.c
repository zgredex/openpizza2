// Game_GetDataByIndex: ported from Pizza Connection 2 at 0x48d110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d110
#include "pc2_port.h"

uint8_t * Game_GetDataByIndex(uint32_t arg1)

{
  switch(arg1) {
  case 0:
    return DAT_005822c8;
  case 1:
    return DAT_0058235c;
  case 2:
    return DAT_00582344;
  case 3:
    return DAT_00582334;
  case 4:
    return DAT_00582318;
  case 5:
    return DAT_00582488;
  case 6:
    return DAT_00582480;
  case 7:
    return DAT_00582478;
  default:
    return &DAT_00568310;
  case 10:
    return DAT_00582314;
  case 0xb:
    return DAT_00582484;
  case 0xc:
    return DAT_00582124;
  case 0xd:
    return DAT_005820fc;
  case 0xe:
    return DAT_00582148;
  case 0xf:
  case 0x21:
    return DAT_005820e8;
  case 0x10:
    return DAT_005812bc;
  case 0x11:
    return DAT_00582174;
  case 0x12:
    return DAT_0058214c;
  case 0x13:
    return DAT_00582114;
  case 0x14:
    return DAT_00580e4c;
  case 0x16:
    return DAT_00582214;
  case 0x17:
    return DAT_00582234;
  case 0x18:
    return DAT_00580df8;
  case 0x1a:
    return DAT_00582208;
  case 0x1b:
    return DAT_005820e4;
  case 0x1c:
    return DAT_005821bc;
  case 0x1d:
    return DAT_00582110;
  case 0x1e:
    return DAT_00582100;
  case 0x1f:
    return DAT_00581290;
  case 0x20:
    return DAT_005821f8;
  case 0x22:
    return DAT_005820cc;
  }
}
