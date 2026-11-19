// rea decompile_all
// name: FUN_00482790
// address: 0x482790
// body: available
// range: 0x482790-0x4827d5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00482790(void *this,void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004014b0((void *)((int)this + 0x3c),param_1);
  *(int *)((int)param_1 + 0x164) = iVar1;
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0xe:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x22:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
    break;
  default:
    Object_Activate(param_1,*(void **)((int)param_1 + 0xcc));
  }
  return iVar1;
}

