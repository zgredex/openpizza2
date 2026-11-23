// Map_BuildObjectGrid: ported from Pizza Connection 2 at 0x4fbae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fbae0
#include "pc2_port.h"

void Map_BuildObjectGrid(void *arg1,uint32_t *arg2)

{
  short svalue1;
  bool flag2;
  uint32_t *uptr3;
  int value4;
  uint32_t extraout_var;
  void *self;
  uint32_t *uptr5;
  int value6;
  int value7;
  int value8;
  int value9;
  int value10;
  short *local_4c;
  short *local_48;
  short *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  short *local_2c;
  int local_28;
  short *local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint32_t *local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value7 = 0x50;
  uptr3 = arg2;
  do {
    value6 = 0x50;
    do {
      *(uint16_t *)(uptr3 + 1) = 0xffff;
      *uptr3 = 0;
      uptr3 = uptr3 + 2;
      value6 = value6 + -1;
    } while (value6 != 0);
    value7 = value7 + -1;
  } while (value7 != 0);
  Object_GetRect100(arg1,&local_18,&local_1c,&local_c,&local_10);
  local_40 = local_c;
  value7 = local_18;
  value6 = local_1c;
  value4 = local_10;
  value9 = local_c;
  if (local_c < local_10) {
    value8 = 0;
    local_14 = arg2 + 0x9f;
    do {
      value10 = 0;
      if (value7 < value6) {
        do {
          value6 = Grid_GetCell(arg1,value7,local_40);
          if ((value6 != 0) && (*(int *)(value6 + 8) != 0)) {
            value6 = Array_GetField4Stride12(value6,0);
            value4 = IsMenuId34EOr350(value6);
            if (value4 == 0) {
              flag2 = IsMenuId352(value6);
              if (CONCAT31(extraout_var,flag2) == 0) {
                value4 = IsMenuId351Or355(value6);
                if (value4 == 0) {
                  value6 = IsMenuIdRange(value6);
                  if (value6 != 0) goto LAB_004fbbdd;
                }
                else {
                  *(uint16_t *)(arg2 + (value8 + value10) * 2 + 1) = 0xfffd;
                }
              }
              else {
                *(uint16_t *)(arg2 + (value8 + value10) * 2 + 1) = 0xfffe;
              }
            }
            else {
LAB_004fbbdd:
              *(uint16_t *)(arg2 + (value8 + value10) * 2 + 1) = 0;
            }
          }
          value10 = value10 + 1;
          value7 = value7 + 1;
        } while (value7 < local_1c);
        value7 = local_18;
        value6 = local_1c;
        value4 = local_10;
        value9 = local_c;
      }
      value8 = value8 + 0x50;
      *(uint16_t *)local_14 = 0xffff;
      local_14 = local_14 + 0xa0;
      local_40 = local_40 + 1;
    } while (local_40 < value4);
  }
  local_38 = 0;
  local_40 = value9;
  if (value4 <= value9) {
    return;
  }
  do {
    value9 = 0;
    if (value7 < value6) {
      local_20 = 1;
      local_44 = (short *)(arg2 + local_38 * 0xa0 + -0x9f);
      local_48 = (short *)(arg2 + local_38 * 0xa0 + 0xa1);
      local_2c = (short *)(arg2 + local_38 * 0xa0 + -1);
      local_24 = (short *)(arg2 + local_38 * 0xa0 + 3);
      local_4c = (short *)(arg2 + local_38 * 0xa0 + 1);
      local_14 = (uint32_t *)value7;
      do {
        svalue1 = *local_4c;
        if (((svalue1 == 0) || (svalue1 == -2)) || (svalue1 == -3)) {
          if (*local_24 == -1) {
            *local_24 = 9;
          }
          if (*local_2c == -1) {
            *local_2c = 9;
          }
          if (*local_48 == -1) {
            *local_48 = 9;
          }
          if (*local_44 == -1) {
            *local_44 = 9;
          }
        }
        value7 = Grid_GetCell(arg1,(intptr_t)local_14,local_40);
        if (((value7 != 0) && (*(int *)(value7 + 8) != 0)) &&
           ((value7 = Array_GetField4Stride12(value7,1), value7 != -1 &&
            (self = (void *)Game_GetCityData(value7), self != (void *)0x0)))) {
          Object_GetPair68(self,&local_8,&local_4);
          if (local_8 == 1) {
            local_3c = value9;
            local_28 = value9;
          }
          else {
            if (local_8 == 2) {
              local_3c = value9;
            }
            else if (local_8 == 3) {
              local_3c = value9 + -1;
            }
            else {
              if (local_8 != 4) goto LAB_004fbd7e;
              local_3c = value9 + -2;
            }
            local_28 = local_20;
          }
LAB_004fbd7e:
          if (local_4 == 1) {
            local_34 = local_38;
            local_30 = local_38;
          }
          else {
            if (local_4 == 2) {
              local_34 = local_38;
LAB_004fbdc6:
              local_30 = local_38 + 1;
            }
            else {
              if (local_4 == 3) {
                local_34 = local_38 + -1;
                goto LAB_004fbdc6;
              }
              if (local_4 == 4) {
                local_34 = local_38 + -2;
                goto LAB_004fbdc6;
              }
            }
            if (local_30 < local_34) goto LAB_004fbe98;
          }
          uptr3 = arg2 + (local_34 * 0x50 + local_3c) * 2;
          value7 = (local_30 - local_34) + 1;
          do {
            if (local_3c <= local_28) {
              value6 = (local_28 - local_3c) + 1;
              uptr5 = uptr3;
              do {
                *uptr5 = self;
                *(short *)(uptr5 + 1) = (short)*(uint32_t *)((intptr_t)self + 8);
                uptr5 = uptr5 + 2;
                value6 = value6 + -1;
              } while (value6 != 0);
            }
            uptr3 = uptr3 + 0xa0;
            value7 = value7 + -1;
          } while (value7 != 0);
        }
LAB_004fbe98:
        local_20 = local_20 + 1;
        local_24 = local_24 + 4;
        local_2c = local_2c + 4;
        local_44 = local_44 + 4;
        local_48 = local_48 + 4;
        local_4c = local_4c + 4;
        value9 = value9 + 1;
        local_14 = (uint32_t *)((intptr_t)local_14 + 1);
      } while ((intptr_t)local_14 < local_1c);
      value7 = local_18;
      value6 = local_1c;
      value4 = local_10;
    }
    local_38 = local_38 + 1;
    local_40 = local_40 + 1;
    if (value4 <= local_40) {
      return;
    }
  } while( true );
}
