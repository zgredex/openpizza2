// rea decompile_all
// name: FUN_00512860
// address: 0x512860
// body: available
// range: 0x512860-0x512a0e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00512860(void *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  longlong lVar14;
  int local_14;
  float local_10;
  
  iVar12 = *(int *)(param_2 + 0x18);
  iVar13 = *(int *)(param_2 + 0x14);
  uVar8 = 0x10a - iVar13;
  uVar5 = 0x112 - iVar12;
  bVar1 = iVar13 < 0x10b;
  bVar2 = iVar12 < 0x113;
  if (uVar8 == 0) {
    local_10 = 0.0;
  }
  else {
    local_10 = (float)(int)uVar5 / (float)(int)uVar8;
  }
  bVar3 = false;
  local_14 = 0;
  uVar6 = FUN_00489040(DAT_0057c670,iVar13,iVar12);
  cVar4 = (char)uVar6;
  do {
    if (cVar4 == '\0') {
      return 0;
    }
    if ((iVar13 == 0x10a) && (iVar12 == 0x112)) {
      bVar3 = true;
    }
    iVar11 = 0;
    if (0 < *(int *)((int)param_1 + 0x14)) {
      do {
        iVar7 = FUN_004017f0(param_1,iVar11,(int *)0x0);
        if ((((iVar7 != param_2) &&
             (iVar10 = *(int *)(iVar7 + 0x18) - iVar12, iVar9 = *(int *)(iVar7 + 0x14) - iVar13,
             iVar10 * iVar10 + iVar9 * iVar9 < 0xe1)) && (bVar3)) && (local_14 < 0xf)) {
          return iVar7;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(int *)((int)param_1 + 0x14));
    }
    if ((int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f)) <
        (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f))) {
      iVar13 = iVar13 + (bVar1 - 1 & 0xfffffffe) + 1;
      lVar14 = FUN_00403850(((float)iVar13 - 266.0) * local_10 + 274.0);
      iVar12 = (int)lVar14;
    }
    else {
      iVar12 = iVar12 + (bVar2 - 1 & 0xfffffffe) + 1;
      if (local_10 != 0.0) {
        lVar14 = FUN_00403850(((float)iVar12 - 274.0) / local_10 + 266.0);
        iVar13 = (int)lVar14;
      }
    }
    if (bVar3) {
      local_14 = local_14 + -1;
    }
    else {
      local_14 = local_14 + 1;
    }
    uVar6 = FUN_00489040(DAT_0057c670,iVar13,iVar12);
    cVar4 = (char)uVar6;
  } while( true );
}

