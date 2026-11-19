// rea decompile_all
// name: FUN_004ddfb0
// address: 0x4ddfb0
// body: available
// range: 0x4ddfb0-0x4de02c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall FUN_004ddfb0(void *this,int param_1,int param_2)

{
  void *this_00;
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_8;
  
  iVar5 = 0;
  local_8 = (void *)0x0;
  iVar1 = FUN_004ddde0((int)this);
  iVar4 = 0;
  pvVar2 = (void *)0x0;
  if (0 < iVar1) {
    do {
      pvVar2 = (void *)FUN_004dde30(this,iVar4);
      iVar3 = Stats_GetMaxTimelineCount(pvVar2,param_1);
      if (iVar5 < iVar3) {
        iVar5 = iVar3;
        local_8 = pvVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
    pvVar2 = local_8;
  }
  if (((param_2 == 0) || (this_00 = *(void **)(param_2 + 0x14dc), this_00 == (void *)0x0)) ||
     (iVar1 = Stats_GetMaxTimelineCount(this_00,param_1), iVar1 <= iVar5)) {
    return pvVar2;
  }
  return this_00;
}

