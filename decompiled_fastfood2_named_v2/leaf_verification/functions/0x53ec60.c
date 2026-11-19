// rea decompile_all
// name: Sound_DecodeADPCM
// address: 0x53ec60
// body: available
// range: 0x53ec60-0x53ed6e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Sound_DecodeADPCM(char *param_1,short *param_2,int param_3,short *param_4)

{
  short sVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int local_4;
  
                    /* Leaf reversal proposal batch 4. */
  psVar8 = param_2;
  iVar6 = (int)(char)param_4[1];
  param_2 = (short *)param_1;
  bVar2 = false;
  iVar7 = (int)*param_4;
  sVar1 = (&DAT_00574a64)[iVar6];
  local_4 = param_3 * 2;
  param_1 = (char *)0x0;
  if (local_4 == 0) {
    *param_4 = *param_4;
    *(char *)(param_4 + 1) = (char)param_4[1];
    return;
  }
  do {
    iVar5 = (int)sVar1;
    if (bVar2) {
      pcVar3 = (char *)((int)param_1 >> 4);
    }
    else {
      pcVar3 = (char *)(int)(char)*param_2;
      param_2 = (short *)((int)param_2 + 1);
      param_1 = pcVar3;
    }
    bVar2 = !bVar2;
    iVar6 = iVar6 + *(int *)(&DAT_00574a24 + ((uint)pcVar3 & 0xf) * 4);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    else if (0x58 < iVar6) {
      iVar6 = 0x58;
    }
    iVar4 = 0;
    if (((uint)pcVar3 & 4) != 0) {
      iVar4 = iVar5;
    }
    if (((uint)pcVar3 & 2) != 0) {
      iVar4 = iVar4 + (iVar5 >> 1);
    }
    if (((uint)pcVar3 & 1) != 0) {
      iVar4 = iVar4 + (iVar5 >> 2);
    }
    iVar4 = iVar4 + (iVar5 >> 3);
    if (((uint)pcVar3 & 8) != 0) {
      iVar4 = -iVar4;
    }
    iVar7 = iVar7 + iVar4;
    if (iVar7 < 0x8000) {
      if (iVar7 < -0x8000) {
        iVar7 = -0x8000;
      }
    }
    else {
      iVar7 = 0x7fff;
    }
    *psVar8 = (short)iVar7;
    sVar1 = (&DAT_00574a64)[iVar6];
    psVar8 = psVar8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  *param_4 = (short)iVar7;
  *(char *)(param_4 + 1) = (char)iVar6;
  return;
}

