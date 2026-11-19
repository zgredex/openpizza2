// rea decompile_all
// name: FUN_004fe570
// address: 0x4fe570
// body: available
// range: 0x4fe570-0x4fe5ec inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fe570(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_00500070(this,param_1);
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  iVar2 = Game_GetPlayerFieldC20(iVar1);
  if (iVar2 < 1) {
    return 1;
  }
  iVar2 = *(int *)(iVar1 + 0x140);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)FUN_004017f0((void *)(iVar1 + 300),iVar4,(int *)0x0);
      FUN_004fe5f0(this,param_1,puVar3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_004fe870(this,param_1);
  return 1;
}

