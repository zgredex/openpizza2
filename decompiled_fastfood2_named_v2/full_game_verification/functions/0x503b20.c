// rea decompile_all
// name: MissionGoal_ApplyFailureEffects
// address: 0x503b20
// body: available
// range: 0x503b20-0x504305 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall MissionGoal_ApplyFailureEffects(int param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
                    /* Applies a mission goal's failure effects. */
  iVar5 = *(int *)(param_1 + 0x54);
  switch(iVar5) {
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
  case 7:
  case 8:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x13:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x25:
  case 0x31:
  case 0x32:
  case 0x34:
  case 0x37:
  case 0x38:
    iVar6 = *(int *)(param_1 + 0x16c + iVar5 * 4);
    goto LAB_0050429c;
  case 4:
  case 0x30:
    *(undefined4 *)(param_1 + 0x16c + iVar5 * 4) = 0x30;
    break;
  case 9:
    Game_CanAffordWithCurrency
              (*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               5000.0,'\0',(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
    break;
  case 10:
    Game_CanAffordWithCurrency
              (*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               25000.0,'\0',(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
    break;
  case 0xb:
    Game_CanAffordWithCurrency
              (*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               50000.0,'\0',(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
    break;
  case 0xc:
    Game_CanAffordWithCurrency
              (*(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),0x18,
               100000.0,'\0',(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
    break;
  case 0x10:
    iVar6 = *(int *)(param_1 + 0x16c + iVar5 * 4) + 0x30;
    goto LAB_0050429d;
  case 0x11:
    local_4 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(iVar5 + 0x148),local_4,(int *)0x0);
        iVar7 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar3 = 0;
        if (0 < iVar7) {
          do {
            puVar4 = (undefined4 *)IDMap_Lookup((void *)((int)pvVar2 + 0x1500),iVar3,(int *)0x0);
            pvVar1 = (void *)*puVar4;
            if (*(char *)((int)pvVar1 + 0x824) == '\x02') {
              Person_SetSkill(pvVar1,(*(int *)((int)pvVar1 + 4) * 0x5f) / 100);
              Person_SetSpeed((void *)*puVar4,(*(int *)((int)*puVar4 + 8) * 0x5f) / 100);
              Person_SetMotivation((void *)*puVar4,(*(int *)((int)*puVar4 + 0xc) * 0x5f) / 100);
              Person_SetHealth((void *)*puVar4,(*(int *)((int)*puVar4 + 0x10) * 0x5f) / 100);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar7);
        }
        local_4 = local_4 + 1;
      } while (local_4 < iVar6);
    }
    break;
  case 0x12:
    local_4 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(iVar5 + 0x148),local_4,(int *)0x0);
        iVar7 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar3 = 0;
        if (0 < iVar7) {
          do {
            puVar4 = (undefined4 *)IDMap_Lookup((void *)((int)pvVar2 + 0x1500),iVar3,(int *)0x0);
            pvVar1 = (void *)*puVar4;
            if (*(char *)((int)pvVar1 + 0x824) == '\0') {
              Person_SetSkill(pvVar1,(*(int *)((int)pvVar1 + 4) * 0x5f) / 100);
              Person_SetSpeed((void *)*puVar4,(*(int *)((int)*puVar4 + 8) * 0x5f) / 100);
              Person_SetMotivation((void *)*puVar4,(*(int *)((int)*puVar4 + 0xc) * 0x5f) / 100);
              Person_SetHealth((void *)*puVar4,(*(int *)((int)*puVar4 + 0x10) * 0x5f) / 100);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < iVar7);
        }
        local_4 = local_4 + 1;
      } while (local_4 < iVar6);
    }
    break;
  case 0x14:
    iVar7 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(iVar5 + 0x148),iVar7,(int *)0x0);
        iVar3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar8 = 0;
        if (0 < iVar3) {
          do {
            puVar4 = (undefined4 *)IDMap_Lookup((void *)((int)pvVar2 + 0x1500),iVar8,(int *)0x0);
            Person_SetPerformance((void *)*puVar4,(*(int *)((int)*puVar4 + 0x3c) * 0xb) / 10);
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar3);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
    break;
  case 0x15:
  case 0x16:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2d:
  case 0x2e:
    iVar6 = *(int *)(param_1 + 0x16c + iVar5 * 4) + 5;
    goto LAB_0050429d;
  case 0x18:
    *(int *)(param_1 + 0x16c + iVar5 * 4) = *(int *)(param_1 + 0x16c + iVar5 * 4) + 1;
    Company_InvalidateAllBranchRatings
              (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
    break;
  case 0x1a:
    iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar6 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar5 = *(int *)(iVar5 + 0xd40 + iVar6 * 4);
    iVar6 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar7 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    *(int *)(iVar6 + 0xd40 + iVar7 * 4) = (iVar5 << 3) / 10;
    break;
  case 0x1b:
    pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    iVar5 = Game_GetPlayerSupplyScore(pvVar2,iVar5);
    iVar6 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar7 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    *(int *)(iVar6 + 0xc98 + iVar7 * 4) = (iVar5 << 3) / 10;
    break;
  case 0x1c:
    iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar6 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (0x19 < *(int *)(iVar5 + 0xcc8 + iVar6 * 4)) {
      iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      iVar6 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      *(undefined4 *)(iVar5 + 0xcc8 + iVar6 * 4) = 0x19;
    }
    break;
  case 0x1e:
    pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar6 = 0;
    iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    City_AddRandomBuilding(pvVar2,iVar5,iVar6);
    break;
  case 0x1f:
    iVar7 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        iVar3 = IDMap_Lookup((void *)(iVar5 + 0x148),iVar7,(int *)0x0);
        if (0 < *(int *)(iVar3 + 0x14b4)) {
          *(int *)(iVar3 + 0x14b4) = *(int *)(iVar3 + 0x14b4) + -1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
    if (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x25c),-0x18614,0x23,0);
    }
    break;
  case 0x22:
  case 0x27:
    iVar7 = 4;
    iVar6 = -0x28;
    iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,iVar5,iVar6,iVar7);
    iVar6 = 1;
    iVar5 = -0x28;
    goto LAB_0050418e;
  case 0x23:
    iVar6 = *(int *)(param_1 + 0x16c + iVar5 * 4);
    if (iVar6 == 0) {
      iVar5 = Game_GetMostCommonTypeIndex
                        (*(int *)((int)DAT_0057c670 +
                                 *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      if (-1 < iVar5) {
        *(int *)(param_1 + 0x16c + *(int *)(param_1 + 0x54) * 4) = (iVar5 * 5 + 5) * 20000;
      }
      break;
    }
LAB_0050429c:
    iVar6 = iVar6 + 1;
LAB_0050429d:
    *(int *)(param_1 + 0x16c + iVar5 * 4) = iVar6;
    break;
  case 0x24:
    iVar6 = -1;
    iVar5 = -0x14;
LAB_0050418e:
    iVar7 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    Game_ApplyPercentChange(DAT_0057c670,iVar7,iVar5,iVar6);
    break;
  case 0x28:
    iVar6 = -1;
    iVar5 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    City_SendResidentsToVenue(DAT_0057c670,(undefined4 *)0xa,iVar5,iVar6);
    break;
  case 0x2c:
    iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    iVar6 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    *(undefined4 *)(iVar5 + 0xc98 + iVar6 * 4) = 0;
    break;
  case 0x2f:
    iVar7 = 0;
    iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar6 = *(int *)(iVar5 + 0x15c);
    if (0 < iVar6) {
      do {
        pvVar2 = (void *)IDMap_Lookup((void *)(iVar5 + 0x148),iVar7,(int *)0x0);
        iVar3 = Game_CountObjectsByType(pvVar2,0xffffffff);
        iVar8 = 0;
        if (0 < iVar3) {
          do {
            puVar4 = (undefined4 *)IDMap_Lookup((void *)((int)pvVar2 + 0x1500),iVar8,(int *)0x0);
            Person_SetMotivation((void *)*puVar4,(*(int *)((int)*puVar4 + 0xc) * 9) / 10);
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar3);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
  }
  iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  *(int *)(iVar5 + 0x100) = *(int *)(iVar5 + 0x100) + 1;
  iVar5 = Game_GetPlayerCity(*(int *)((int)DAT_0057c670 +
                                     *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  *(int *)(iVar5 + 0x2c) = *(int *)(iVar5 + 0x2c) + 1;
  if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x264),-0x18615,0x23,0);
  }
  return;
}

