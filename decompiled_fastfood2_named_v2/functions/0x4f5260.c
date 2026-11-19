// rea decompile_all
// name: FUN_004f5260
// address: 0x4f5260
// body: available
// range: 0x4f5260-0x4f530e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_004f5260(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  int extraout_ECX;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined1 unaff_retaddr;
  
  FUN_0054f110(unaff_retaddr);
  iVar1 = *(int *)(extraout_ECX + 0x20);
  iVar9 = 0;
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      iVar6 = *(int *)(extraout_ECX + 0x1c);
      iVar4 = iVar3;
      if (0 < iVar6) {
        iVar4 = iVar3 + iVar6;
        piVar5 = (int *)(*(int *)(extraout_ECX + 0x4c) + 8 + iVar3 * 0xc);
        piVar7 = (int *)(&param_2 + iVar9 * 4);
        do {
          iVar3 = *piVar5;
          piVar8 = piVar7;
          if ((((iVar3 != 0) && (*(int *)(iVar3 + 4) == 0x355)) && (*(short *)(iVar3 + 0x24) != -1))
             && (*(int *)(iVar3 + 0x28) != 0)) {
            iVar9 = iVar9 + 1;
            piVar8 = piVar7 + 1;
            *piVar7 = *(int *)(extraout_ECX + 0x9c) + *(short *)(iVar3 + 0x24) * 0x28;
          }
          piVar5 = piVar5 + 3;
          iVar6 = iVar6 + -1;
          piVar7 = piVar8;
        } while (iVar6 != 0);
      }
      iVar1 = iVar1 + -1;
      iVar3 = iVar4;
    } while (iVar1 != 0);
    if (0 < iVar9) {
      uVar2 = Random_Range(0,iVar9 - 1);
      return *(undefined4 *)(&param_2 + uVar2 * 4);
    }
  }
  return 0;
}

