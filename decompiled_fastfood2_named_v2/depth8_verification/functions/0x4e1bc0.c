// rea decompile_all
// name: Company_CollectUnprofitableBranches
// address: 0x4e1bc0
// body: available
// range: 0x4e1bc0-0x4e1d39 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall Company_CollectUnprofitableBranches(int param_1)

{
  int iVar1;
  int *piVar2;
  void *this;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Collects branches whose profit is below half the company average. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005594db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  piVar2 = operator_new(*(int *)(param_1 + 0x124) * 8 + 0x50);
  this = operator_new(0x1c);
  iVar7 = 0;
  local_4 = 0;
  if (this == (void *)0x0) {
    local_10 = (undefined4 *)0x0;
  }
  else {
    local_10 = FUN_004013a0(this,0);
  }
  local_4 = 0xffffffff;
  if (0 < *(int *)(param_1 + 0x124)) {
    iVar6 = 0;
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x124)) {
      piVar8 = piVar2;
      do {
        *piVar8 = iVar7;
        iVar3 = FUN_004017f0((void *)(param_1 + 0x110),iVar7,(int *)0x0);
        iVar3 = *(int *)(iVar3 + 0x30c);
        piVar8[1] = iVar3;
        iVar5 = iVar5 + iVar3;
        iVar6 = iVar6 + 1;
        piVar8 = piVar8 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x124));
    }
    iVar5 = iVar5 / *(int *)(param_1 + 0x124);
    if (0 < iVar5) {
      while (iVar6 = iVar6 + -1, 0 < iVar6) {
        iVar7 = iVar6;
        piVar8 = piVar2;
        do {
          piVar4 = piVar8 + 2;
          if (piVar8[3] < piVar8[1]) {
            iVar3 = *piVar8;
            iVar1 = piVar8[1];
            *piVar8 = *piVar4;
            piVar8[1] = piVar8[3];
            *piVar4 = iVar3;
            piVar8[3] = iVar1;
          }
          iVar7 = iVar7 + -1;
          piVar8 = piVar4;
        } while (iVar7 != 0);
      }
      iVar7 = 0;
      if (0 < *(int *)(param_1 + 0x124)) {
        piVar8 = piVar2;
        do {
          iVar6 = FUN_004017f0((void *)(param_1 + 0x110),*piVar8,(int *)0x0);
          if (*(int *)(iVar6 + 0x30c) < iVar5 / 2) {
            FUN_004014b0(local_10,iVar6);
          }
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 2;
        } while (iVar7 < *(int *)(param_1 + 0x124));
      }
    }
  }
  FUN_0054dd78(piVar2);
  ExceptionList = local_c;
  return local_10;
}

