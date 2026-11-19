// rea decompile_all
// name: Sound_GetChannelObject
// address: 0x54acc0
// body: available
// range: 0x54acc0-0x54ad79 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Sound_GetChannelObject(void *this,int param_1,int param_2)

{
  void *this_00;
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  this_00 = (void *)((int)this + 4);
  pvVar3 = (LPVOID)IDMap_Lookup(this_00,param_1,(int *)0x0);
  if (pvVar3 == (LPVOID)0x0) {
    return 0;
  }
  if ((*(int *)((int)pvVar3 + 0x14) != 0) && (param_2 == 0)) {
    return 0;
  }
  if (*(int *)((int)pvVar3 + 8) != -1) {
    UI_RemoveObject(*(void **)((int)this + 0x34),*(int *)((int)pvVar3 + 8));
    iVar1 = *(int *)((int)this + 0x18);
    iVar2 = *(int *)((int)pvVar3 + 0xc);
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        iVar4 = IDMap_Lookup(this_00,iVar6,(int *)0x0);
        if ((iVar4 != 0) && (iVar2 < *(int *)(iVar4 + 0xc))) {
          iVar5 = *(int *)(iVar4 + 0xc) - *(int *)((int)this + 0x28);
          *(int *)(iVar4 + 0xc) = iVar5;
          *(float *)(iVar4 + 0x20) = -(*(float *)(iVar4 + 0x1c) - (float)iVar5);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  }
  IDMap_RemoveByKey(this_00,(int)pvVar3);
  Mem_Free(pvVar3);
  return 1;
}

