// rea decompile_all
// name: FUN_00477b80
// address: 0x477b80
// body: available
// range: 0x477b80-0x477bc9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00477b80(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x14dc) = 0;
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0x30));
  Company_InvalidateAllBranchRatings(iVar1);
  if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18658,0x23,0);
  }
  FUN_0047edc0(param_1);
  return;
}

