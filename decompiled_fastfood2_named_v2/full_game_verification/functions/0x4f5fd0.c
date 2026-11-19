// rea decompile_all
// name: Mission_EvaluateGoals
// address: 0x4f5fd0
// body: available
// range: 0x4f5fd0-0x4f6a9b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Mission_EvaluateGoals(void *this,int param_1,char param_2)

{
  void *this_00;
  int *piVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  float10 fVar12;
  float10 fVar13;
  longlong lVar14;
  uint in_stack_ffffffc8;
  int local_34;
  int local_30;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18 [6];
  
  local_34 = 0;
  local_20 = 3;
  local_1c = 0;
  local_30 = 0;
  do {
    pvVar2 = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    if (*(char *)((int)this + local_30 + 0xc4) == '\x01') goto switchD_004f6040_default;
    switch(*(undefined4 *)((int)this + local_30 * 4 + 4)) {
    case 0:
      if (DAT_0057bb20 == '\0') {
        iVar9 = Game_GetPlayerFieldC20((int)pvVar2);
        goto joined_r0x004f6435;
      }
      iVar9 = Game_GetPlayerFieldC20((int)pvVar2);
      if (5 < iVar9) goto LAB_004f6960;
      break;
    case 1:
      iVar9 = *(int *)((int)this + 0x14);
      goto joined_r0x004f656f;
    case 2:
      iVar9 = Game_CountRecordsWithFlag16F4((int)pvVar2);
      if (iVar9 != 0) goto LAB_004f6960;
      break;
    case 3:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,5,*(int *)((int)pvVar2 + 0x48));
joined_r0x004f695e:
        if (0x3b < iVar9) goto LAB_004f6960;
      }
      break;
    case 4:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      iVar6 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
          if ((*(char *)(iVar8 + 0x16f4) == '\x01') && (0 < *(int *)(iVar8 + 0x38))) {
            local_34 = local_34 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
      }
      if (0 < local_34) {
        *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
      }
      break;
    case 5:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      in_stack_ffffffc8 = CONCAT13(1,(int3)in_stack_ffffffc8);
      local_24 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = 0;
          local_34 = 0;
          iVar6 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),local_24,(int *)0x0);
          if (*(int *)((int)pvVar2 + 0x194) < 1) {
LAB_004f619e:
            in_stack_ffffffc8 = in_stack_ffffffc8 & 0xffffff;
          }
          else {
            do {
              this_00 = (void *)IDMap_Lookup((void *)((int)pvVar2 + 0x180),iVar8,(int *)0x0);
              bVar10 = LookupTable_HasKey(this_00,*(int *)(iVar6 + 0x3c));
              if (bVar10) {
                local_34 = 1;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)((int)pvVar2 + 0x194));
            if (local_34 == 0) goto LAB_004f619e;
          }
          local_24 = local_24 + 1;
        } while (local_24 < iVar9);
        if ((char)(in_stack_ffffffc8 >> 0x18) == '\0') break;
      }
      *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
      break;
    case 6:
      if (9 < *(int *)((int)this + 0x28)) goto LAB_004f6960;
      break;
    case 7:
      iVar9 = *(int *)((int)this + 0x2c);
      goto joined_r0x004f656f;
    case 8:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      iVar6 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
          if (0 < *(int *)(iVar8 + 0x14b4)) {
            *(undefined1 *)(local_30 + 0xc4 + (int)this) = 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
      }
      break;
    case 9:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      iVar6 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
          if (3 < *(int *)(iVar8 + 0x14b4)) {
            local_34 = local_34 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
      }
      bVar11 = false;
      bVar10 = local_34 == 0;
      iVar9 = local_34;
      goto LAB_004f677d;
    case 10:
      iVar9 = Game_CountObjectsByState(DAT_0057c670,-1);
      iVar6 = 0;
      local_34 = 0;
      local_18[0] = 0;
      local_18[1] = 0;
      local_18[2] = 0;
      local_18[3] = 0;
      local_18[4] = 0;
      local_18[5] = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),iVar6,(int *)0x0);
          if (*(int *)(iVar8 + 0x30) < 8) {
            piVar7 = local_18;
            local_34 = local_34 + 1;
            iVar3 = 0;
            piVar1 = (int *)(iVar8 + 0x5c);
            do {
              iVar8 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
              if ((iVar3 != iVar8) && (*piVar1 < 0)) {
                *piVar7 = *piVar7 + 1;
              }
              iVar3 = iVar3 + 1;
              piVar1 = piVar1 + 1;
              piVar7 = piVar7 + 1;
            } while (iVar3 < 6);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
      }
      iVar9 = 0;
      piVar1 = local_18;
      do {
        if (local_34 / 10 < *piVar1) {
          *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
          goto switchD_004f6040_default;
        }
        iVar9 = iVar9 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar9 < 6);
      *(undefined1 *)((int)this + local_30 + 0xc4) = 0;
      break;
    case 0xb:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,-1,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f66d8;
      }
      break;
    case 0xc:
      if (param_1 == 0) {
        iVar9 = AI_GetMaxPlanSteps(pvVar2,*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10) - 1);
        iVar6 = 0;
        do {
          pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar6);
          if (((pvVar2 != (void *)0x0) &&
              (iVar8 = *(int *)((int)pvVar2 + 0x48),
              iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670), iVar8 != iVar3)) &&
             (iVar8 = AI_GetMaxPlanSteps(pvVar2,*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10)
                                                - 1), local_34 < iVar8)) {
            local_34 = iVar8;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 6);
        if ((local_34 * 2 <= iVar9) && (0 < iVar9)) {
          *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
        }
      }
      break;
    case 0xd:
      pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                    *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      iVar9 = Game_CountRecordsByOwner(pvVar2,0x11);
joined_r0x004f6435:
      if (2 < iVar9) goto LAB_004f6960;
      break;
    case 0xe:
    case 0x1c:
      if (*(int *)((int)this + 0xc0) == 0) goto LAB_004f6960;
      break;
    case 0xf:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      iVar6 = 0;
      local_34 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
          iVar8 = *(int *)(iVar8 + 0x1a04);
          if (((iVar8 == 2) || (iVar8 == 0)) || (iVar8 == 4)) goto LAB_004f64aa;
          if (iVar8 == 3) {
            local_34 = local_34 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
        if (1 < local_34) {
LAB_004f64aa:
          *(undefined1 *)((int)this + local_30 + 0xc4) = 0;
          break;
        }
      }
      goto LAB_004f6960;
    case 0x10:
      if (param_1 == 0) {
        iVar9 = AI_SumPlanSteps(pvVar2,*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10) - 1);
        iVar6 = 0;
        do {
          pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar6);
          if ((pvVar2 != (void *)0x0) &&
             (iVar8 = *(int *)((int)pvVar2 + 0x48),
             iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670), iVar8 != iVar3)) {
            iVar8 = AI_SumPlanSteps(pvVar2,*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10) - 1)
            ;
            local_34 = local_34 + iVar8;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 6);
        if (local_34 <= iVar9) goto joined_r0x004f656f;
      }
      break;
    case 0x11:
      if (250000.0 <= *(double *)((int)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x12:
      iVar9 = *(int *)((int)this + 0x58);
joined_r0x004f656f:
      if (0 < iVar9) {
LAB_004f6960:
        *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
      }
      break;
    case 0x13:
      iVar9 = *(int *)((int)this + 0x5c);
      goto joined_r0x004f679a;
    case 0x14:
      iVar9 = *(int *)((int)this + 0x60);
      goto joined_r0x004f6739;
    case 0x15:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      if (4 < iVar9) {
        iVar6 = 0;
        local_34 = 0;
        if (0 < iVar9) {
          do {
            iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
            fVar12 = Stats_SumFilteredFloats2
                               (iVar8,-1,-1,
                                (uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
            fVar13 = Stats_SumFilteredFloats
                               (iVar8,-1,-1,
                                (uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
            if (((float10)(float)fVar12 <= fVar13) && ((float10)0.0 < fVar13)) {
              local_34 = local_34 + 1;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar9);
          if (4 < local_34) {
            *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
          }
        }
      }
      break;
    case 0x16:
      iVar9 = Player_ComputeAverageRating((int)pvVar2);
      in_stack_ffffffc8 = CONCAT13(1,(int3)in_stack_ffffffc8);
      iVar6 = 0;
      do {
        iVar8 = Game_GetPlayerBySlot(DAT_0057c670,iVar6);
        if (((iVar8 != 0) &&
            (iVar3 = *(int *)(iVar8 + 0x48),
            iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670), iVar3 != iVar5)) &&
           (local_34 = Player_ComputeAverageRating(iVar8), iVar9 < local_34)) {
          in_stack_ffffffc8 = in_stack_ffffffc8 & 0xffffff;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      if ((char)(in_stack_ffffffc8 >> 0x18) != '\0') {
        *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
      }
      break;
    case 0x17:
      iVar9 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      lVar14 = Game_GetPlayerValueSharePercent(DAT_0057c670,iVar9);
      iVar9 = (int)lVar14;
joined_r0x004f66d8:
      if (0x31 < iVar9) goto LAB_004f6960;
      break;
    case 0x18:
      if ((param_1 == 0) &&
         (iVar9 = Game_GetCategoryShare(DAT_0057c670,3,*(int *)((int)pvVar2 + 0x48)), 0x45 < iVar9))
      {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,5,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f682f;
      }
      break;
    case 0x19:
      iVar9 = *(int *)((int)this + 0x74);
joined_r0x004f6739:
      if (iVar9 < 1) break;
      goto LAB_004f6960;
    case 0x1a:
      if (39999 < *(int *)((int)this + 0x78)) goto LAB_004f6960;
      break;
    case 0x1b:
      iVar9 = *(int *)((int)pvVar2 + 0x15c);
      iVar6 = 0;
      if (0 < iVar9) {
        do {
          iVar8 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),iVar6,(int *)0x0);
          if ((*(char *)(iVar8 + 0x16f4) == '\x01') && (1 < *(int *)(iVar8 + 0x38))) {
            local_34 = local_34 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar9);
      }
      bVar11 = SBORROW4(local_34,5);
      bVar10 = local_34 == 5;
      iVar9 = local_34 + -5;
LAB_004f677d:
      if (!bVar10 && bVar11 == iVar9 < 0) {
        *(undefined1 *)((int)this + local_30 + 0xc4) = 1;
      }
      break;
    case 0x1d:
      iVar9 = *(int *)((int)this + 0x84);
joined_r0x004f679a:
      if (iVar9 < 2) break;
      goto LAB_004f6960;
    case 0x1e:
      if (100000.0 <= *(double *)((int)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x1f:
      if (500000.0 <= *(double *)((int)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x20:
      if (1000000.0 <= *(double *)((int)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x21:
      if (2000000.0 <= *(double *)((int)pvVar2 + 0x108)) goto LAB_004f6960;
      break;
    case 0x22:
      iVar9 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      lVar14 = Game_GetPlayerValueSharePercent(DAT_0057c670,iVar9);
      iVar9 = (int)lVar14;
joined_r0x004f682f:
      if (0x45 < iVar9) goto LAB_004f6960;
      break;
    case 0x23:
      iVar9 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      lVar14 = Game_GetPlayerValueSharePercent(DAT_0057c670,iVar9);
      iVar9 = (int)lVar14;
joined_r0x004f687b:
      if (0x4f < iVar9) goto LAB_004f6960;
      break;
    case 0x24:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,-1,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f687b;
      }
      break;
    case 0x25:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,0,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x26:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,1,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x27:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,2,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x28:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,3,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x29:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,4,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x2a:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,6,*(int *)((int)pvVar2 + 0x48));
        goto joined_r0x004f695e;
      }
      break;
    case 0x2b:
      if (param_1 == 0) {
        iVar9 = Game_GetCategoryShare(DAT_0057c670,7,*(int *)((int)pvVar2 + 0x48));
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
      if (param_2 != '\0') {
        *(undefined1 *)((int)this + 0xc4) = 1;
        *(undefined1 *)((int)this + 0xc5) = 1;
        *(undefined1 *)((int)this + 0xc6) = 1;
      }
      iVar9 = 0;
      uVar4 = (uint)(*(char *)((int)this + 0xc4) != '\0');
      if (*(char *)((int)this + 0xc5) != '\0') {
        uVar4 = uVar4 + 1;
      }
      if (*(char *)((int)this + 0xc6) != '\0') {
        uVar4 = uVar4 + 1;
      }
      if ((uVar4 == local_20) && (local_1c != 3)) {
        *(undefined1 *)((int)this + 0xcc) = 1;
      }
      iVar6 = 0;
      local_34 = 0;
      iVar8 = 0x224;
      do {
        if (((*(int *)(iVar8 + (int)DAT_0057c670) != 0) &&
            (iVar3 = *(int *)(*(int *)(iVar8 + (int)DAT_0057c670) + 8),
            iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670), iVar3 != iVar5)) &&
           (iVar6 = iVar6 + 1, *(int *)(*(int *)((int)DAT_0057c670 + 0x90) + 300 + iVar9) == 0x18))
        {
          local_34 = local_34 + 1;
        }
        iVar8 = iVar8 + 4;
        iVar9 = iVar9 + 0x168;
      } while (iVar8 < 0x23c);
      if (iVar6 == local_34) {
        *(undefined1 *)((int)this + 0xcc) = 1;
      }
      if (*(char *)((int)this + 0xcc) != '\0') {
        UI_Briefing_Printf((int)DAT_0057c670,0x25,6,1,4,0,DAT_00581b14,DAT_0058102c,
                           in_stack_ffffffc8);
        iVar9 = Game_GetPlayerCity(*(int *)((int)DAT_0057c670 +
                                           *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
        *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x30) + 1;
      }
      return;
    }
  } while( true );
}

