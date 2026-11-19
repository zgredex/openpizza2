// rea decompile_all
// name: FUN_00478eb0
// address: 0x478eb0
// body: available
// range: 0x478eb0-0x478f57 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00478eb0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  iVar3 = 8;
  piVar2 = (int *)(param_1 + 0x17dc);
  piVar4 = (int *)(iVar1 + 0x220);
  do {
    iVar1 = piVar4[-8] * *(int *)(param_1 + 0x183c);
    *piVar2 = iVar1;
    iVar1 = iVar1 + *(int *)(param_1 + 0x1844) * *piVar4;
    *piVar2 = iVar1;
    iVar1 = iVar1 + piVar4[8] * *(int *)(param_1 + 0x1840);
    *piVar2 = iVar1;
    iVar1 = (piVar4[0x10] * *(int *)(param_1 + 0x1848) + iVar1) / 100;
    *piVar2 = iVar1 * 3;
    iVar3 = iVar3 + -1;
    *piVar2 = (iVar1 * 9 + *(int *)(param_1 + 0x1a04) + *(int *)(param_1 + 0x19fc)) / 5;
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 != 0);
  return;
}

