// rea decompile_all
// name: FUN_004f7920
// address: 0x4f7920
// body: available
// range: 0x4f7920-0x4f79fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f7920(void *this,int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c [3];
  
  iVar3 = 0;
  iVar2 = 0;
  local_1c = 0;
  local_20 = (void *)0x0;
  local_18 = 0;
  local_10 = *(int *)(*(int *)((int)this + param_1 * 0x168 + 0x70) + 0x15c);
  if (0 < local_10) {
    do {
      pvVar1 = (void *)Game_GetPlayerSubrecord(this,param_1,iVar2,1);
      if ((pvVar1 != (void *)0x0) &&
         (iVar3 = AI_ComputePlanScores((int)pvVar1,&local_14,local_c,2), iVar3 == 2)) {
        if ((local_20 == (void *)0x0) || (local_14 < local_18)) {
          local_18 = local_14;
          local_20 = pvVar1;
        }
        iVar3 = 3;
        local_1c = local_1c + local_14;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_10);
    if (((9 < iVar3) && (local_20 != (void *)0x0)) && (local_18 < local_1c / (iVar3 * 2))) {
      FUN_004fc990(this,pvVar1,1);
      return 1;
    }
  }
  return 0;
}

