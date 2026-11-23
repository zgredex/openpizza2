// Map_BuildTerrainGrid: ported from Pizza Connection 2 at 0x4f96e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f96e0
#include "pc2_port.h"

void Map_BuildTerrainGrid(int arg1)

{
  char cVar1;
  bool flag2;
  uint8_t uvalue3;
  int value4;
  uint32_t extraout_var;
  void *self;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t *uptr8;
  int value9;
  int value10;
  uint32_t *uptr11;
  int value12;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uptr8 = (uint32_t *)(arg1 + 0x28);
  uptr11 = uptr8;
  for (value5 = 0x640; value5 != 0; value5 = value5 + -1) {
    *uptr11 = 0x40404040;
    uptr11 = uptr11 + 1;
  }
  Object_GetRect100(*(void **)(arg1 + 0x10),&local_18,&local_1c,&local_10,&local_14);
  local_30 = local_10;
  local_38 = local_18;
  value5 = local_1c;
  value4 = local_14;
  value9 = local_10;
  if (local_10 < local_14) {
    do {
      value10 = 0;
      if (local_38 < value5) {
        do {
          value5 = Grid_GetCell(*(void **)(arg1 + 0x10),local_38,local_30);
          if ((value5 != 0) && (*(int *)(value5 + 8) != 0)) {
            value5 = Array_GetField4Stride12(value5,0);
            value4 = IsMenuId34EOr350(value5);
            if (value4 == 0) {
              flag2 = IsMenuId352(value5);
              if (CONCAT31(extraout_var,flag2) == 0) {
                value4 = IsMenuId351Or355(value5);
                if (value4 == 0) {
                  value5 = IsMenuIdRange(value5);
                  if (value5 != 0) {
                    *(uint8_t *)(value10 + (intptr_t)uptr8) = 0x20;
                  }
                }
                else {
                  *(uint8_t *)(value10 + (intptr_t)uptr8) = 0x2b;
                }
              }
              else {
                *(uint8_t *)(value10 + (intptr_t)uptr8) = 0x2d;
              }
            }
            else {
              *(uint8_t *)(value10 + (intptr_t)uptr8) = 0x2e;
            }
          }
          value10 = value10 + 1;
          local_38 = local_38 + 1;
        } while (local_38 < local_1c);
        local_38 = local_18;
        value5 = local_1c;
        value4 = local_14;
        value9 = local_10;
      }
      uptr8 = uptr8 + 0x14;
      local_30 = local_30 + 1;
    } while (local_30 < value4);
  }
  local_34 = 0;
  if (value9 < value4) {
    value10 = local_20;
    value12 = local_24;
    local_30 = value9;
    do {
      value9 = 0;
      if (local_38 < value5) {
        local_3c = 1;
        value5 = local_34 * 0x50 + arg1;
        local_4 = value5;
        do {
          cVar1 = *(char *)(value5 + 0x28 + value9);
          if ((cVar1 == '+') || (cVar1 == '-')) {
            uvalue3 = 0x31;
LAB_004f985f:
            if (*(char *)(value5 + 0x29 + value9) == '@') {
              *(uint8_t *)(value5 + 0x29 + value9) = uvalue3;
            }
            if (*(char *)(value5 + 0x27 + value9) == '@') {
              *(uint8_t *)(value5 + 0x27 + value9) = uvalue3;
            }
            if (*(char *)(value5 + 0x78 + value9) == '@') {
              *(uint8_t *)(value5 + 0x78 + value9) = uvalue3;
            }
            if (*(char *)(value5 + -0x28 + value9) == '@') {
              *(uint8_t *)(value5 + -0x28 + value9) = uvalue3;
            }
          }
          else if (cVar1 == '.') {
            uvalue3 = 0x57;
            goto LAB_004f985f;
          }
          value4 = Grid_GetCell(*(void **)(arg1 + 0x10),local_38,local_30);
          if ((value4 != 0) && (*(int *)(value4 + 8) != 0)) {
            value4 = Array_GetField4Stride12(value4,1);
            if (value4 != -1) {
              self = (void *)Game_GetCityData(value4);
              if (self != (void *)0x0) {
                Object_GetPair68(self,&local_c,&local_8);
                if (local_c == 1) {
                  value10 = value9;
                  local_24 = value9;
LAB_004f9924:
                  value12 = local_24;
                  local_20 = value10;
                }
                else {
                  if (local_c == 2) {
                    local_24 = value9;
LAB_004f991c:
                    value10 = local_3c;
                    goto LAB_004f9924;
                  }
                  if (local_c == 3) {
                    local_24 = value9 + -1;
                    goto LAB_004f991c;
                  }
                  if (local_c == 4) {
                    local_24 = value9 + -2;
                    goto LAB_004f991c;
                  }
                }
                if (local_8 == 1) {
                  local_2c = local_34;
                  local_28 = local_34;
                }
                else {
                  if (local_8 == 2) {
                    local_2c = local_34;
LAB_004f9970:
                    local_28 = local_34 + 1;
                  }
                  else {
                    if (local_8 == 3) {
                      local_2c = local_34 + -1;
                      goto LAB_004f9970;
                    }
                    if (local_8 == 4) {
                      local_2c = local_34 + -2;
                      goto LAB_004f9970;
                    }
                  }
                  if (local_28 < local_2c) goto LAB_004f99ca;
                }
                uptr8 = (uint32_t *)(local_2c * 0x50 + value12 + 0x28 + arg1);
                value5 = (local_28 - local_2c) + 1;
                do {
                  if (value12 <= value10) {
                    uvalue6 = (value10 - value12) + 1;
                    uptr11 = uptr8;
                    for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
                      *uptr11 = 0x78787878;
                      uptr11 = uptr11 + 1;
                    }
                    for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
                      *(uint8_t *)uptr11 = 0x78;
                      uptr11 = (uint32_t *)((intptr_t)uptr11 + 1);
                    }
                    value10 = local_20;
                    value12 = local_24;
                  }
                  uptr8 = uptr8 + 0x14;
                  value5 = value5 + -1;
                } while (value5 != 0);
                value5 = local_4;
              }
            }
          }
LAB_004f99ca:
          value9 = value9 + 1;
          local_3c = local_3c + 1;
          local_38 = local_38 + 1;
        } while (local_38 < local_1c);
        local_38 = local_18;
        value5 = local_1c;
        value4 = local_14;
      }
      local_34 = local_34 + 1;
      local_30 = local_30 + 1;
    } while (local_30 < value4);
  }
  return;
}
