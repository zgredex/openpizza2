// rea decompile_all
// name: FUN_004fe5f0
// address: 0x4fe5f0
// body: available
// range: 0x4fe5f0-0x4fe864 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fe5f0(void *this,int param_1,undefined4 *param_2)

{
  void *this_00;
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  longlong lVar12;
  int local_16c;
  undefined4 local_160;
  int local_15c;
  int local_158 [86];
  
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  if (param_2[2] != 3) {
    FUN_004e3ab0(this_00,param_2,0);
  }
  iVar8 = param_2[2];
  if (iVar8 == 1) {
    local_160 = 10000;
    iVar8 = Game_GetPlayerFieldC20((int)this_00);
    if (iVar8 < 3) {
      return 0;
    }
    if (*(int *)((int)this_00 + 0x15c) < 3) {
      return 0;
    }
  }
  else if (iVar8 == 2) {
    local_160 = 5000;
  }
  else if (iVar8 == 3) {
    local_160 = 0xdac;
  }
  param_2[8] = local_160;
  iVar8 = *(int *)((int)this_00 + 0x124);
  if (0 < iVar8) {
    piVar9 = local_158;
    for (iVar7 = 0x56; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar9 = 0;
      piVar9 = piVar9 + 1;
    }
    local_15c = 0;
    if (0 < iVar8) {
      do {
        iVar7 = FUN_004017f0((void *)((int)this_00 + 0x110),local_15c,(int *)0x0);
        if ((iVar7 != 0) && (*(char *)(iVar7 + 0x1dc) != '\0')) {
          piVar11 = local_158;
          piVar9 = (int *)(iVar7 + 100);
          local_16c = 0x56;
          do {
            if (0 < *piVar9) {
              lVar12 = __ftol();
              *piVar11 = *piVar11 + (int)lVar12 * *piVar9;
            }
            piVar9 = piVar9 + 1;
            piVar11 = piVar11 + 1;
            local_16c = local_16c + -1;
          } while (local_16c != 0);
        }
        local_15c = local_15c + 1;
      } while (local_15c < iVar8);
    }
    iVar7 = 0;
    iVar8 = 0;
    iVar4 = 0;
    piVar9 = local_158;
    do {
      if (iVar8 < *piVar9) {
        iVar8 = *piVar9;
        iVar7 = iVar4;
      }
      iVar4 = iVar4 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar4 < 0x56);
    if (0 < iVar8) {
      param_2[6] = iVar7 + 1;
    }
  }
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[7] = 0xffffffff;
  iVar4 = FUN_0050f840(param_2,iVar1);
  iVar7 = 0;
  local_16c = 0;
  iVar8 = 1;
  do {
    param_2[4] = iVar8;
    iVar5 = FUN_0050f840(param_2,iVar1);
    if (iVar7 == 0) {
LAB_004fe794:
      iVar7 = iVar5 - iVar4;
      local_16c = iVar8;
    }
    else if (iVar7 < iVar5 - iVar4) goto LAB_004fe794;
    bVar3 = iVar8 < 0xc;
    iVar8 = iVar8 + 1;
  } while (bVar3);
  if (iVar7 < 1) {
    param_2[4] = 0;
  }
  else {
    iVar4 = iVar4 + iVar7;
    param_2[4] = local_16c;
  }
  uVar10 = 1;
  do {
    uVar2 = param_2[5];
    param_2[5] = uVar2 | uVar10;
    iVar8 = FUN_0050f840(param_2,iVar1);
    if (iVar8 - iVar4 < 1) {
      param_2[5] = uVar2;
    }
    else {
      iVar4 = iVar4 + (iVar8 - iVar4);
    }
    uVar10 = uVar10 * 2;
  } while ((int)uVar10 < 0x10);
  iVar5 = 0;
  local_16c = 0;
  iVar8 = 0;
  iVar7 = FUN_00482720(DAT_0057c670);
  if (0 < iVar7) {
    do {
      if (iVar5 != iVar1) {
        param_2[7] = iVar5;
        iVar6 = FUN_0050f840(param_2,iVar1);
        if (iVar8 != 0) {
          if (iVar6 - iVar4 <= iVar8) goto LAB_004fe826;
        }
        iVar8 = iVar6 - iVar4;
        local_16c = iVar5;
      }
LAB_004fe826:
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar7);
    if (0 < iVar8) {
      param_2[7] = local_16c;
      return 1;
    }
  }
  param_2[7] = 0xffffffff;
  return 1;
}

