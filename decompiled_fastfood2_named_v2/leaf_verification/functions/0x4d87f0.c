// rea decompile_all
// name: FUN_004d87f0
// address: 0x4d87f0
// body: available
// range: 0x4d87f0-0x4d8baf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d87f0(void *this,void *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  void *local_118;
  int local_114;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559174;
  local_c = ExceptionList;
  local_114 = 0;
  ExceptionList = &local_c;
  if (0 < *(int *)((int)this + 0xfc0)) {
    do {
      iVar2 = IDMap_Lookup((void *)((int)this + 0xfac),local_114,(int *)0x0);
      iVar7 = 0;
      switch(*(undefined4 *)(iVar2 + 4)) {
      case 0x10:
        iVar4 = *(int *)(iVar2 + 8);
        iVar7 = iVar4 * 10000 + 18000;
        iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
        if (iVar4 != iVar3) break;
        pvVar5 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar4);
        iVar4 = FUN_004e2330(pvVar5,iVar2);
        if (iVar4 == 0) break;
        uVar8 = 0;
        if (pvVar5 != (void *)0x0) {
          uVar8 = *(undefined4 *)((int)pvVar5 + 0x1dc);
        }
        Get_Subobject4(iVar4);
        FUN_0054dd83(local_10c,(byte *)s__s___s_0056cd9c,DAT_00582158);
        local_118 = operator_new(0x58);
        local_4 = 3;
        if (local_118 == (void *)0x0) goto LAB_004d8a68;
LAB_004d89b5:
        pcVar6 = FUN_00403300(local_118,local_10c,iVar2,uVar8);
        goto LAB_004d8b66;
      default:
        break;
      case 0x17:
        iVar7 = 1;
      case 0x18:
        iVar7 = iVar7 + 1;
switchD_004d8852_caseD_19:
        if (*(int *)(iVar2 + 0x54) != -1) {
          pvVar5 = operator_new(0x58);
          local_4 = 0;
          if (pvVar5 == (void *)0x0) {
            pcVar6 = (char *)0x0;
          }
          else {
            pcVar6 = FUN_00403370(pvVar5,*(char **)(&DAT_005840d4 + *(int *)(iVar2 + 4) * 4),iVar2);
          }
          goto LAB_004d8b66;
        }
        break;
      case 0x19:
        goto switchD_004d8852_caseD_19;
      case 0x1a:
        iVar4 = *(int *)(iVar2 + 8);
        iVar7 = iVar4 * 10000 + 19000;
        if (*(int *)(iVar2 + 0x30) == 0x1c) {
          iVar7 = iVar4 * 10000 + 0x2774;
          iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar4);
          uVar8 = 0;
          if (iVar4 != 0) {
            uVar8 = *(undefined4 *)(iVar4 + 0x1dc);
          }
          FUN_0054dd83(local_10c,(byte *)s__s___s__0056c954,DAT_00584144);
          pvVar5 = operator_new(0x58);
          local_4 = 1;
          if (pvVar5 == (void *)0x0) goto LAB_004d8b4d;
          pcVar6 = FUN_00403300(pvVar5,local_10c,iVar2,uVar8);
          goto LAB_004d8b4f;
        }
        iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
        if (iVar4 != iVar3) break;
        iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar4);
        if (iVar4 == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = *(undefined4 *)(iVar4 + 0x1dc);
        }
        FUN_0054dd83(local_10c,(byte *)s__s___s__0056c954,DAT_005821b0);
        local_118 = operator_new(0x58);
        local_4 = 2;
        if (local_118 != (void *)0x0) goto LAB_004d89b5;
        goto LAB_004d8a68;
      case 0x1c:
        iVar7 = 1;
      case 0xf:
        uVar1 = *(uint *)(iVar2 + 0x2c);
        iVar4 = *(int *)(iVar2 + 8);
        iVar3 = FUN_00489820(DAT_0057c670,iVar4,uVar1);
        if (iVar7 == 0) {
          iVar7 = iVar4 * 10000 + 0x2774 + (uVar1 & 0x7f);
        }
        else {
          iVar7 = iVar4 * 10000 + 0x2774;
        }
        iVar4 = Game_GetPlayerBySlot(DAT_0057c670,iVar4);
        uVar8 = 0;
        if (iVar4 != 0) {
          uVar8 = *(undefined4 *)(iVar4 + 0x1dc);
        }
        if (iVar3 == 0) {
          pvVar5 = operator_new(0x58);
          local_4 = 5;
          if (pvVar5 == (void *)0x0) {
LAB_004d8b4d:
            pcVar6 = (char *)0x0;
          }
          else {
            pcVar6 = FUN_00403300(pvVar5,*(char **)(&DAT_005840d4 + *(int *)(iVar2 + 4) * 4),iVar2,
                                  uVar8);
          }
LAB_004d8b4f:
          *(int *)(pcVar6 + 0x50) = *(int *)(iVar2 + 4) + 10000;
        }
        else {
          pvVar5 = operator_new(0x58);
          local_4 = 4;
          if (pvVar5 == (void *)0x0) {
LAB_004d8a68:
            pcVar6 = (char *)0x0;
          }
          else {
            pcVar6 = FUN_00403300(pvVar5,(char *)(iVar3 + 4),iVar2,uVar8);
          }
        }
LAB_004d8b66:
        local_4 = 0xffffffff;
        if (pcVar6 != (char *)0x0) {
          *(int *)(pcVar6 + 0x50) = iVar7;
          FUN_004014b0(param_1,pcVar6);
        }
      }
      local_114 = local_114 + 1;
    } while (local_114 < *(int *)((int)this + 0xfc0));
  }
  ExceptionList = local_c;
  return;
}

