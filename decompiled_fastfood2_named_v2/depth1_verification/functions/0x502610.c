// rea decompile_all
// name: FUN_00502610
// address: 0x502610
// body: available
// range: 0x502610-0x502807 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_00502610(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_10;
  int local_8;
  
  iVar7 = 0;
  iVar5 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  local_8 = 0;
  local_10 = 2;
  if (((*(int *)(param_1 + 0x44) == 0) && (*(int *)(iVar5 + 0x15c) == 0)) &&
     (local_8 = 1, *(int *)(iVar5 + 0x194) == 0)) {
    local_8 = 2;
  }
  if ((*(int *)(param_1 + 0x44) == 1) && (*(int *)(iVar5 + 0x15c) == 0x14)) {
    iVar6 = 0;
    local_10 = 1;
    do {
      iVar2 = FUN_004017f0((void *)(iVar5 + 0x148),iVar7,(int *)0x0);
      if (*(int *)(iVar2 + 0x38) == 2) {
        iVar6 = iVar6 + 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x14);
    if (iVar6 == 0x14) {
      local_10 = 0;
    }
  }
  if (*(int *)(param_1 + 0x44) == 2) {
    bVar1 = false;
    iVar7 = 0;
    do {
      iVar6 = FUN_00488be0(DAT_0057c670,iVar7);
      if (iVar6 != 0) {
        iVar2 = *(int *)(iVar6 + 0x15c);
        iVar8 = 0;
        if (0 < iVar2) {
          do {
            iVar3 = FUN_004017f0((void *)(iVar6 + 0x148),iVar8,(int *)0x0);
            iVar3 = Game_CountFreeBuildingsByType(*(void **)(iVar3 + 0x16f0),0x17);
            if (iVar3 != 0) {
              bVar1 = true;
              break;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar2);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 6);
    if (!bVar1) {
      local_10 = 1;
    }
  }
  uVar4 = FUN_004034d0(local_8,local_10);
  if (uVar4 == 1) {
    if (*(int *)(param_1 + 0x44) == 1) {
      iVar6 = 0;
      local_8 = 0;
      iVar7 = *(int *)(iVar5 + 0x15c);
      if (0 < iVar7) {
        do {
          iVar2 = FUN_004017f0((void *)(iVar5 + 0x148),iVar6,(int *)0x0);
          if (*(int *)(iVar2 + 0x38) == 2) {
            local_8 = local_8 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar7);
      }
      if (local_8 != iVar7) goto LAB_0050277f;
      if (iVar7 != 0x14) {
LAB_005027a4:
        uVar4 = 2;
        goto LAB_005027b4;
      }
    }
    else {
LAB_0050277f:
      if ((*(int *)(param_1 + 0x44) != 0) || (*(int *)(iVar5 + 0x194) != 0)) goto LAB_005027d5;
      uVar4 = FUN_004034d0(0,1);
      if (uVar4 == 0) goto LAB_005027a4;
    }
    uVar4 = 0;
  }
  else {
    if (uVar4 != 2) goto LAB_005027d5;
LAB_005027b4:
    if (*(int *)(param_1 + 0x44) == 2) {
      *(undefined4 *)(param_1 + 0x84) = 200000;
    }
    if (*(int *)(param_1 + 0x44) == 3) {
      *(undefined4 *)(param_1 + 0x84) = 300000;
    }
  }
LAB_005027d5:
  if ((*(int *)(param_1 + 0x44) == 3) && (uVar4 == 0)) {
    *(undefined4 *)(param_1 + 0x84) = 0x14;
  }
  iVar5 = (*(int *)(param_1 + 0x44) + uVar4 * 4) * 4;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(&DAT_0057276c + iVar5);
  return *(undefined4 *)(&DAT_0057273c + iVar5);
}

