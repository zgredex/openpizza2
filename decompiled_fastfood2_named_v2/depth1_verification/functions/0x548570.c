// rea decompile_all
// name: Sound_ApplyVolumePreset
// address: 0x548570
// body: available
// range: 0x548570-0x54867e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_ApplyVolumePreset(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
                    /* Depth-1 proposal batch 3/4. */
  if (param_1 == 0) {
    if (*(float *)((int)this + 0x170) == 1.0) {
      return;
    }
    *(undefined4 *)((int)this + 0x170) = 0x3f800000;
  }
  else if (param_1 == 1) {
    if (*(float *)((int)this + 0x170) == 0.7) {
      return;
    }
    *(undefined4 *)((int)this + 0x170) = 0x3f000000;
  }
  else {
    if (param_1 != 2) {
      return;
    }
    if (*(float *)((int)this + 0x170) == 0.4) {
      return;
    }
    *(undefined4 *)((int)this + 0x170) = 0x3e99999a;
  }
  if (((*(char *)((int)this + 0x169) != '\0') && (*(char *)((int)this + 0xfc) != '\0')) &&
     (*(int *)((int)this + 0x1d0) != 0)) {
    lVar3 = __ftol();
    (**(code **)(**(int **)((int)this + 8) + 0x7c))
              (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x84),(int)lVar3);
    piVar1 = *(int **)((int)this + 8);
    iVar2 = *piVar1;
    lVar3 = __ftol();
    (**(code **)(iVar2 + 0xa4))(piVar1,*(undefined4 *)((int)this + 0xf8),(int)lVar3);
  }
  return;
}

