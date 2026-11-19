// rea decompile_all
// name: FUN_0047cd80
// address: 0x47cd80
// body: available
// range: 0x47cd80-0x47ce48 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047cd80(void *this,uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar5 = -1;
  iVar6 = -1;
  local_4 = -1;
  local_8 = 0;
  if (*(int *)((int)this + 0x170c) < 1) {
    *param_2 = -1;
    *param_3 = -1;
    return;
  }
  do {
    iVar3 = FUN_004017f0((void *)((int)this + 0x16f8),local_8,(int *)0x0);
    if ((iVar3 != 0) && (bVar2 = FUN_004e5df0(iVar3), bVar2 == param_1)) {
      iVar1 = *(int *)(iVar3 + 4);
      iVar3 = *(int *)(iVar3 + 8);
      if (((iVar1 != iVar5) || (iVar3 != local_4)) &&
         (iVar4 = FUN_0047cc70(this,iVar1,iVar3), iVar6 < iVar4)) {
        iVar5 = iVar1;
        iVar6 = iVar4;
        local_4 = iVar3;
      }
    }
    local_8 = local_8 + 1;
  } while (local_8 < *(int *)((int)this + 0x170c));
  *param_2 = iVar5;
  *param_3 = local_4;
  return;
}

