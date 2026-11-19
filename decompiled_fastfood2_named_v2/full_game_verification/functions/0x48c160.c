// rea decompile_all
// name: Game_SelectPlayer
// address: 0x48c160
// body: available
// range: 0x48c160-0x48c1bb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_SelectPlayer(void *this,int param_1)

{
  int iVar1;
  
  if (param_1 == -1) {
    param_1 = *(int *)((int)this + 0x288);
  }
  iVar1 = Game_GetPlayerBySlot(this,param_1);
  if ((iVar1 != 0) && (param_1 != *(int *)((int)this + 0x2ec))) {
    *(int *)((int)this + 0x2ec) = param_1;
    *(undefined4 *)((int)this + 0x2f0) = *(undefined4 *)(iVar1 + 0x4c);
    *(undefined4 *)((int)this + 700) = *(undefined4 *)((int)this + 0x29c);
    *(undefined4 *)((int)this + 0x29c) = 1;
    Game_SetViewMode(this,1,0);
  }
  return;
}

