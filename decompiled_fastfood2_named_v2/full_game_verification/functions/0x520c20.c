// rea decompile_all
// name: UI_MoveChildToPosition
// address: 0x520c20
// body: available
// range: 0x520c20-0x520ccb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_MoveChildToPosition(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)((int)this + 0x38) != param_1) || (*(int *)((int)this + 0x3c) != param_2)) {
    piVar1 = (int *)((int)this + 0x28);
    UI_ClipRect(*(void **)((int)this + 8),piVar1,1);
    iVar4 = *piVar1;
    iVar2 = *(int *)((int)this + 0x2c);
    iVar3 = (iVar4 - *(int *)((int)this + 0x38)) + param_1;
    iVar5 = (iVar2 - *(int *)((int)this + 0x3c)) + param_2;
    *piVar1 = iVar3;
    *(int *)((int)this + 0x2c) = iVar5;
    *(int *)((int)this + 0x30) = iVar3 + (*(int *)((int)this + 0x30) - iVar4);
    *(int *)((int)this + 0x34) = iVar5 + (*(int *)((int)this + 0x34) - iVar2);
    *(int *)((int)this + 0x3c) = param_2;
    *(int *)((int)this + 0x38) = param_1;
    if (*(int *)((int)this + 0x50) != 0) {
      iVar4 = *(int *)(*(int *)((int)this + 8) + 0x134);
      iVar4 = UI_IsValidSize(this,*(int *)(iVar4 + 0x248),*(int *)(iVar4 + 0x24c));
      if (iVar4 == 0) {
        (**(code **)(*(int *)this + 0xc))(5,0,0);
      }
    }
    UI_ClipRect(*(void **)((int)this + 8),piVar1,1);
  }
  return;
}

