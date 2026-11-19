// rea decompile_all
// name: Game_HandleMapClickCloseSubmenu
// address: 0x4c3000
// body: available
// range: 0x4c3000-0x4c306f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Game_HandleMapClickCloseSubmenu(undefined4 *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  
                    /* Handles map clicks that close a building submenu. */
  this = *(void **)(DAT_0057c670 + 0x9c);
  iVar1 = *(int *)((int)this + 0x14e0);
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x74),param_1[1],(int *)0x0);
  if (((*(int *)(iVar2 + 8) == 1) || (*(int *)(iVar2 + 8) == 2)) &&
     (iVar2 = FUN_00489ea0(this,(int)param_1), iVar2 != 0)) {
    return;
  }
  *(undefined4 *)(DAT_0057c670 + 0x344) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  MapObject_RemoveFromMap(this,param_1);
  *(undefined4 *)(iVar1 + 0xf4) = 1;
  return;
}

