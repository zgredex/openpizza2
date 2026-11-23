// Map_ConnectCellToStreetGraph: ported from Pizza Connection 2 at 0x4f3ec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3ec0
#include "pc2_port.h"


void __thiscall Map_ConnectCellToStreetGraph(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  int value6;
  int64_t lvalue7;
  int local_84;
  uint32_t *local_7c;
  int local_78;
  int local_74;
  int local_70;
  short *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint32_t local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint32_t local_34;
  void *local_30;
  uint32_t local_2c;
  double local_28;
  double local_20;
  void *pvStack_14;
  uint8_t *puStack_10;
  uint32_t local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0055a04b;
  pvStack_14 = ExceptionList;
  local_60 = 10000000;
  local_84 = 0x28;
  local_4c = arg3;
  ExceptionList = &pvStack_14;
  local_30 = operator_new(0x1c);
  local_c = 0;
  if (local_30 == (void *)0x0) {
    local_7c = (uint32_t *)0x0;
  }
  else {
    local_7c = List_Construct(local_30,0);
  }
  local_c = 0xffffffff;
  value2 = Object_LinkNeighborRecord(self,(int *)0x1,arg1,arg2,(uint32_t *)0x0);
  local_50 = (uint32_t)*(uint16_t *)(value2 + 4);
  *(uint32_t *)((intptr_t)self + 0xb4) = 0;
  ptr3 = (int *)Grid_GetNeighborCell
                            (self,*(int *)((intptr_t)self + 0x4c) + *(int *)(value2 + 8) * 0xc,arg3);
  UI_ComputeCenteredRect(self,ptr3,&local_74,&local_78);
  local_70 = *(int *)(value2 + 0x10);
  local_6c = *(short **)(value2 + 0xc);
  local_54 = 0;
  local_28 = (double)(local_78 - local_70) / (double)(local_74 - (intptr_t)local_6c);
  local_20 = (double)local_70 - (double)(intptr_t)local_6c * local_28;
LAB_004f3fd7:
  do {
    local_84 = local_84 + 10;
    Grid_CollectNearbyIds(self,local_7c,value2,0x14,local_84);
    if (local_7c[5] == 0) {
      if (local_84 < 800) goto LAB_004f3fd7;
LAB_004f400d:
      arg3 = arg3 + 1;
      if (arg3 == local_4c) {
        NoOp_Stub();
      }
      if (3 < arg3) {
        arg3 = 0;
      }
      local_84 = 0x28;
      ptr3 = (int *)Grid_GetNeighborCell
                                (self,*(int *)((intptr_t)self + 0x4c) + *(int *)(value2 + 8) * 0xc,arg3
                                );
      UI_ComputeCenteredRect(self,ptr3,&local_74,&local_78);
      local_70 = *(int *)(value2 + 0x10);
      local_6c = *(short **)(value2 + 0xc);
      local_28 = (double)(local_78 - local_70) / (double)(local_74 - (intptr_t)local_6c);
      local_20 = (double)local_70 - (double)(intptr_t)local_6c * local_28;
    }
    else if (799 < local_84) goto LAB_004f400d;
    local_58 = 0;
    if (0 < (intptr_t)local_7c[5]) {
      do {
        value4 = IDMap_Lookup(local_7c,local_58,(int *)0x0);
        local_5c = Array_GetRecord28(self,1,value4);
        local_64 = 0;
        local_6c = (short *)(local_5c + 0x14);
        do {
          value4 = local_5c;
          if (*local_6c != -1) {
            local_40 = Array_GetRecord28(self,1,(intptr_t)*local_6c);
            value5 = *(int *)(local_40 + 0x10);
            local_70 = *(int *)(value4 + 0x10);
            value6 = *(int *)(local_40 + 0xc);
            value4 = *(int *)(value4 + 0xc);
            local_68 = value6 - value4;
            local_48 = value4;
            if (local_28 != (double)(value5 - local_70) / (double)local_68) {
              lvalue7 = __ftol();
              local_48 = (intptr_t)lvalue7;
              lvalue7 = __ftol();
              value1 = local_48;
              local_44 = (intptr_t)lvalue7;
              local_68 = value6;
              if (value4 <= value6) {
                local_68 = value4;
              }
              if (value4 < value6) {
                value4 = value6;
              }
              value6 = value5;
              if (local_70 <= value5) {
                value6 = local_70;
              }
              if (value5 <= local_70) {
                value5 = local_70;
              }
              if ((((local_68 <= local_48) && (local_48 <= value4)) && (value6 <= local_44)) &&
                 (local_44 <= value5)) {
                switch(arg3) {
                case 0:
                  if (local_48 < *(int *)(value2 + 0xc)) {
                    value4 = *(int *)(value2 + 0x10);
joined_r0x004f41fc:
                    if (value4 < local_44) goto switchD_004f41d7_default;
                  }
                  break;
                case 1:
                  if (*(int *)(value2 + 0xc) < local_48) {
                    value4 = *(int *)(value2 + 0x10);
                    goto joined_r0x004f41fc;
                  }
                  break;
                case 2:
                  if (*(int *)(value2 + 0xc) < local_48) {
                    value4 = *(int *)(value2 + 0x10);
joined_r0x004f4220:
                    if (local_44 < value4) goto switchD_004f41d7_default;
                  }
                  break;
                case 3:
                  if (local_48 < *(int *)(value2 + 0xc)) {
                    value4 = *(int *)(value2 + 0x10);
                    goto joined_r0x004f4220;
                  }
                  break;
                default:
switchD_004f41d7_default:
                  value4 = Distance_Manhattan3(*(int *)(value2 + 0xc),*(int *)(value2 + 0x10),local_48,
                                              local_44);
                  if (value4 < local_60) {
                    local_34 = (uint32_t)*(uint16_t *)(local_5c + 4);
                    local_38 = local_44;
                    local_3c = value1;
                    local_30 = (void *)(uint32_t)*(uint16_t *)(local_40 + 4);
                    local_54 = 1;
                    local_60 = value4;
                  }
                  goto LAB_004f4298;
                }
              }
            }
          }
          local_64 = local_64 + 1;
          local_6c = local_6c + 1;
        } while (local_64 < 8);
LAB_004f4298:
        local_58 = local_58 + 1;
      } while (local_58 < (intptr_t)local_7c[5]);
    }
    List_Node_Reset((intptr_t)local_7c);
    if (local_54 != 0) {
      value2 = Object_LinkNeighborRecord
                        (self,(int *)0x1,local_3c - *(int *)((intptr_t)self + 0x24),
                         local_38 - *(int *)((intptr_t)self + 0x28),&local_2c);
      *(uint32_t *)((intptr_t)self + 0xb4) = 0;
      value4 = Array_GetRecord28(self,1,local_50);
      Map_LinkObjects(1,value4,value2);
      value4 = Array_GetRecord28(self,1,local_34);
      Map_LinkObjects(1,value4,value2);
      value5 = Array_GetRecord28(self,1,(intptr_t)local_30);
      Map_LinkObjects(1,value5,value2);
      if (local_2c == 0) {
        Map_UnlinkCells(1,value4,value5);
      }
      *(uint32_t *)((intptr_t)self + 0xb4) = 0;
      if (local_7c != (uint32_t *)0x0) {
        (**(code **)*local_7c)(1);
      }
      Array_GetRecord28(self,1,local_50);
      ExceptionList = pvStack_14;
      return;
    }
  } while( true );
}
