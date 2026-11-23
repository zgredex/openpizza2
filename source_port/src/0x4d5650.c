// City_InitBuildings: ported from Pizza Connection 2 at 0x4d5650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5650
#include "pc2_port.h"


void __fastcall City_InitBuildings(int arg1)

{
  int *ptr1;
  void *self;
  void **ppvVar2;
  int *ptr3;
  int *ptr4;
  int value5;
  int value6;
  uint32_t *this_00;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558fbb;
  local_c = ExceptionList;
  self = *(void **)(arg1 + 0xfa8);
  if (self != (void *)0x0) {
    value5 = *(int *)((intptr_t)self + 0x20);
    value6 = *(int *)((intptr_t)self + 0x1c);
    local_40 = 0;
    ExceptionList = &local_c;
    ppvVar2 = &local_c;
    local_3c = arg1;
    local_18 = value6;
    local_14 = value5;
    if (0 < value5) {
      do {
        local_38 = 0;
        if (0 < value6) {
          do {
            value5 = local_38;
            ptr3 = (int *)Grid_GetCell(self,local_38,local_40);
            if (((ptr3 != (int *)0x0) && (ptr3[2] != 0)) &&
               (local_2c = *(int *)(ptr3[2] + 0x10), -1 < local_2c)) {
              value6 = 0;
              local_4c = 0;
              if (DAT_0056cb48 != -1) {
                ptr4 = &DAT_0056cb50;
                do {
                  if ((ptr4[-1] <= local_2c) && (local_2c <= *ptr4)) break;
                  value6 = value6 + 3;
                  ptr1 = ptr4 + 1;
                  ptr4 = ptr4 + 3;
                } while (*ptr1 != -1);
                local_4c = value6;
              }
              if ((&DAT_0056cb48)[local_4c] != -1) {
                UI_AlignSpriteToObject(self,ptr3,&local_44,&local_48,&local_24,&local_28);
                local_44 = local_44 + *(int *)((intptr_t)self + 0x24);
                local_48 = local_48 + *(int *)((intptr_t)self + 0x28);
                local_10 = operator_new(0x9c);
                this_00 = (uint32_t *)0x0;
                local_4 = 0;
                if (local_10 != (void *)0x0) {
                  this_00 = MapObject_Construct(local_10,(void *)0x0);
                }
                local_4 = 0xffffffff;
                this_00[1] = (&DAT_0056cb48)[local_4c];
                Entity_ApplyTypeProperties(this_00,local_2c);
                value5 = this_00[0x12];
                if ((value5 < 0) || (3 < value5)) {
                  value6 = value5;
                }
                else {
                  value6 = *(int *)(&DAT_00568188 + value5 * 4);
                }
                if ((((value6 == -1) || (value6 = (&DAT_0056cb48)[local_4c], value6 == 0x20)) ||
                    (value6 == 5)) || (value6 == 6)) {
                  ptr4 = ptr3;
                }
                else {
                  ptr4 = (int *)Grid_GetNeighborCell(self,(intptr_t)ptr3,value5);
                }
                SetRect((LPRECT)(this_00 + 4),local_44,local_48,local_24 + local_44,
                        local_48 + local_28);
                Entity_SetTileId(this_00,(uint32_t)*(uint16_t *)ptr3[2]);
                this_00[10] = *(uint32_t *)(local_3c + 0xc1c);
                Object_SetMarketValueByType((intptr_t)this_00);
                if ((&DAT_0056cb48)[local_4c] == 0xb) {
                  UI_ComputeCenteredRect(self,ptr3,&local_30,&local_34);
                }
                UI_ComputeCenteredRect(self,ptr4,&local_1c,&local_20);
                if (this_00[0x12] != -1) {
                  value5 = Map_ConnectCellToStreetGraph
                                    (self,local_1c - *(int *)((intptr_t)self + 0x24),
                                     local_20 - *(int *)((intptr_t)self + 0x28),this_00[0x12]);
                  Map_AssignObjectToCell(this_00,value5);
                  value5 = Array_GetRecord28(self,1,this_00[0x15]);
                  if (value5 == 0) {
                    Debug_WarningMessageBox();
                  }
                  value5 = Array_GetRecord28(self,1,this_00[0x15]);
                  Grid_CollectNearbyIds(self,this_00 + 0x16,value5,10,0xfa);
                }
                if ((&DAT_0056cb48)[local_4c] == 0x1b) {
                  BuildingValue_CreateDefault(this_00,3);
                }
                List_Add((void *)(local_3c + 0xfac),this_00);
                value5 = local_38;
              }
            }
            local_38 = value5 + 1;
          } while (local_38 < local_18);
          value6 = local_18;
          value5 = local_14;
        }
        local_40 = local_40 + 1;
        ppvVar2 = ExceptionList;
      } while (local_40 < value5);
    }
    ExceptionList = ppvVar2;
    Rect_Center(&local_30,&local_34);
    Map_SetScrollPosition(self,local_30,local_34);
  }
  ExceptionList = local_c;
  return;
}
