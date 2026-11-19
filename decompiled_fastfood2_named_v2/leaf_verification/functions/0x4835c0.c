// rea decompile_all
// name: FUN_004835c0
// address: 0x4835c0
// body: available
// range: 0x4835c0-0x483737 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_004835c0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  void *this_00;
  int iVar1;
  int *piVar2;
  int iVar3;
  void *local_4;
  
  if (*(int *)((int)this + 0x268) == 0) {
    local_4 = this;
    this_00 = FUN_0046d910((int *)&local_4);
    *(undefined4 *)((int)this + 0x274) = param_1;
    *(undefined4 *)((int)this + 0x270) = param_6;
    *(undefined4 *)((int)this + 0x27c) = param_4;
    *(void **)((int)this + 0x268) = this_00;
    *(undefined4 *)((int)this + 0x278) = 0xffffffff;
    *(undefined4 *)((int)this + 0x284) = param_5;
    *(undefined4 *)((int)this + 0x280) = 0;
    FUN_0052f9b0(this_00,0x3e9,param_2);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x3ea,param_3);
    iVar3 = *(int *)(*(int *)((int)this + 0x27c) + 0x14);
    if (iVar3 < 6) {
      iVar3 = 5 - iVar3;
      FUN_00531740(*(void **)((int)this + 0x268),1000);
      if (0 < iVar3) {
        iVar1 = 0x3f4;
        piVar2 = &DAT_00567e84;
        do {
          FUN_00531740(*(void **)((int)this + 0x268),iVar1);
          FUN_00531740(*(void **)((int)this + 0x268),*piVar2);
          iVar1 = iVar1 + -1;
          piVar2 = piVar2 + -1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else {
      *(int *)((int)this + 0x280) = *(int *)((int)this + 0x284);
      if (*(int *)(*(int *)((int)this + 0x27c) + 0x14) < *(int *)((int)this + 0x284) + 5) {
        *(int *)((int)this + 0x280) = iVar3 + -5;
      }
      FUN_0052fd00(*(void **)((int)this + 0x268),1000,0,(iVar3 + -5) * 100,1);
      FUN_0052fd70(*(void **)((int)this + 0x268),1000,*(int *)((int)this + 0x280) * 100,0);
      FUN_0052fce0(*(void **)((int)this + 0x268),1000,1);
    }
    FUN_00483530(this,*(int *)((int)this + 0x280));
    FUN_00523d60(DAT_0057c5e0,(int)local_4);
  }
  return;
}

