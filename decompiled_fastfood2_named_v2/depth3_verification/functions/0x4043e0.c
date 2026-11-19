// rea decompile_all
// name: FUN_004043e0
// address: 0x4043e0
// body: available
// range: 0x4043e0-0x404415 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_004043e0(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5,
            undefined4 param_6,char *param_7,undefined4 param_8,int param_9,undefined4 param_10,
            char *param_11,undefined4 param_12,int param_13,undefined4 param_14,char *param_15,
            undefined4 param_16,int param_17,undefined4 param_18,char *param_19,undefined4 param_20,
            int param_21,undefined4 param_22,char *param_23,undefined4 param_24,int param_25)

{
  undefined4 *puVar1;
  char *unaff_ESI;
  undefined4 unaff_retaddr;
  
  FUN_00403580();
  FUN_004052c0(unaff_ESI,unaff_retaddr,param_1,param_2,param_3,param_4,param_5,param_6,param_7,
               param_8,param_9,param_10,param_11,param_12,param_13,param_14,param_15,param_16,
               param_17,param_18,param_19,param_20,param_21,param_22,param_23,param_24,param_25);
  FUN_00404760();
  puVar1 = DAT_0057c5b0;
  DAT_0057c480 = 1;
  if (DAT_0057c5b0 != (undefined4 *)0x0) {
    FUN_0054c4f0(DAT_0057c5b0);
    FUN_0054dd78(puVar1);
  }
  return;
}

