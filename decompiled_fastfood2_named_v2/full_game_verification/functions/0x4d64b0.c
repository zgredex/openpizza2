// rea decompile_all
// name: Map_PickObjectsAtPoint
// address: 0x4d64b0
// body: available
// range: 0x4d64b0-0x4d656e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Map_PickObjectsAtPoint(void *this,void *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2 << ((byte)DAT_00580a50 & 0x1f);
  param_2 = 0;
  iVar4 = iVar4 + *(int *)(*(int *)((int)this + 0xfa8) + 0x24);
  iVar3 = (param_3 << ((byte)DAT_00580a50 & 0x1f)) + *(int *)(*(int *)((int)this + 0xfa8) + 0x28);
  if (0 < *(int *)((int)this + 0xfc0)) {
    do {
      iVar1 = IDMap_Lookup((void *)((int)this + 0xfac),param_2,(int *)0x0);
      if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0x20)) && (*(int *)(iVar1 + 0xc) != 0x12378d6)) {
        if (((*(int *)(iVar1 + 0x10) <= iVar4) && (iVar4 <= *(int *)(iVar1 + 0x18))) &&
           ((*(int *)(iVar1 + 0x14) <= iVar3 && (iVar3 <= *(int *)(iVar1 + 0x1c))))) {
          puVar2 = operator_new(8);
          *puVar2 = 2;
          *(int *)(puVar2 + 4) = iVar1;
          List_Add(param_1,puVar2);
        }
      }
      param_2 = param_2 + 1;
    } while (param_2 < *(int *)((int)this + 0xfc0));
  }
  return;
}

