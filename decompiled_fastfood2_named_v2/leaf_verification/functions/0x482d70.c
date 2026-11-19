// rea decompile_all
// name: FUN_00482d70
// address: 0x482d70
// body: available
// range: 0x482d70-0x482f0c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00482d70(char param_1)

{
  int *piVar1;
  uint uVar2;
  void *this;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  undefined1 local_res0;
  undefined4 in_stack_00002008;
  char *in_stack_0000200c;
  undefined4 in_stack_00002010;
  undefined4 in_stack_00002014;
  
  local_res0 = (undefined1)_local_res0;
  __chkstk(local_res0);
  if (*(int *)(extraout_ECX + 0x268) == 0) {
    piVar1 = FUN_00402290(DAT_0057c5d8,in_stack_0000200c,1);
    uVar2 = FUN_00402750(DAT_0057c5d8,&param_1,0x2000,(int)piVar1);
    (&param_1)[uVar2] = '\0';
    FUN_00402990(DAT_0057c5d8,(int)piVar1);
    this = FUN_0046cad0((int *)&local_res0);
    *(void **)(extraout_ECX + 0x268) = this;
    FUN_0052f9b0(this,0x42b,in_stack_00002010);
    FUN_0052f9b0(*(void **)(extraout_ECX + 0x268),0x42c,&param_1);
    iVar3 = FUN_0052f950(*(void **)(extraout_ECX + 0x268),0x42c);
    iVar4 = FUN_0052f970(*(void **)(extraout_ECX + 0x268),0x42c);
    if (iVar4 < iVar3) {
      FUN_005316b0(*(void **)(extraout_ECX + 0x268),0x1f42);
      FUN_0052fd00(*(void **)(extraout_ECX + 0x268),0x1f42,0,iVar3 - iVar4,1);
      FUN_0052fd70(*(void **)(extraout_ECX + 0x268),0x1f42,0,0);
      FUN_0052fce0(*(void **)(extraout_ECX + 0x268),0x1f42,1);
    }
    else {
      FUN_00531740(*(void **)(extraout_ECX + 0x268),0x1f42);
      FUN_0052f990(*(void **)(extraout_ECX + 0x268),0x42c,0);
    }
    *(undefined4 *)(extraout_ECX + 0x270) = in_stack_00002014;
    *(undefined4 *)(extraout_ECX + 0x274) = in_stack_00002008;
    *(undefined4 *)(extraout_ECX + 0x278) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x27c) = 0;
    *(undefined4 *)(extraout_ECX + 0x280) = 0;
    FUN_00532a30(*(void **)(extraout_ECX + 0x268),0x42e,0xd);
    FUN_00532a30(*(void **)(extraout_ECX + 0x268),0x42e,0x1b);
    FUN_00523d60(DAT_0057c5e0,_local_res0);
  }
  return;
}

