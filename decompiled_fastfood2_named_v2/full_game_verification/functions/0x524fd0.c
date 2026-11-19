// rea decompile_all
// name: UI_SelectObjectRecord
// address: 0x524fd0
// body: available
// range: 0x524fd0-0x52507e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_SelectObjectRecord(void *this,void *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (((param_1 != (void *)0x0) && (*(int *)((int)param_1 + 0x4c) != 0)) &&
     ((*(void **)((int)this + 0x228) == (void *)0x0 || (*(void **)((int)this + 0x228) == param_1))))
  {
    UI_RefreshChildRect(this);
    piVar2 = (int *)Array_GetRecordByKey(param_1,param_2);
    piVar1 = *(int **)((int)this + 0x22c);
    if ((piVar1 != (int *)0x0) && (piVar1 != piVar2)) {
      (**(code **)(*piVar1 + 0xc))(10,0,0);
      *(undefined4 *)((int)this + 0x224) = 0;
      *(undefined4 *)((int)this + 0x22c) = 0;
    }
    *(int **)((int)this + 0x82d4) = piVar2;
    *(void **)((int)this + 0x82c8) = param_1;
    iVar3 = (**(code **)(*piVar2 + 0xc))(0xb,0,0);
    if (iVar3 != 0) {
      *(undefined4 *)((int)this + 0x224) = *(undefined4 *)((int)this + 0x82c8);
      *(undefined4 *)((int)this + 0x22c) = *(undefined4 *)((int)this + 0x82d4);
      return;
    }
    *(undefined4 *)((int)this + 0x224) = 0;
    *(undefined4 *)((int)this + 0x22c) = 0;
  }
  return;
}

