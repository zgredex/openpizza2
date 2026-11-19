// rea decompile_all
// name: GameView_SetupZoomedViewport
// address: 0x4859c0
// body: available
// range: 0x4859c0-0x485a75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall GameView_SetupZoomedViewport(void *this,void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
                    /* Prepares the zoomed in-game viewport and surfaces. */
  DAT_0057c674 = param_1;
  iVar1 = Object_GetId((int)param_1);
  puVar2 = UI_CreateBitmapGadget(param_1,0x2a,0,0,DAT_00571958,DAT_0057195c,0x10);
  UI_MoveElementToIndex(param_1,0x2a,0);
  UI_BringWindowToFront(DAT_0057c5e0,iVar1);
  Array_SetField14ByKey(param_1,0x2a,1);
  DAT_00580a50 = *(undefined4 *)((int)this + 0x2da0);
  DAT_00571950 = DAT_00571958 << ((byte)DAT_00580a50 & 0x1f);
  DAT_00571954 = DAT_0057195c << ((byte)DAT_00580a50 & 0x1f);
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = Object_GetActiveValue((int)puVar2);
  Game_ResizeZoomSurfaces(DAT_0057c5cc,DAT_0057c5c8,DAT_00571950,DAT_00571954,uVar3,uVar4,uVar5);
  return;
}

