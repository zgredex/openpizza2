// rea decompile_all
// name: FUN_00547340
// address: 0x547340
// body: available
// range: 0x547340-0x5473fd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00547340(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  int unaff_retaddr;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_c;
  int iStack_8;
  
  local_c = 0;
  if (param_2 == 1) {
    iVar1 = *(int *)((int)this + 0x1d0);
  }
  else if (param_2 == 2) {
    iVar1 = *(int *)((int)this + 0x1d4);
  }
  else {
    if (param_2 != 3) goto LAB_00547384;
    iVar1 = *(int *)((int)this + 0x1d8);
  }
  if (iVar1 == 0) {
    return;
  }
LAB_00547384:
  piVar4 = *(int **)((int)this + 8);
  puVar5 = &local_c;
  (**(code **)(*piVar4 + 0x34))(piVar4,param_1,1,puVar5);
  if (unaff_retaddr != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0xa0))(*(int **)((int)this + 8),unaff_retaddr,puVar5);
  }
  piVar2 = *(int **)((int)this + 8);
  iStack_8 = *piVar2;
  lVar3 = __ftol();
  (**(code **)(iStack_8 + 0x80))(piVar2,puVar5,(int)lVar3);
  (**(code **)(**(int **)((int)this + 8) + 100))(*(int **)((int)this + 8),piVar4);
  return;
}

