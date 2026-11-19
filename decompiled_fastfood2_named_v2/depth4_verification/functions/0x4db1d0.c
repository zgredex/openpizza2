// rea decompile_all
// name: Game_SelectRandomPlayerCompany
// address: 0x4db1d0
// body: available
// range: 0x4db1d0-0x4db25b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_SelectRandomPlayerCompany(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
                    /* Selects a random or specified player company. */
  iVar5 = 0;
  if (param_1 == -1) {
    uVar2 = FUN_004034d0(0,5);
  }
  else {
    iVar1 = FUN_00488be0(DAT_0057c670,param_1);
    uVar2 = FUN_004e2b70(iVar1);
  }
  piVar4 = (int *)((int)this + 200);
  iVar1 = 6;
  piVar3 = piVar4;
  do {
    if (*piVar3 == 1) {
      iVar5 = iVar5 + 1;
    }
    piVar3 = piVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (1 < iVar5) {
    iVar5 = 0;
    while (*piVar4 != 1) {
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
      if (5 < iVar5) {
        *(undefined4 *)((int)this + uVar2 * 4 + 200) = 1;
        return;
      }
    }
    *(undefined4 *)((int)this + iVar5 * 4 + 200) = 0;
  }
  *(undefined4 *)((int)this + uVar2 * 4 + 200) = 1;
  return;
}

