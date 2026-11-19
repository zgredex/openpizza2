// rea decompile_all
// name: Game_GetRatingPercent
// address: 0x48c7b0
// body: available
// range: 0x48c7b0-0x48c852 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_GetRatingPercent(void *this,int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  int local_20 [8];
  
  local_20[0] = 0x14;
  local_20[1] = 0x1e;
  local_20[2] = 0x28;
  local_20[3] = 0x32;
  local_20[4] = 0x5a;
  local_20[5] = 0x5f;
  local_20[6] = 0x50;
  local_20[7] = 0x46;
  if (local_20[param_1] <= param_2) {
    return 100;
  }
  IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
  lVar2 = __ftol();
  iVar1 = 100 - (int)lVar2;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}

