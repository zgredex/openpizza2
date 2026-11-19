// rea decompile_all
// name: FUN_0050e730
// address: 0x50e730
// body: available
// range: 0x50e730-0x50e79b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0050e730(void *this,void *param_1,int param_2)

{
  void *this_00;
  int iVar1;
  
  if (*(void **)((int)this + 0xfc) != (void *)0x0) {
    FUN_004d2960(*(void **)((int)this + 0xfc),this,0);
  }
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this_00 = *(void **)(iVar1 + 0xfa8);
  FUN_0050e720(this,param_1);
  if (param_2 != 0) {
    FUN_004d28f0(param_1,this);
  }
  iVar1 = FUN_004f0cc0(this_00,1,*(int *)((int)param_1 + 0x54));
  UI_SetChildTracking(this,0,iVar1);
  return;
}

