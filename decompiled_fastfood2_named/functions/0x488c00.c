// rea decompile_all
// name: FUN_00488c00
// address: 0x488c00
// body: available
// range: 0x488c00-0x488cb6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00488c00(void *param_1)

{
  if (*(int *)((int)param_1 + 0x1508) == 0) {
    CS_Enter(*(int *)((int)param_1 + 0x23c));
    *(undefined4 *)((int)param_1 + 0x254) = 1;
    CS_Leave(*(int *)((int)param_1 + 0x23c));
    CS_Enter(*(int *)((int)param_1 + 0x240));
    FUN_0040b900(param_1,DAT_0057c68c);
    *(int *)((int)param_1 + 0x340) = *(int *)((int)param_1 + 0x340) + 1;
    if (DAT_0057c68c == 0) {
      FUN_0040bab0((int)param_1);
    }
    FUN_00548780(DAT_0057ba0c,(uint)*(byte *)(*(int *)((int)param_1 + 0x94) + 7),
                 (uint)*(byte *)(*(int *)((int)param_1 + 0x94) + 6) * 5);
    CS_Leave(*(int *)((int)param_1 + 0x240));
    *(undefined4 *)((int)param_1 + 0x254) = 0;
    DAT_0057c68c = DAT_0057c68c + 1;
    if (4 < DAT_0057c68c) {
      DAT_0057c68c = 0;
    }
  }
  return;
}

