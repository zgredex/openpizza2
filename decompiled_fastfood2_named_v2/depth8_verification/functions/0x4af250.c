// rea decompile_all
// name: FUN_004af250
// address: 0x4af250
// body: available
// range: 0x4af250-0x4af2eb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004af250(void *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(&DAT_00569f94 + param_2 * 0xc);
  iVar3 = 0x42c;
  param_2 = param_2 * 3;
  do {
    FUN_0052ff50(param_1,iVar3,(uint)(param_2 == DAT_0057d654));
    if (param_2 < 0x38) {
      FUN_005316f0(param_1,iVar3,1);
      FUN_005316f0(param_1,iVar3 + 0xb74,1);
      FUN_00531b70(param_1,iVar3 + 0xb74,*puVar2);
    }
    else {
      FUN_005316f0(param_1,iVar3,0);
      FUN_005316f0(param_1,iVar3 + 0xb74,0);
    }
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
    iVar1 = iVar3 + -0x42b;
    iVar3 = iVar3 + 1;
  } while (iVar1 < 0x12);
  return;
}

