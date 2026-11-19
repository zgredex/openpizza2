// rea decompile_all
// name: UI_SliderStepValue
// address: 0x52a160
// body: available
// range: 0x52a160-0x52a256 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_SliderStepValue(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  
                    /* Depth-3 proposal batch 4. */
  uVar2 = *(uint *)((int)this + 0xd0);
  if (0x7fffffff < uVar2) {
    lVar3 = __ftol();
    uVar2 = (uint)lVar3;
  }
  iVar1 = *(int *)((int)this + 0x8c);
  if (param_1 != 0) {
    uVar2 = -uVar2;
  }
  FUN_0052a3a0(this,iVar1 + uVar2,0);
  if (*(int *)((int)this + 0x8c) != iVar1) {
    FUN_005301c0(*(void **)((int)this + 8),*(int *)((int)this + 4),0x1a,iVar1);
    if (*(int *)((int)this + 0xc4) != 0) {
      FUN_005301c0(*(void **)((int)this + 8),*(int *)((int)this + 4),0x19,*(int *)((int)this + 0x8c)
                  );
    }
    FUN_005301c0(*(void **)((int)this + 8),*(int *)((int)this + 4),0x18,*(int *)((int)this + 0x8c));
    FUN_005321f0(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
  }
  return;
}

