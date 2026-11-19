// rea decompile_all
// name: FUN_0047fbd0
// address: 0x47fbd0
// body: available
// range: 0x47fbd0-0x47fd1d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined1 __fastcall FUN_0047fbd0(void *param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_EDX;
  uint uVar6;
  undefined1 local_1;
  
  uVar2 = *(uint *)((int)param_1 + 0x14b4);
  local_1 = 0;
  iVar3 = FUN_004787f0(param_1,5);
  iVar4 = Branch_ComputeBuildingRating(param_1,extraout_EDX,5);
  iVar5 = FUN_00478320(param_1,5);
  iVar3 = (iVar5 + iVar3 + iVar4) / 3;
  iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)param_1 + 0x34),(int *)0x0);
  iVar4 = 0x3c - *(int *)(iVar4 + 0xcc8 + *(int *)((int)param_1 + 0x30) * 4);
  iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
  uVar6 = (uint)(iVar4 + 0x4b <= iVar3);
  if (iVar4 + 0x4e <= iVar3) {
    uVar6 = uVar6 + 1;
  }
  if (iVar4 + 0x51 <= iVar3) {
    uVar6 = uVar6 + 1;
  }
  if (iVar4 + 0x54 <= iVar3) {
    uVar6 = uVar6 + 1;
  }
  if (iVar4 + 0x57 <= iVar3) {
    uVar6 = uVar6 + 1;
  }
  pvVar1 = (void *)(DAT_0057c670 + 0x304);
  if (uVar6 != uVar2) {
    if ((int)uVar6 < (int)uVar2) {
      *(uint *)((int)param_1 + 0x14b4) = uVar2 - 1;
      iVar3 = FUN_00482820(DAT_0057c670);
      if (*(int *)((int)param_1 + 0x3c) == iVar3) {
        FUN_0054a980(pvVar1,0x14,0,4,1,*(int *)((int)param_1 + 0x16f0),DAT_005819e0,
                     (byte *)DAT_005819e0,(int)param_1 + 4);
        return 0;
      }
    }
    else {
      if (uVar2 == 5) {
        return 0;
      }
      local_1 = 1;
      *(uint *)((int)param_1 + 0x14b4) = uVar2 + 1;
      iVar3 = FUN_00482820(DAT_0057c670);
      if (*(int *)((int)param_1 + 0x3c) == iVar3) {
        FUN_0054a980(pvVar1,0x13,0,4,1,*(int *)((int)param_1 + 0x16f0),DAT_0058262c,
                     (byte *)DAT_0058262c,(int)param_1 + 4);
      }
    }
  }
  return local_1;
}

