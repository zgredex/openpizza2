// rea decompile_all
// name: FUN_00480ab0
// address: 0x480ab0
// body: available
// range: 0x480ab0-0x480b32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00480ab0(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  iVar1 = *(int *)((int)*(void **)((int)this + 0x14e0) + 0x4c) + param_1[8] * 0xc;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
    Game_DrawMapObjectSprite(param_1,*(void **)((int)this + 0x14e0));
    FUN_004f5db0(iVar1);
    FUN_004ed330(*(void **)((int)this + 0x14e0),iVar1,-1,1);
  }
  FUN_0047c5b0(this,(int)puVar2);
  Game_ComputeCityPriceShare((int)this,(int)puVar2,(float *)&param_1);
  FUN_00477c80(this,0x15,(float)param_1,-1);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  return;
}

