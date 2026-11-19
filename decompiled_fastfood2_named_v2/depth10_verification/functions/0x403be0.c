// rea decompile_all
// name: FUN_00403be0
// address: 0x403be0
// body: available
// range: 0x403be0-0x403c42 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00403be0(void *this,LPVOID param_1)

{
  int iVar1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  
  iVar1 = (int)this + 0x10;
  FUN_00401320(iVar1);
  pvVar2 = *(LPVOID *)((int)this + 0xc);
  if (pvVar2 == param_1) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)param_1 + 0x14);
  }
  else {
    pvVar3 = *(LPVOID *)((int)pvVar2 + 0x14);
    while( true ) {
      if (pvVar3 == (LPVOID)0x0) {
        FUN_00401340(iVar1);
        return 0;
      }
      if (pvVar3 == param_1) break;
      pvVar2 = pvVar3;
      pvVar3 = *(LPVOID *)((int)pvVar3 + 0x14);
    }
    *(undefined4 *)((int)pvVar2 + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
  }
  FUN_0054dd78(param_1);
  FUN_00401340(iVar1);
  return 1;
}

