// rea decompile_all
// name: FUN_00483210
// address: 0x483210
// body: available
// range: 0x483210-0x4833aa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00483210(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
            int param_5,undefined4 param_6)

{
  void *this_00;
  int iVar1;
  int iVar2;
  void *local_4;
  
  if (*(int *)((int)this + 0x268) == 0) {
    local_4 = this;
    this_00 = FUN_0046cc70((int *)&local_4);
    *(undefined4 *)((int)this + 0x270) = param_6;
    *(undefined4 *)((int)this + 0x274) = param_1;
    *(int *)((int)this + 0x28c) = param_5;
    *(void **)((int)this + 0x268) = this_00;
    *(undefined4 *)((int)this + 0x278) = 0xffffffff;
    *(int *)((int)this + 0x27c) = param_4;
    *(int *)((int)this + 0x284) = param_5 + -6;
    if (*(int *)(param_4 + 0x14) < param_5 + 7) {
      *(int *)((int)this + 0x284) = *(int *)(param_4 + 0x14) + -0xd;
    }
    if (*(int *)((int)this + 0x284) < 0) {
      *(undefined4 *)((int)this + 0x284) = 0;
    }
    *(undefined4 *)((int)this + 0x280) = *(undefined4 *)((int)this + 0x284);
    FUN_0052f9b0(this_00,0x440,param_2);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x441,param_3);
    iVar1 = *(int *)(*(int *)((int)this + 0x27c) + 0x14);
    if (iVar1 < 0xe) {
      FUN_00531740(*(void **)((int)this + 0x268),0x42d);
      iVar2 = 0x450;
      iVar1 = 0x450 - (0xd - iVar1);
      if (iVar1 < 0x450) {
        do {
          FUN_00531740(*(void **)((int)this + 0x268),iVar2);
          FUN_00531740(*(void **)((int)this + 0x268),iVar2 + 0xd);
          iVar2 = iVar2 + -1;
        } while (iVar1 < iVar2);
      }
    }
    else {
      FUN_0052fd00(*(void **)((int)this + 0x268),0x42d,0,(iVar1 * 5 + -0x41) * 0x14,1);
      FUN_0052fd70(*(void **)((int)this + 0x268),0x42d,*(int *)((int)this + 0x280) * 100,0);
      FUN_0052fce0(*(void **)((int)this + 0x268),0x42d,1);
    }
    FUN_00483150(this,*(int *)((int)this + 0x280));
    FUN_00532a30(*(void **)((int)this + 0x268),0x443,0x1b);
    FUN_00523d60(DAT_0057c5e0,(int)local_4);
  }
  return;
}

