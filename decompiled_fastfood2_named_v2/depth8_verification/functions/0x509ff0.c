// rea decompile_all
// name: FUN_00509ff0
// address: 0x509ff0
// body: available
// range: 0x509ff0-0x50a07d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00509ff0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  if (*(int *)(param_1 + 200) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 200) + 0x20);
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0xc4) + 0x4c) + *(int *)(iVar2 + 8) * 0xc;
  uVar1 = FUN_004034d0(0x10,0x1c);
  iVar3 = 0;
  local_4 = iVar2;
  if (0 < (int)uVar1) {
    do {
      iVar2 = FUN_004f3e10(*(void **)(param_1 + 0xc4),local_4,2);
      if (((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0)) ||
         (*(int *)(*(int *)(iVar2 + 8) + 0x28) == 0)) {
        iVar2 = local_4;
        break;
      }
      iVar3 = iVar3 + 1;
      local_4 = iVar2;
    } while (iVar3 < (int)uVar1);
  }
  FUN_004f0cc0(*(void **)(param_1 + 0xc4),1,(int)*(short *)(*(int *)(iVar2 + 8) + 0x24));
  return;
}

