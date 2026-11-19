// rea decompile_all
// name: FUN_0049b5f0
// address: 0x49b5f0
// body: available
// range: 0x49b5f0-0x49b714 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0049b5f0(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005586d6;
  local_c = ExceptionList;
  iVar6 = 0;
  local_14 = 0;
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = *(int *)(iVar1 + 0x124);
  if (iVar2 == 0) {
    return -1;
  }
  ExceptionList = &local_c;
  pvVar3 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    DAT_0057ca8c = (undefined4 *)0x0;
  }
  else {
    DAT_0057ca8c = FUN_004013a0(pvVar3,0);
  }
  local_4 = 0xffffffff;
  if (0 < iVar2) {
    do {
      iVar4 = IDMap_Lookup((void *)(iVar1 + 0x110),iVar6,(int *)0x0);
      if ((*(char *)(iVar4 + 0x1dc) == '\0') && (0 < *(int *)(iVar4 + 0x1d8))) {
        pvVar3 = operator_new(0x58);
        local_4 = 1;
        if (pvVar3 == (void *)0x0) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = FUN_00403370(pvVar3,(char *)(iVar4 + 4),iVar6);
        }
        local_4 = 0xffffffff;
        List_Add(DAT_0057ca8c,pcVar5);
        local_14 = local_14 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar2);
    if (local_14 != 0) {
      ExceptionList = local_c;
      return local_14;
    }
  }
  if (DAT_0057ca8c != (undefined4 *)0x0) {
    (**(code **)*DAT_0057ca8c)(1);
  }
  ExceptionList = local_c;
  return local_14;
}

