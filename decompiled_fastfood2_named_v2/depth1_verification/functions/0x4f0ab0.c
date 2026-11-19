// rea decompile_all
// name: Map_LinkCells
// address: 0x4f0ab0
// body: available
// range: 0x4f0ab0-0x4f0bc1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Map_LinkCells(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar3 = FUN_004f0cc0(this,param_1,param_2);
  iVar4 = FUN_004f0cc0(this,param_1,param_3);
  iVar5 = *(int *)(iVar3 + 0xc);
  iVar1 = *(int *)(iVar4 + 0xc);
  if (iVar5 == iVar1) {
    dVar2 = 0.0;
  }
  else {
    dVar2 = (double)(*(int *)(iVar3 + 0x10) - *(int *)(iVar4 + 0x10)) / (double)(iVar5 - iVar1);
    if ((dVar2 == 0.5) || (dVar2 == -0.5)) goto LAB_004f0b47;
  }
  if ((iVar5 != iVar1) && (dVar2 != 0.0)) {
    FUN_0048e0a0();
    return;
  }
LAB_004f0b47:
  psVar7 = (short *)(iVar3 + 0x14);
  iVar5 = 0;
  psVar6 = psVar7;
  do {
    if (*psVar6 == param_3) {
      return;
    }
    iVar5 = iVar5 + 1;
    psVar6 = psVar6 + 1;
  } while (iVar5 < 8);
  iVar5 = 0;
  do {
    if (*psVar7 == -1) {
      *(short *)(iVar3 + 0x14 + iVar5 * 2) = (short)param_3;
      break;
    }
    iVar5 = iVar5 + 1;
    psVar7 = psVar7 + 1;
  } while (iVar5 < 8);
  if (param_1 == 1) {
    iVar5 = 0;
    psVar7 = (short *)(iVar4 + 0x14);
    psVar6 = psVar7;
    do {
      if (*psVar6 == param_2) {
        return;
      }
      iVar5 = iVar5 + 1;
      psVar6 = psVar6 + 1;
    } while (iVar5 < 8);
    iVar5 = 0;
    while (*psVar7 != -1) {
      iVar5 = iVar5 + 1;
      psVar7 = psVar7 + 1;
      if (7 < iVar5) {
        return;
      }
    }
    *(short *)(iVar4 + 0x14 + iVar5 * 2) = (short)param_2;
  }
  return;
}

