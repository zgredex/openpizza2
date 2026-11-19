// rea decompile_all
// name: FUN_004f7a50
// address: 0x4f7a50
// body: available
// range: 0x4f7a50-0x4f7b43 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f7a50(int param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_14;
  int local_10;
  
  iVar2 = Game_GetPlayerBySlot(DAT_0057c670,param_1);
  iVar1 = *(int *)(iVar2 + 0x15c);
  param_1 = 0;
  local_10 = 0;
  local_14 = 0;
  if (0 < iVar1) {
    do {
      this = (void *)IDMap_Lookup((void *)(iVar2 + 0x148),local_14,(int *)0x0);
      if (this != (void *)0x0) {
        iVar3 = FUN_0047aac0(this,0xffffffff);
        iVar6 = 0;
        if (0 < iVar3) {
          do {
            piVar4 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),iVar6,(int *)0x0);
            if (*piVar4 != 0) {
              param_1 = param_1 + *(int *)(*piVar4 + 0x3c);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar3);
        }
        local_10 = *(int *)((int)this + 0x14b0);
      }
      local_14 = local_14 + 1;
    } while (local_14 < iVar1);
  }
  iVar6 = 0;
  iVar1 = *(int *)(iVar2 + 0x194);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar5 = IDMap_Lookup((void *)(iVar2 + 0x180),iVar3,(int *)0x0);
      if ((iVar5 != 0) && (*(char *)(iVar5 + 0x3c) == '\0')) {
        iVar6 = iVar6 + *(int *)(iVar5 + 0x40);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return local_10 + iVar6 + param_1;
}

