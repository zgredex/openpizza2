// rea decompile_all
// name: FUN_00482c40
// address: 0x482c40
// body: available
// range: 0x482c40-0x482d6e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_00482c40(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,char param_7)

{
  void *pvVar1;
  int iVar2;
  void *local_4;
  
  iVar2 = param_6;
  if (*(int *)((int)this + 0x268) == 0) {
    DAT_00567da0 = param_6;
    local_4 = this;
    pvVar1 = FUN_0046c690(&param_6);
    *(void **)((int)this + 0x268) = pvVar1;
    *(undefined4 *)((int)this + 0x274) = param_1;
    *(undefined4 *)((int)this + 0x278) = param_4;
    if (param_7 == '\0') {
      *(undefined4 *)((int)this + 0x2e14) = 0xffffffff;
    }
    else {
      *(undefined4 *)((int)this + 0x2e14) = 0;
    }
    *(undefined4 *)((int)this + 0x270) = param_5;
    *(undefined4 *)((int)this + 0x27c) = 0;
    *(undefined4 *)((int)this + 0x280) = 1;
    *(int *)((int)this + 0x284) = iVar2;
    if (iVar2 != -1) {
      iVar2 = FUN_0054b110((void *)((int)this + 0x304),iVar2,(int *)&local_4);
      if (*(int *)(iVar2 + 0x24) != -1) {
        FUN_0052f830(*(void **)((int)this + 0x268),0x431,DAT_00581650);
      }
    }
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x42d,param_2);
    FUN_0052f9b0(*(void **)((int)this + 0x268),0x42f,param_3);
    FUN_0052fa20(*(void **)((int)this + 0x268),0x42f,2);
    UI_AddUniquePair(*(void **)((int)this + 0x268),0x431,0xd);
    UI_AddUniquePair(*(void **)((int)this + 0x268),0x430,0x1b);
    FUN_00523d60(DAT_0057c5e0,param_6);
  }
  return;
}

