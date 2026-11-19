// rea decompile_all
// name: FUN_0047d150
// address: 0x47d150
// body: available
// range: 0x47d150-0x47d208 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __thiscall FUN_0047d150(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  this_00 = *(void **)((int)this + 0x16f0);
  if (this_00 == (void *)0x0) {
    return (void *)0x0;
  }
  if (*(int *)(param_1 + 200) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 200) + 0x20);
  }
  iVar1 = *(int *)((int)this_00 + 0x8c);
  local_8 = 0;
  pvVar2 = (void *)0x0;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    pvVar3 = (void *)FUN_004d2a60(this_00,iVar1);
    if (*(int *)((int)pvVar3 + 0x38) == 0xd) {
      if (*(int *)((int)pvVar3 + 0xc4) == *(int *)(param_1 + 0xc4)) {
        if (*(int *)((int)pvVar3 + 200) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(*(int *)((int)pvVar3 + 200) + 0x20);
        }
        iVar5 = *(int *)(iVar6 + 0xc) - *(int *)(iVar4 + 0xc);
        iVar4 = *(int *)(iVar6 + 0x10) - *(int *)(iVar4 + 0x10);
        iVar4 = iVar4 * iVar4 + iVar5 * iVar5;
        if ((pvVar2 == (void *)0x0) || (iVar4 < local_8)) {
          pvVar2 = pvVar3;
          local_8 = iVar4;
        }
      }
      else {
        FUN_004d29d0(this_00,pvVar3);
      }
    }
  }
  return pvVar2;
}

