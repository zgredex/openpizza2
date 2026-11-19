// rea decompile_all
// name: FUN_004ff6e0
// address: 0x4ff6e0
// body: available
// range: 0x4ff6e0-0x4ff8a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004ff6e0(void *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int *piVar8;
  int iVar9;
  uint local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c0 [8];
  undefined4 local_1a0;
  short local_19a [205];
  
  local_1cc = *(int *)((int)param_1 + 0x14ac);
  if ((*(int *)((int)param_1 + 0x14a8) < 0x32) || (0x96 < *(int *)((int)param_1 + 0x14a8))) {
    uVar1 = Random_Range(0x32,0x96);
    *(uint *)((int)param_1 + 0x14a8) = uVar1;
    *(undefined4 *)((int)param_1 + 0x1714) = 0;
  }
  FUN_0047c3c0(param_1,&local_1a0);
  iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)param_1 + 0x34),(int *)0x0);
  piVar3 = (int *)(iVar2 + 0x4c);
  piVar8 = local_1c0;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar8 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar8 = piVar8 + 1;
  }
  psVar7 = local_19a;
  iVar2 = 8;
  do {
    piVar3 = local_1c0;
    iVar5 = 8;
    psVar6 = psVar7;
    do {
      *piVar3 = *piVar3 + (int)*psVar6;
      psVar6 = psVar6 + 1;
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    psVar7 = psVar7 + 0x1a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  piVar3 = local_1c0;
  iVar5 = 8;
  do {
    iVar9 = *piVar3;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + iVar9;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar2 = (iVar2 * 4) / 5;
  local_1d0 = 0x10;
  local_1c8 = 0;
  while( true ) {
    iVar5 = 0;
    iVar9 = 0;
    piVar3 = local_1c0;
    do {
      iVar4 = FUN_0047a3b0(param_1,iVar9,0);
      if (iVar4 < 0x32) {
        if (0x1e < iVar4) {
          iVar5 = iVar5 + ((iVar4 + -0x1e) * *piVar3) / 0x14;
        }
      }
      else {
        iVar5 = iVar5 + *piVar3;
      }
      iVar9 = iVar9 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar9 < 8);
    if (iVar2 < iVar5) {
      if (local_1c8 == -1) {
        local_1d0 = (int)local_1d0 >> 1;
      }
      local_1c8 = 1;
      uVar1 = local_1d0;
    }
    else {
      if (iVar2 <= iVar5) {
        return 1;
      }
      if (local_1c8 == 1) {
        local_1d0 = (int)local_1d0 >> 1;
      }
      uVar1 = -local_1d0;
      local_1c8 = -1;
    }
    local_1cc = local_1cc + uVar1;
    if ((local_1cc < 0) || (99 < local_1cc)) break;
    *(int *)((int)param_1 + 0x14ac) = local_1cc;
    *(undefined4 *)((int)param_1 + 0x1714) = 0;
    if (local_1d0 < 2) {
      return 1;
    }
  }
  *(undefined4 *)((int)param_1 + 0x14ac) = 10;
  *(undefined4 *)((int)param_1 + 0x1714) = 0;
  return 1;
}

