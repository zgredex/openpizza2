// rea decompile_all
// name: CompanyMenu_InitBranchOverview
// address: 0x4a36d0
// body: available
// range: 0x4a36d0-0x4a3716 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompanyMenu_InitBranchOverview(void *param_1)

{
                    /* Initializes the company branch-overview page. */
  DAT_00568ef0 = 0xffffffff;
  DAT_00568ef4 = 0xffffffff;
  DAT_0057d01c = 0;
  DAT_0057d014 = FUN_0048cc10(DAT_0057c670,&DAT_00568ef0,&DAT_00568ef4);
  DAT_0057d018 = 1;
  HeadquartersPanel_UpdateStaffCosts(param_1);
  return;
}

