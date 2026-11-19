// rea decompile_all
// name: Map_FindEdgeDot
// address: 0x500470
// body: available
// range: 0x500470-0x500578 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl Map_FindEdgeDot(int param_1,int *param_2,int *param_3,uint *param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
                    /* Depth-1 proposal batch 3/4. */
  bVar1 = false;
  if ((char)param_5 == '\0') {
    uVar2 = _rand();
    *param_4 = uVar2 & 3;
  }
  else {
    *param_4 = 0;
  }
  uVar2 = *param_4;
  if (uVar2 == 0) {
    param_5 = 0;
    iVar4 = param_1 + 0x28;
    do {
      iVar3 = 0;
      do {
        if (*(char *)(iVar4 + iVar3) == '.') {
          bVar1 = true;
          goto LAB_005004ce;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x50);
      param_5 = param_5 + 1;
      iVar4 = iVar4 + 0x50;
    } while (param_5 < 0x50);
  }
  else {
    iVar3 = param_5;
  }
LAB_005004ce:
  if (uVar2 == 1) {
    param_5 = 0x4f;
    iVar4 = param_1 + 0x18d8;
    do {
      iVar3 = 0x4f;
      do {
        if (*(char *)(iVar4 + iVar3) == '.') {
          bVar1 = true;
          goto LAB_005004fc;
        }
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
      if (bVar1) break;
      param_5 = param_5 - 1;
      iVar4 = iVar4 + -0x50;
    } while (-1 < param_5);
  }
LAB_005004fc:
  if (uVar2 == 2) {
    iVar3 = 0;
    pcVar6 = (char *)(param_1 + 0x18d8);
    do {
      param_5 = 0x4f;
      pcVar5 = pcVar6;
      do {
        if (*pcVar5 == '.') {
          bVar1 = true;
          goto LAB_0050052c;
        }
        param_5 = param_5 - 1;
        pcVar5 = pcVar5 + -0x50;
      } while (-1 < param_5);
      if (bVar1) break;
      iVar3 = iVar3 + 1;
      pcVar6 = pcVar6 + 1;
    } while (iVar3 < 0x50);
  }
LAB_0050052c:
  if (uVar2 == 3) {
    iVar3 = 0x4f;
    pcVar6 = (char *)(param_1 + 0x1927);
    do {
      param_5 = 0x4f;
      pcVar5 = pcVar6;
      do {
        if (*pcVar5 == '.') goto LAB_00500567;
        param_5 = param_5 - 1;
        pcVar5 = pcVar5 + -0x50;
      } while (-1 < param_5);
      if (bVar1) goto LAB_00500567;
      iVar3 = iVar3 + -1;
      pcVar6 = pcVar6 + -1;
    } while (-1 < iVar3);
  }
  else if (bVar1) {
LAB_00500567:
    *param_2 = param_5;
    *param_3 = iVar3;
    return CONCAT31((int3)((uint)param_3 >> 8),1);
  }
  return param_5 & 0xffffff00;
}

