// Branch_AssignEntranceAndCustomerSlots: ported from Pizza Connection 2 at 0x4f8d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8d40
#include "pc2_port.h"


uint32_t __thiscall Branch_AssignEntranceAndCustomerSlots(void *self,void *arg1,int arg2)

{
  uint8_t flag1;
  int value2;
  bool flag3;
  uint32_t uvalue4;
  int value5;
  int *ptr6;
  short *psVar7;
  uint32_t uvalue8;
  int value9;
  uint32_t uvalue10;
  int value11;
  int *ptr12;
  short *local_ac;
  int *local_a8;
  uint32_t local_a4;
  uint32_t local_a0;
  int local_98 [11];
  uint32_t local_6c [5];
  int local_58;
  int local_50 [8];
  int local_30 [8];
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Chooses a branch entrance side and re-places customer slots. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a108;
  local_c = ExceptionList;
  local_a0 = 0;
  ExceptionList = &local_c;
  List_Construct(local_6c,0);
  local_4 = 0;
  if (arg2 != 0) {
    value9 = 0;
    psVar7 = (short *)(arg2 + 4);
    do {
      value5 = ((intptr_t)*(short *)(arg2 + 4 + (value9 - 1U & 7) * 0x34) >> 1) + (intptr_t)*psVar7;
      local_30[value9] = value5;
      if (value5 < 6) {
        local_98[value9] = 0;
      }
      else {
        local_98[value9] = 1;
      }
      value9 = value9 + 1;
      psVar7 = psVar7 + 0x1a;
    } while (value9 < 8);
    value9 = 0;
    uvalue4 = 2;
    do {
      if ((*(int *)((intptr_t)local_98 + value9) == 0) && (uvalue8 = uvalue4 - 1 & 7, local_98[uvalue8] != 0)) {
        uvalue10 = uvalue4 & 7;
        if (local_98[uvalue10] == 0) {
          if ((local_98[uvalue4 + 1 & 7] == 0) || (local_30[uvalue10] < 3)) {
            if ((local_98[uvalue4 - 3 & 7] == 0) || (*(int *)((intptr_t)local_30 + value9) < 3)) {
              local_98[uvalue8] = 0;
            }
            else {
LAB_004f8f06:
              *(uint32_t *)((intptr_t)local_98 + value9) = 1;
            }
          }
          else {
            local_98[uvalue10] = 1;
          }
        }
        else {
          uvalue8 = uvalue4 + 1 & 7;
          if (local_98[uvalue8] == 0) {
            if (local_30[uvalue8] <= *(int *)((intptr_t)local_30 + value9)) goto LAB_004f8f06;
            local_98[uvalue8] = 1;
          }
        }
      }
      value9 = value9 + 4;
      value5 = uvalue4 - 1;
      uvalue4 = uvalue4 + 1;
    } while (value5 < 8);
    value5 = 0;
    ptr6 = local_98;
    value9 = 8;
    do {
      if (*ptr6 == 0) {
        value5 = value5 + 1;
      }
      ptr6 = ptr6 + 1;
      value9 = value9 + -1;
    } while (value9 != 0);
    if (value5 == 8) {
      value9 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
      if (value9 != *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
        UI_ShiftRowData(self,arg1,0);
        local_4 = 0xffffffff;
        List_Node_Destroy(local_6c);
        ExceptionList = local_c;
        return 0;
      }
      local_98[3] = 1;
      local_98[4] = 1;
      local_98[5] = 1;
    }
    else if (value5 < 2) {
      value9 = 0;
      value11 = 1;
      ptr6 = local_30;
      do {
        ptr6 = ptr6 + 1;
        if (*ptr6 < local_30[0]) {
          value9 = value11;
          local_30[0] = *ptr6;
        }
        value11 = value11 + 1;
      } while (value11 < 8);
      local_98[value9] = 0;
      if (value5 < 1) {
        uvalue4 = value9 - 1U & 7;
        uvalue8 = value9 + 1U & 7;
        if (local_98[uvalue8] < local_98[uvalue4]) {
          local_98[uvalue8] = 0;
        }
        else {
          local_98[uvalue4] = 0;
        }
      }
    }
    goto LAB_004f8ffe;
  }
  ptr6 = local_98;
  for (value9 = 8; value9 != 0; value9 = value9 + -1) {
    *ptr6 = 0;
    ptr6 = ptr6 + 1;
  }
  ptr6 = local_30;
  for (value9 = 8; value9 != 0; value9 = value9 + -1) {
    *ptr6 = 0;
    ptr6 = ptr6 + 1;
  }
  value9 = *(int *)((intptr_t)arg1 + 0x38);
  if (value9 == 0) {
LAB_004f8dc7:
    local_98[3] = 1;
    local_98[7] = 1;
    local_98[6] = 1;
    local_98[5] = 1;
    local_98[4] = 1;
  }
  else if ((0 < value9) && (value9 < 3)) {
    local_98[2] = 1;
    goto LAB_004f8dc7;
  }
  value9 = 0;
  do {
    if (*(int *)((intptr_t)local_98 + value9) != 0) {
      *(uint32_t *)((intptr_t)local_30 + value9) = 10;
    }
    value9 = value9 + 4;
  } while (value9 < 0x20);
  local_30[7] = 5;
  if (local_98[2] == 0) {
    local_30[3] = 5;
  }
  else {
    local_30[2] = 5;
  }
LAB_004f8ffe:
  local_98[9] = 3;
  value9 = 0;
  uvalue4 = 2;
  ptr6 = local_98;
  do {
    if (((*ptr6 != 0) && (local_98[uvalue4 - 1 & 7] != 0)) && (local_98[uvalue4 & 7] != 0)) {
      local_98[9] = value9;
      break;
    }
    value9 = value9 + 1;
    ptr6 = ptr6 + 1;
    uvalue4 = uvalue4 + 1;
  } while ((intptr_t)uvalue4 < 10);
  local_98[8] = 0;
  value9 = local_98[10];
  do {
    if (local_98[8] == 0) {
      local_a4 = 0;
    }
    else if (local_98[8] == 1) {
      local_a4 = 2;
    }
    else if (local_98[8] == 2) {
      local_a4 = 3;
    }
    value5 = Game_CountObjectsByType(arg1,0xffffffff);
    value11 = 0;
    if (0 < value5) {
      do {
        ptr6 = (int *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x1500),value11,(int *)0x0);
        value2 = *ptr6;
        flag1 = *(uint8_t *)(value2 + 0x824);
        local_10 = CONCAT31(((uint8_t)((local_10) >> 24)),flag1);
        if (flag1 == local_a4) {
          List_Add(local_6c,ptr6);
        }
        if (*(char *)(value2 + 0x824) == '\x01') {
          ptr6[1] = local_98[9];
        }
        value11 = value11 + 1;
      } while (value11 < value5);
    }
    if (arg2 == 0) {
      value5 = *(int *)((intptr_t)arg1 + 0x38);
      if (value5 == 0) {
        value9 = (-(uint32_t)(local_a4 != 3) & 0xfffffffd) + 5;
      }
      else if (value5 == 1) {
        value9 = (-(uint32_t)(local_a4 != 3) & 0xfffffffd) + 6;
      }
      else if (value5 == 2) {
        value9 = (-(uint32_t)(local_a4 != 3) & 0xfffffffd) + 7;
      }
      ptr6 = local_30;
      ptr12 = local_50;
      for (value5 = 8; value5 != 0; value5 = value5 + -1) {
        *ptr12 = *ptr6;
        ptr6 = ptr6 + 1;
        ptr12 = ptr12 + 1;
      }
    }
    else {
      value9 = 0;
      if (local_a4 == 0) {
        psVar7 = (short *)(arg2 + 0x30);
        local_ac = (short *)(arg2 + 0x20);
        ptr6 = local_30;
        ptr12 = local_50;
        for (value5 = 8; value5 != 0; value5 = value5 + -1) {
          *ptr12 = *ptr6;
          ptr6 = ptr6 + 1;
          ptr12 = ptr12 + 1;
        }
        value5 = 8;
        do {
          value9 = value9 + ((intptr_t)psVar7[-10] >> 2);
          if (0x32 < *psVar7) {
            value9 = value9 - (intptr_t)*local_ac / (intptr_t)*psVar7;
          }
          psVar7 = psVar7 + 0x1a;
          local_ac = local_ac + 0x1a;
          value5 = value5 + -1;
        } while (value5 != 0);
LAB_004f92c5:
        if (value9 < 4) {
          if (value9 < 2) {
            if (-2 < value9) goto LAB_004f92e7;
            value9 = -1;
          }
          else {
            value9 = 1;
          }
        }
        else {
          value9 = 2;
        }
      }
      else {
        if (local_a4 == 2) {
          psVar7 = (short *)(arg2 + 0x30);
          local_ac = (short *)(arg2 + 0x24);
          ptr6 = local_30;
          ptr12 = local_50;
          for (value5 = 8; value5 != 0; value5 = value5 + -1) {
            *ptr12 = *ptr6;
            ptr6 = ptr6 + 1;
            ptr12 = ptr12 + 1;
          }
          value5 = 8;
          do {
            value9 = value9 + ((intptr_t)psVar7[-0xd] >> 2);
            if (0x32 < *psVar7) {
              value9 = value9 - (intptr_t)*local_ac / (intptr_t)*psVar7;
            }
            psVar7 = psVar7 + 0x1a;
            local_ac = local_ac + 0x1a;
            value5 = value5 + -1;
          } while (value5 != 0);
          goto LAB_004f92c5;
        }
        if (local_a4 == 3) {
          psVar7 = (short *)(arg2 + 0x30);
          local_ac = (short *)(arg2 + 0x26);
          ptr6 = local_30;
          ptr12 = local_50;
          for (value9 = 8; value9 != 0; value9 = value9 + -1) {
            *ptr12 = *ptr6;
            ptr6 = ptr6 + 1;
            ptr12 = ptr12 + 1;
          }
          local_a8 = (int *)0x8;
          do {
            value9 = Game_CountObjectsByType(arg1,2);
            value5 = Game_CountObjectsByType(arg1,3);
            value9 = value9 * 2 - value5;
            if (0x32 < *psVar7) {
              value9 = value9 - (intptr_t)*local_ac / (intptr_t)*psVar7;
            }
            if (value5 + value9 < 2) {
              value9 = 2 - value5;
            }
            local_ac = local_ac + 0x1a;
            psVar7 = psVar7 + 0x1a;
            local_a8 = (int *)((intptr_t)local_a8 + -1);
          } while (local_a8 != (int *)0x0);
          goto LAB_004f92c5;
        }
LAB_004f92e7:
        value9 = 0;
      }
    }
    local_a8 = local_98;
    local_ac = (short *)0x2;
    do {
      if ((*local_a8 == 0) && (uvalue4 = (intptr_t)local_ac - 1U & 7, local_98[uvalue4] != 0)) {
        value11 = 1;
        value5 = local_98[(uint32_t)local_ac & 7];
        psVar7 = local_ac;
        while (value5 != 0) {
          value11 = value11 + 1;
          psVar7 = (short *)((intptr_t)psVar7 + 1);
          value5 = local_98[(uint32_t)psVar7 & 7];
        }
        ptr6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
        if (ptr6 == (int *)0x0) {
          ptr6 = City_AssignPersonToBuilding(arg1,local_a4);
          value9 = value9 + -1;
          local_a0 = 1;
          if (value9 < 0) {
            value9 = 0;
          }
        }
        else {
          IDMap_RemoveRecursive(local_6c,0);
        }
        ptr6[1] = uvalue4;
        local_50[uvalue4] = local_50[uvalue4] + -6;
        uvalue8 = uvalue4 + 1 & 7;
        uvalue4 = uvalue4 + 2 & 7;
        local_50[uvalue8] = local_50[uvalue8] + -6;
        local_50[uvalue4] = local_50[uvalue4] + -6;
        if (3 < value11) {
          ptr6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
          if (ptr6 == (int *)0x0) {
            ptr6 = City_AssignPersonToBuilding(arg1,local_a4);
            value9 = value9 + -1;
            local_a0 = 1;
            if (value9 < 0) {
              value9 = 0;
            }
          }
          else {
            IDMap_RemoveRecursive(local_6c,0);
          }
          uvalue4 = ((intptr_t)local_ac - 4U) + value11 & 7;
          ptr6[1] = uvalue4;
          local_50[uvalue4] = local_50[uvalue4] + -6;
          uvalue8 = uvalue4 + 1 & 7;
          local_50[uvalue8] = local_50[uvalue8] + -6;
          local_50[uvalue4 + 2 & 7] = local_50[uvalue4 + 2 & 7] + -6;
        }
        if (6 < value11) {
          ptr6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
          if (ptr6 == (int *)0x0) {
            ptr6 = City_AssignPersonToBuilding(arg1,local_a4);
            value9 = value9 + -1;
            local_a0 = 1;
            if (value9 < 0) {
              value9 = 0;
            }
          }
          else {
            IDMap_RemoveRecursive(local_6c,0);
          }
          uvalue4 = (uint32_t)local_ac & 7;
          if (local_30[uvalue4] <= local_30[(intptr_t)local_ac - 5U & 7]) {
            uvalue4 = (intptr_t)local_ac + 1U & 7;
          }
          uvalue8 = uvalue4 + 1 & 7;
          ptr6[1] = uvalue4;
          local_50[uvalue4] = local_50[uvalue4] + -6;
          local_50[uvalue8] = local_50[uvalue8] + -6;
          local_50[uvalue4 + 2 & 7] = local_50[uvalue4 + 2 & 7] + -6;
        }
      }
      local_a8 = local_a8 + 1;
      value5 = (intptr_t)local_ac - 1;
      local_ac = (short *)((intptr_t)local_ac + 1);
    } while (value5 < 8);
    if ((value9 < 0) && (0 < local_58)) {
      ptr6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
      Branch_RemoveStaffMember(arg1,ptr6,0);
      IDMap_RemoveRecursive(local_6c,0);
      local_a0 = 1;
    }
    value5 = value9;
    if (0 < value9) {
      local_a0 = 1;
      do {
        ptr6 = City_AssignPersonToBuilding(arg1,local_a4);
        List_Add(local_6c,ptr6);
        value9 = value9 + -1;
        value5 = 0;
      } while (value9 != 0);
    }
    while (value9 = value5, 0 < local_58) {
      ptr6 = (int *)IDMap_Lookup(local_6c,0,(int *)0x0);
      uvalue4 = 0xffffffff;
      value5 = 0;
      uvalue8 = 1;
      do {
        if ((((*(int *)((intptr_t)local_98 + value5) != 0) && (local_98[uvalue8 & 7] != 0)) &&
            (uvalue10 = uvalue8 + 1 & 7, local_98[uvalue10] != 0)) &&
           ((value11 = local_50[uvalue10] + local_50[uvalue8 & 7] + *(int *)((intptr_t)local_50 + value5),
            uvalue4 == 0xffffffff || (local_98[10] < value11)))) {
          uvalue4 = uvalue8 - 1;
          local_98[10] = value11;
        }
        value5 = value5 + 4;
        flag3 = (intptr_t)uvalue8 < 8;
        uvalue8 = uvalue8 + 1;
      } while (flag3);
      if ((uvalue4 == 0xffffffff) || (local_98[10] < 1)) {
        Branch_RemoveStaffMember(arg1,ptr6,0);
      }
      else {
        ptr6[1] = uvalue4;
        local_50[uvalue4 & 7] = local_50[uvalue4 & 7] + -6;
        uvalue8 = uvalue4 + 1 & 7;
        uvalue4 = uvalue4 + 2 & 7;
        local_50[uvalue8] = local_50[uvalue8] + -6;
        local_50[uvalue4] = local_50[uvalue4] + -6;
      }
      IDMap_RemoveRecursive(local_6c,0);
      value5 = value9;
    }
    local_98[8] = local_98[8] + 1;
    if (2 < local_98[8]) {
      Game_ToggleObjectFlag2(arg1);
      Stats_ResetAverages(arg1);
      local_4 = 0xffffffff;
      List_Node_Destroy(local_6c);
      ExceptionList = local_c;
      return local_a0;
    }
  } while( true );
}
