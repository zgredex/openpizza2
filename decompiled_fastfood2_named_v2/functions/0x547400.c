// rea decompile_all
// name: FUN_00547400
// address: 0x547400
// body: available
// range: 0x547400-0x5474ac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_00547400(void *this,undefined4 param_1,int param_2)

{
  int unaff_EDI;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_4;
  
  iVar1 = 0;
  local_4 = 0;
  if (param_2 == 1) {
    iVar1 = *(int *)((int)this + 0x1d0);
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
  }
  else if (param_2 == 2) {
    iVar1 = *(int *)((int)this + 0x1d4);
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
  }
  else if ((param_2 == 3) && (iVar1 = *(int *)((int)this + 0x1d8), iVar1 == 0)) {
    return (undefined4 *)0x0;
  }
  puVar2 = &local_4;
  uVar3 = 1;
  (**(code **)(**(int **)((int)this + 8) + 0x34))(*(int **)((int)this + 8),param_1,1);
  (**(code **)(**(int **)((int)this + 8) + 0x80))(*(int **)((int)this + 8),uVar3,iVar1);
  if (unaff_EDI != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0x78))(*(int **)((int)this + 8),iVar1,unaff_EDI);
  }
  (**(code **)(**(int **)((int)this + 8) + 0x60))(*(int **)((int)this + 8),iVar1);
  return puVar2;
}

