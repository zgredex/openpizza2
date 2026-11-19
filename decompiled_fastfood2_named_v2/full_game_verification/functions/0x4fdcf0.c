// rea decompile_all
// name: City_MoveResidentIntoVacantHouse
// address: 0x4fdcf0
// body: available
// range: 0x4fdcf0-0x4fddfc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 City_MoveResidentIntoVacantHouse(void *param_1,int param_2,int param_3)

{
  void *this;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_c [3];
  
                    /* Moves a resident into a vacant house with an acceptance roll. */
  local_c[0] = 1000;
  local_c[1] = 1000;
  local_c[2] = 1000;
  if (*(char *)(param_3 + 0x1880 + param_2) != '\0') {
    return 3;
  }
  this = (void *)Game_FindIdleObjectByClass(DAT_0057c670,param_3);
  if (this == (void *)0x0) {
    return 3;
  }
  iVar1 = Game_GetPlayerCity((int)param_1);
  uVar2 = Game_CanAffordWithCurrency
                    (param_1,0x17,
                     (float)((((*(int *)(iVar1 + 0x60) + *(int *)(iVar1 + 0x48)) * -3 + 100) *
                             local_c[param_3]) / 100),'\x01',0xffffffff);
  if ((char)uVar2 == '\0') {
    return 2;
  }
  iVar1 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)(param_2 + 0x34),(int *)0x0);
  uVar3 = Random_RangeFast(0,99);
  if ((int)uVar3 <= *(int *)(iVar1 + 0xc38 + (param_3 + *(int *)((int)param_1 + 0x48) * 4) * 4)) {
    Person_AssignBranchStaffRole(this,param_2,param_3,*(int *)((int)param_1 + 0x48),'\x01');
    *(int *)((int)param_1 + 0x70) = *(int *)((int)param_1 + 0x70) + 1;
  }
  return 1;
}

