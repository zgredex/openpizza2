// Map_FloodFillMask: ported from Pizza Connection 2 at 0x531e10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531e10
#include "pc2_port.h"

void Map_FloodFillMask(int arg1,int arg2,int arg3,int arg4,int arg5)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  int local_288;
  uint32_t local_284;
  uint32_t local_280 [160];
  
  local_288 = 0;
  value6 = 1;
  local_280[0] = arg3 * 0x10000 + arg2;
  uvalue5 = local_284;
  uvalue7 = local_284;
  do {
    uptr1 = local_280 + local_288;
    local_288 = local_288 + 1;
    if (0x9f < local_288) {
      local_288 = 0;
    }
    uvalue2 = (intptr_t)*uptr1 >> 0x10;
    uvalue8 = *uptr1 & 0xffff;
    *(uint8_t *)(uvalue2 * arg4 + arg1 + uvalue8) = 1;
    local_284 = 0;
    do {
      switch(local_284) {
      case 0:
        uvalue5 = uvalue8 - 1;
        uvalue7 = uvalue2;
        break;
      case 1:
        uvalue5 = uvalue8 + 1;
        uvalue7 = uvalue2;
        break;
      case 2:
        uvalue5 = uvalue8;
        uvalue7 = uvalue2 + 1;
        break;
      case 3:
        uvalue5 = uvalue8;
        uvalue7 = uvalue2 - 1;
      }
      if ((((-1 < (intptr_t)uvalue5) && (-1 < (intptr_t)uvalue7)) && ((intptr_t)uvalue5 < arg4)) &&
         (((intptr_t)uvalue7 < arg5 && (*(char *)(uvalue7 * arg4 + uvalue5 + arg1) == '\0')))) {
        uvalue4 = uvalue7 * 0x10000 + uvalue5;
        value3 = local_288;
        while (value3 != value6) {
          if (local_280[value3] == uvalue4) {
            if (value3 != value6) goto LAB_00531f17;
            break;
          }
          value3 = value3 + 1;
          if (0x9f < value3) {
            value3 = 0;
          }
        }
        local_280[value6] = uvalue4;
        value6 = value6 + 1;
        if (0x9f < value6) {
          value6 = 0;
        }
      }
LAB_00531f17:
      local_284 = local_284 + 1;
    } while ((intptr_t)local_284 < 4);
    if (local_288 == value6) {
      return;
    }
  } while( true );
}
