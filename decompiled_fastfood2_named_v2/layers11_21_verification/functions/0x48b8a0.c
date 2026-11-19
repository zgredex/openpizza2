// rea decompile_all
// name: Map_ScrollToClamped
// address: 0x48b8a0
// body: available
// range: 0x48b8a0-0x48b956 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Map_ScrollToClamped(void *this,void *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Clamps and applies a map scroll position, then refreshes the minimap. */
  iVar3 = *(int *)((int)param_1 + 0x1016c) + *(int *)((int)param_1 + 0x2c);
  iVar4 = *(int *)((int)param_1 + 0x30) - *(int *)((int)param_1 + 0x10174);
  iVar2 = *(int *)((int)param_1 + 0x10170) + *(int *)((int)param_1 + 0x38) + DAT_00571954;
  iVar1 = (*(int *)((int)param_1 + 0x34) - *(int *)((int)param_1 + 0x10168)) + DAT_00571950;
  if (param_2 < iVar3) {
    param_2 = iVar3;
  }
  if (param_3 < iVar4) {
    param_3 = iVar4;
  }
  if (iVar1 <= param_2 + DAT_00571950) {
    param_2 = iVar1 - DAT_00571950;
  }
  if (iVar2 <= DAT_00571954 + param_3) {
    param_3 = iVar2 - DAT_00571954;
  }
  FUN_004ed440(param_1,param_2,param_3);
  *(undefined4 *)((int)param_1 + 0xf4) = 1;
  iVar1 = FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
  if (param_1 == *(void **)(iVar1 + 0xfa8)) {
    Map_DrawMinimap(this);
  }
  return;
}

