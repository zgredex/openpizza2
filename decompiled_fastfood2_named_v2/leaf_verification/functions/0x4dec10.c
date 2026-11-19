// rea decompile_all
// name: FUN_004dec10
// address: 0x4dec10
// body: available
// range: 0x4dec10-0x4dece7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dec10(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *local_4;
  
  local_4 = param_1;
  local_4 = operator_new(0x1a0);
  if (*(int *)(*(int *)(DAT_0057c670 + 0x90) + 300 + param_1[0x13] * 0x168) != 0x18) {
    FUN_004decf0(param_1,(int *)&local_4);
    FUN_004defd0(param_1,(int *)&local_4);
    FUN_004df200(param_1,(int *)&local_4);
    FUN_004df480(param_1,(int *)&local_4);
    FUN_004df780(param_1,(int *)&local_4);
    FUN_004dfaf0(param_1,(int *)&local_4);
    FUN_004dfcd0(param_1,(int *)&local_4);
    FUN_004dfe40(param_1,(int *)&local_4);
    Company_ComputeTotals((int *)&local_4);
    FUN_004014b0(param_1 + 0x67,local_4);
    return;
  }
  puVar2 = local_4;
  for (iVar1 = 0x68; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_004014b0(param_1 + 0x67,local_4);
  return;
}

