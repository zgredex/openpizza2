// rea decompile_all
// name: FUN_004e3550
// address: 0x4e3550
// body: available
// range: 0x4e3550-0x4e3602 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004e3550(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  local_8 = 0;
  iVar6 = 999999999;
  iVar1 = FUN_004d2320(param_1);
  iVar2 = FUN_004d2360(param_1);
  iVar7 = 0;
  if (*(int *)((int)this + 0x15c) < 1) {
    return 0;
  }
  do {
    iVar3 = FUN_004017f0((void *)((int)this + 0x148),iVar7,(int *)0x0);
    iVar4 = FUN_004d2320(*(int *)(iVar3 + 0x16f0));
    iVar5 = FUN_004d2360(*(int *)(iVar3 + 0x16f0));
    iVar4 = (iVar1 - iVar4) * (iVar1 - iVar4) + (iVar2 - iVar5) * (iVar2 - iVar5);
    if (iVar4 < iVar6) {
      iVar6 = iVar4;
      local_8 = iVar3;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < *(int *)((int)this + 0x15c));
  return local_8;
}

