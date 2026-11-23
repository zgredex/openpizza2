// Mission_EvaluateGoals: ported from Pizza Connection 2 at 0x4f5fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5fd0
#include "pc2_port.h"

void __thiscall Mission_EvaluateGoals(void *self,int arg1,char arg2)

{
  void *this_00;
  int *ptr1;
  void *pvVar2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int *ptr7;
  int value8;
  int value9;
  bool flag10;
  bool flag11;
  double fVar12;
  double fVar13;
  int64_t lvalue14;
  uint32_t in_stack_ffffffc8;
  int local_34;
  int local_30;
  int local_24;
  uint32_t local_20;
  int local_1c;
  int local_18 [6];
  
  local_34 = 0;
  local_20 = 3;
  local_1c = 0;
  local_30 = 0;
  do {
    pvVar2 = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    if (*(char *)((intptr_t)self + local_30 + 0xc4) == '\x01') goto switchD_004f6040_default;
    switch(*(uint32_t *)((intptr_t)self + local_30 * 4 + 4)) {
    case 0:
      if (DAT_0057bb20 == '\0') {
        value9 = Game_GetPlayerFieldC20((intptr_t)pvVar2);
        goto joined_r0x004f6435;
      }
      value9 = Game_GetPlayerFieldC20((intptr_t)pvVar2);
      if (5 < value9) goto LAB_004f6960;
      break;
    case 1:
      value9 = *(int *)((intptr_t)self + 0x14);
      goto joined_r0x004f656f;
    case 2:
      value9 = Game_CountRecordsWithFlag16F4((intptr_t)pvVar2);
      if (value9 != 0) goto LAB_004f6960;
      break;
    case 3:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,5,*(int *)((intptr_t)pvVar2 + 0x48));
joined_r0x004f695e:
        if (0x3b < value9) goto LAB_004f6960;
      }
      break;
    case 4:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      value6 = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
          if ((*(char *)(value8 + 0x16f4) == '\x01') && (0 < *(int *)(value8 + 0x38))) {
            local_34 = local_34 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < value9);
      }
      if (0 < local_34) {
        *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
      }
      break;
    case 5:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      in_stack_ffffffc8 = CONCAT13(1,(int3)in_stack_ffffffc8);
      local_24 = 0;
      if (0 < value9) {
        do {
          value8 = 0;
          local_34 = 0;
          value6 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),local_24,(int *)0x0);
          if (*(int *)((intptr_t)pvVar2 + 0x194) < 1) {
LAB_004f619e:
            in_stack_ffffffc8 = in_stack_ffffffc8 & 0xffffff;
          }
          else {
            do {
              this_00 = (void *)IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x180),value8,(int *)0x0);
              flag10 = LookupTable_HasKey(this_00,*(int *)(value6 + 0x3c));
              if (flag10) {
                local_34 = 1;
              }
              value8 = value8 + 1;
            } while (value8 < *(int *)((intptr_t)pvVar2 + 0x194));
            if (local_34 == 0) goto LAB_004f619e;
          }
          local_24 = local_24 + 1;
        } while (local_24 < value9);
        if ((char)(in_stack_ffffffc8 >> 0x18) == '\0') break;
      }
      *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
      break;
    case 6:
      if (9 < *(int *)((intptr_t)self + 0x28)) goto LAB_004f6960;
      break;
    case 7:
      value9 = *(int *)((intptr_t)self + 0x2c);
      goto joined_r0x004f656f;
    case 8:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      value6 = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
          if (0 < *(int *)(value8 + 0x14b4)) {
            *(uint8_t *)(local_30 + 0xc4 + (intptr_t)self) = 1;
          }
          value6 = value6 + 1;
        } while (value6 < value9);
      }
      break;
    case 9:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      value6 = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
          if (3 < *(int *)(value8 + 0x14b4)) {
            local_34 = local_34 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < value9);
      }
      flag11 = false;
      flag10 = local_34 == 0;
      value9 = local_34;
      goto LAB_004f677d;
    case 10:
      value9 = Game_CountObjectsByState(DAT_0057c670,-1);
      value6 = 0;
      local_34 = 0;
      local_18[0] = 0;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      local_18[4] = 0;
      local_18[5] = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),value6,(int *)0x0);
          if (*(int *)(value8 + 0x30) < 8) {
            ptr7 = local_18;
            local_34 = local_34 + 1;
            value3 = 0;
            ptr1 = (int *)(value8 + 0x5c);
            do {
              value8 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
              if ((value3 != value8) && (*ptr1 < 0)) {
                *ptr7 = *ptr7 + 1;
              }
              value3 = value3 + 1;
              ptr1 = ptr1 + 1;
              ptr7 = ptr7 + 1;
            } while (value3 < 6);
          }
          value6 = value6 + 1;
        } while (value6 < value9);
      }
      value9 = 0;
      ptr1 = local_18;
      do {
        if (local_34 / 10 < *ptr1) {
          *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
          goto switchD_004f6040_default;
        }
        value9 = value9 + 1;
        ptr1 = ptr1 + 1;
      } while (value9 < 6);
      *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 0;
      break;
    case 0xb:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,-1,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f66d8;
      }
      break;
    case 0xc:
      if (arg1 == 0) {
        value9 = AI_GetMaxPlanSteps(pvVar2,*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) - 1);
        value6 = 0;
        do {
          pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value6);
          if (((pvVar2 != (void *)0x0) &&
              (value8 = *(int *)((intptr_t)pvVar2 + 0x48),
              value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value8 != value3)) &&
             (value8 = AI_GetMaxPlanSteps(pvVar2,*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10)
                                                - 1), local_34 < value8)) {
            local_34 = value8;
          }
          value6 = value6 + 1;
        } while (value6 < 6);
        if ((local_34 * 2 <= value9) && (0 < value9)) {
          *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
        }
      }
      break;
    case 0xd:
      pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                    *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      value9 = Game_CountRecordsByOwner(pvVar2,0x11);
joined_r0x004f6435:
      if (2 < value9) goto LAB_004f6960;
      break;
    case 0xe:
    case 0x1c:
      if (*(int *)((intptr_t)self + 0xc0) == 0) goto LAB_004f6960;
      break;
    case 0xf:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      value6 = 0;
      local_34 = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
          value8 = *(int *)(value8 + 0x1a04);
          if (((value8 == 2) || (value8 == 0)) || (value8 == 4)) goto LAB_004f64aa;
          if (value8 == 3) {
            local_34 = local_34 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < value9);
        if (1 < local_34) {
LAB_004f64aa:
          *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 0;
          break;
        }
      }
      goto LAB_004f6960;
    case 0x10:
      if (arg1 == 0) {
        value9 = AI_SumPlanSteps(pvVar2,*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) - 1);
        value6 = 0;
        do {
          pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value6);
          if ((pvVar2 != (void *)0x0) &&
             (value8 = *(int *)((intptr_t)pvVar2 + 0x48),
             value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value8 != value3)) {
            value8 = AI_SumPlanSteps(pvVar2,*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10) - 1)
            ;
            local_34 = local_34 + value8;
          }
          value6 = value6 + 1;
        } while (value6 < 6);
        if (local_34 <= value9) goto joined_r0x004f656f;
      }
      break;
    case 0x11:
      if (250000.0 <= *(double *)((intptr_t)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x12:
      value9 = *(int *)((intptr_t)self + 0x58);
joined_r0x004f656f:
      if (0 < value9) {
LAB_004f6960:
        *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
      }
      break;
    case 0x13:
      value9 = *(int *)((intptr_t)self + 0x5c);
      goto joined_r0x004f679a;
    case 0x14:
      value9 = *(int *)((intptr_t)self + 0x60);
      goto joined_r0x004f6739;
    case 0x15:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      if (4 < value9) {
        value6 = 0;
        local_34 = 0;
        if (0 < value9) {
          do {
            value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
            fVar12 = Stats_SumFilteredFloats2
                               (value8,-1,-1,
                                (uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
            fVar13 = Stats_SumFilteredFloats
                               (value8,-1,-1,
                                (uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10));
            if (((double)(float)fVar12 <= fVar13) && ((double)0.0 < fVar13)) {
              local_34 = local_34 + 1;
            }
            value6 = value6 + 1;
          } while (value6 < value9);
          if (4 < local_34) {
            *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
          }
        }
      }
      break;
    case 0x16:
      value9 = Player_ComputeAverageRating((intptr_t)pvVar2);
      in_stack_ffffffc8 = CONCAT13(1,(int3)in_stack_ffffffc8);
      value6 = 0;
      do {
        value8 = Game_GetPlayerBySlot(DAT_0057c670,value6);
        if (((value8 != 0) &&
            (value3 = *(int *)(value8 + 0x48),
            value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value3 != value5)) &&
           (local_34 = Player_ComputeAverageRating(value8), value9 < local_34)) {
          in_stack_ffffffc8 = in_stack_ffffffc8 & 0xffffff;
        }
        value6 = value6 + 1;
      } while (value6 < 6);
      if ((char)(in_stack_ffffffc8 >> 0x18) != '\0') {
        *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
      }
      break;
    case 0x17:
      value9 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      lvalue14 = Game_GetPlayerValueSharePercent(DAT_0057c670,value9);
      value9 = (intptr_t)lvalue14;
joined_r0x004f66d8:
      if (0x31 < value9) goto LAB_004f6960;
      break;
    case 0x18:
      if ((arg1 == 0) &&
         (value9 = Game_GetCategoryShare(DAT_0057c670,3,*(int *)((intptr_t)pvVar2 + 0x48)), 0x45 < value9))
      {
        value9 = Game_GetCategoryShare(DAT_0057c670,5,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f682f;
      }
      break;
    case 0x19:
      value9 = *(int *)((intptr_t)self + 0x74);
joined_r0x004f6739:
      if (value9 < 1) break;
      goto LAB_004f6960;
    case 0x1a:
      if (39999 < *(int *)((intptr_t)self + 0x78)) goto LAB_004f6960;
      break;
    case 0x1b:
      value9 = *(int *)((intptr_t)pvVar2 + 0x15c);
      value6 = 0;
      if (0 < value9) {
        do {
          value8 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x148),value6,(int *)0x0);
          if ((*(char *)(value8 + 0x16f4) == '\x01') && (1 < *(int *)(value8 + 0x38))) {
            local_34 = local_34 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < value9);
      }
      flag11 = SBORROW4(local_34,5);
      flag10 = local_34 == 5;
      value9 = local_34 + -5;
LAB_004f677d:
      if (!flag10 && flag11 == value9 < 0) {
        *(uint8_t *)((intptr_t)self + local_30 + 0xc4) = 1;
      }
      break;
    case 0x1d:
      value9 = *(int *)((intptr_t)self + 0x84);
joined_r0x004f679a:
      if (value9 < 2) break;
      goto LAB_004f6960;
    case 0x1e:
      if (100000.0 <= *(double *)((intptr_t)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x1f:
      if (500000.0 <= *(double *)((intptr_t)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x20:
      if (1000000.0 <= *(double *)((intptr_t)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x21:
      if (2000000.0 <= *(double *)((intptr_t)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x22:
      value9 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      lvalue14 = Game_GetPlayerValueSharePercent(DAT_0057c670,value9);
      value9 = (intptr_t)lvalue14;
joined_r0x004f682f:
      if (0x45 < value9) goto LAB_004f6960;
      break;
    case 0x23:
      value9 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      lvalue14 = Game_GetPlayerValueSharePercent(DAT_0057c670,value9);
      value9 = (intptr_t)lvalue14;
joined_r0x004f687b:
      if (0x4f < value9) goto LAB_004f6960;
      break;
    case 0x24:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,-1,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f687b;
      }
      break;
    case 0x25:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,0,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x26:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,1,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x27:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,2,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x28:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,3,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x29:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,4,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x2a:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,6,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x2b:
      if (arg1 == 0) {
        value9 = Game_GetCategoryShare(DAT_0057c670,7,*(int *)((intptr_t)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0xffffffff:
      local_20 = local_20 - 1;
      local_1c = local_1c + 1;
    }
switchD_004f6040_default:
    local_30 = local_30 + 1;
    if (2 < local_30) {
      if (arg2 != '\0') {
        *(uint8_t *)((intptr_t)self + 0xc4) = 1;
        *(uint8_t *)((intptr_t)self + 0xc5) = 1;
        *(uint8_t *)((intptr_t)self + 0xc6) = 1;
      }
      value9 = 0;
      uvalue4 = (uint32_t)(*(char *)((intptr_t)self + 0xc4) != '\0');
      if (*(char *)((intptr_t)self + 0xc5) != '\0') {
        uvalue4 = uvalue4 + 1;
      }
      if (*(char *)((intptr_t)self + 0xc6) != '\0') {
        uvalue4 = uvalue4 + 1;
      }
      if ((uvalue4 == local_20) && (local_1c != 3)) {
        *(uint8_t *)((intptr_t)self + 0xcc) = 1;
      }
      value6 = 0;
      local_34 = 0;
      value8 = 0x224;
      do {
        if (((*(int *)(value8 + (intptr_t)DAT_0057c670) != 0) &&
            (value3 = *(int *)(*(int *)(value8 + (intptr_t)DAT_0057c670) + 8),
            value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670), value3 != value5)) &&
           (value6 = value6 + 1, *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x90) + 300 + value9) == 0x18))
        {
          local_34 = local_34 + 1;
        }
        value8 = value8 + 4;
        value9 = value9 + 0x168;
      } while (value8 < 0x23c);
      if (value6 == local_34) {
        *(uint8_t *)((intptr_t)self + 0xcc) = 1;
      }
      if (*(char *)((intptr_t)self + 0xcc) != '\0') {
        UI_Briefing_Printf((intptr_t)DAT_0057c670,0x25,6,1,4,0,DAT_00581b14,DAT_0058102c,
                           in_stack_ffffffc8);
        value9 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                           *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
        *(int *)(value9 + 0x30) = *(int *)(value9 + 0x30) + 1;
      }
      return;
    }
  } while( true );
}
