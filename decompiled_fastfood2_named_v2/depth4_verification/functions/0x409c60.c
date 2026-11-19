// rea decompile_all
// name: FUN_00409c60
// address: 0x409c60
// body: available
// range: 0x409c60-0x409d36 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00409c60(void *this,int param_1,void *param_2)

{
  void *this_00;
  int iVar1;
  
  if (*(int *)((int)param_2 + 0x128) < 1) {
    return 0;
  }
  this_00 = *(void **)((int)param_2 + 0xc4);
  do {
    iVar1 = FUN_004017f0((void *)((int)param_2 + 0x114),0,(int *)0x0);
    iVar1 = FUN_004017f0((void *)((int)this + 0x3c),iVar1,(int *)0x0);
    if ((*(int *)(iVar1 + 0x38) == 0xb) && (*(int *)(iVar1 + 0xf4) == *(int *)(param_1 + 0x16f0))) {
      Object_SetState(param_2,0xf);
      FUN_005090e0((int)param_2);
      *(undefined4 *)((int)param_2 + 0x10c) = *(undefined4 *)(iVar1 + 0x164);
      FUN_0050e4c0(param_2,0);
      iVar1 = FUN_004f0cc0(this_00,1,
                           (int)*(short *)(*(int *)(*(int *)((int)this_00 + 0x4c) + 8 +
                                                   *(int *)(iVar1 + 0x8c) * 0xc) + 0x24));
      FUN_00507d90(param_2,iVar1);
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
    FUN_004016b0((void *)((int)param_2 + 0x114),0);
  } while ((iVar1 == 0) && (0 < *(int *)((int)param_2 + 0x128)));
  return iVar1;
}

