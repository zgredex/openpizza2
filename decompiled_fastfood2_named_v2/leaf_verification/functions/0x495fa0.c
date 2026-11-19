// rea decompile_all
// name: FUN_00495fa0
// address: 0x495fa0
// body: available
// range: 0x495fa0-0x49615d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00495fa0(void)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558541;
  local_c = ExceptionList;
  iVar1 = *(int *)(DAT_0057c700 + 0x124);
  iVar5 = 0;
  iVar6 = *(int *)((int)DAT_0057c670 + 0x9c);
  if (iVar1 == 0) {
    ExceptionList = &local_c;
    FUN_00482b70(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581698,0);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057c710 = (undefined4 *)0x0;
  }
  else {
    DAT_0057c710 = FUN_004013a0(pvVar2,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(iVar6 + 0x14dc) != 0) {
    pvVar2 = operator_new(0x58);
    iVar5 = 1;
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = FUN_00403370(pvVar2,DAT_00582aa4,0);
    }
    local_4 = 0xffffffff;
    FUN_004014b0(DAT_0057c710,pcVar3);
  }
  iVar6 = 0;
  if (0 < iVar1) {
    do {
      iVar4 = IDMap_Lookup((void *)(DAT_0057c700 + 0x110),iVar6,(int *)0x0);
      if (*(char *)(iVar4 + 0x1dc) == '\0') {
        pvVar2 = operator_new(0x58);
        local_4 = 2;
        if (pvVar2 == (void *)0x0) {
          pcVar3 = (char *)0x0;
        }
        else {
          pcVar3 = FUN_00403370(pvVar2,(char *)(iVar4 + 4),iVar6 + 1);
        }
        local_4 = 0xffffffff;
        FUN_004014b0(DAT_0057c710,pcVar3);
        iVar5 = iVar5 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  if (iVar5 == 0) {
    FUN_00482b70(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581a00,0);
    ExceptionList = local_c;
    return;
  }
  FUN_00483210(DAT_0057c670,0xfffe7986,DAT_0058282c,DAT_00581208,(int)DAT_0057c710,0,0);
  ExceptionList = local_c;
  return;
}

