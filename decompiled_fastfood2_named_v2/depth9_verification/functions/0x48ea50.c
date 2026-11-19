// rea decompile_all
// name: FUN_0048ea50
// address: 0x48ea50
// body: available
// range: 0x48ea50-0x48eae8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0048ea50(void)

{
  void *this;
  void *pvVar1;
  
  pvVar1 = DAT_0057c670;
  this = *(void **)((int)DAT_0057c670 + 0x260);
  *(undefined4 *)((int)DAT_0057c670 + 0x21c) = 0;
  *(undefined4 *)((int)pvVar1 + 0x2da8) = 1;
  pvVar1 = DAT_0057c670;
  *(undefined4 *)((int)DAT_0057c670 + 0x2c8) = *(undefined4 *)((int)DAT_0057c670 + 0x2a8);
  *(undefined4 *)((int)pvVar1 + 0x2a8) = 1;
  FUN_00482880((int)DAT_0057c670);
  FUN_00484270(DAT_0057c670);
  FUN_0052ff50(this,0x3f4,1);
  FUN_00531620(this,0x3f4,1);
  FUN_0052ff50(this,0x3fd,0);
  FUN_00531620(this,0x3fd,0);
  FUN_005316f0(this,0x3fd,0);
  return;
}

