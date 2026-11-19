// rea decompile_all
// name: Game_FindBestCompositeRatedBranch
// address: 0x4d8140
// body: available
// range: 0x4d8140-0x4d8212 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * Game_FindBestCompositeRatedBranch(int param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  void *local_8;
  
                    /* Finds the highest composite-rated branch across all companies. */
  local_10 = -1;
  local_8 = (void *)0x0;
  local_c = 0;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,local_c);
    if ((iVar1 != 0) && (iVar4 = 0, 0 < *(int *)(iVar1 + 0x15c))) {
      do {
        this = (void *)FUN_004017f0((void *)(iVar1 + 0x148),iVar4,(int *)0x0);
        if (this != (void *)0x0) {
          if (param_1 == -1) {
            iVar3 = 0;
            iVar5 = 0;
            do {
              iVar2 = Branch_GetCustomerGroupRating(this,iVar5,1);
              iVar3 = iVar3 + iVar2;
              iVar5 = iVar5 + 1;
            } while (iVar5 < 8);
            iVar3 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
          }
          else {
            iVar3 = Branch_GetCustomerGroupRating(this,param_1,1);
          }
          if (local_10 < iVar3) {
            local_10 = iVar3;
            local_8 = this;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar1 + 0x15c));
    }
    local_c = local_c + 1;
  } while (local_c < 6);
  if (local_10 < 0x1e) {
    return (void *)0x0;
  }
  return local_8;
}

