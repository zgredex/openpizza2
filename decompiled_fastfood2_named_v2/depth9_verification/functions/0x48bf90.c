// rea decompile_all
// name: FUN_0048bf90
// address: 0x48bf90
// body: available
// range: 0x48bf90-0x48bffb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_0048bf90(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char *param_7,
            byte *param_8,undefined4 param_9)

{
  byte *pbVar1;
  byte local_400 [1024];
  
  pbVar1 = local_400;
  FUN_0054f084(local_400,param_8,&param_9);
  UI_Briefing_AddMessage
            ((void *)(param_1 + 0x304),param_2,param_3,param_4,param_5,param_6,param_7,local_400,
             pbVar1);
  return;
}

