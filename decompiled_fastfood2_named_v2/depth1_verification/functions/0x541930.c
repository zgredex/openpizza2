// rea decompile_all
// name: FUN_00541930
// address: 0x541930
// body: available
// range: 0x541930-0x541ad5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_00541930(int param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int local_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055afb6;
  local_c = ExceptionList;
  local_14 = 0;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    puVar1 = *(undefined1 **)(param_1 + 0x4c);
    if (puVar1 == (undefined1 *)0x0) {
      return 1;
    }
    ExceptionList = &local_c;
    if (puVar1[1] != '\0') {
      ExceptionList = &local_c;
      *puVar1 = 0x2c;
      pcVar3 = (char *)(*(int *)(param_1 + 0x4c) + 1);
      *(char **)(param_1 + 0x48) = pcVar3;
      pcVar3 = _strchr(pcVar3,0x2c);
      *(char **)(param_1 + 0x4c) = pcVar3;
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
      }
    }
  }
  else {
    ExceptionList = &local_c;
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  pcVar3 = *(char **)(param_1 + 0x48);
  if (pcVar3 == (char *)0x0) {
    ExceptionList = local_c;
    return 1;
  }
  piVar2 = *(int **)(param_1 + 0x2c);
  if (piVar2 == (int *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x30))(*(undefined4 **)(param_1 + 0x30));
    pvStack_10 = operator_new(0x4c);
    uStack_4 = 0;
    if (pvStack_10 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_0053f460(pvStack_10,*(void **)(param_1 + 0x30),pcVar3,&local_14);
    }
    *(undefined4 **)(param_1 + 0x2c) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
joined_r0x00541a81:
    uStack_4 = 0xffffffff;
    if (local_14 < 0) goto LAB_00541ab4;
    uStack_4 = 0xffffffff;
    Parser_ResetTokenState((uint *)(param_1 + 8));
  }
  else if (1 < *(int *)(param_1 + 0x40)) {
    (**(code **)(*piVar2 + 4))(piVar2);
    *(undefined4 *)(param_1 + 0x2c) = 0;
    (**(code **)**(undefined4 **)(param_1 + 0x30))(*(undefined4 **)(param_1 + 0x30));
    pvStack_10 = operator_new(0x4c);
    uStack_4 = 1;
    if (pvStack_10 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_0053f460(pvStack_10,*(void **)(param_1 + 0x30),pcVar3,&local_14);
    }
    *(undefined4 **)(param_1 + 0x2c) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      ExceptionList = local_c;
      return -0x7ff8fff2;
    }
    goto joined_r0x00541a81;
  }
  if (-1 < local_14) {
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x34) = *(undefined1 *)(param_1 + 0x52);
    if (*(char *)(param_1 + 0x88) == '\0') {
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(undefined1 *)(param_1 + 0x88) = 1;
      ExceptionList = local_c;
      return local_14;
    }
    ExceptionList = local_c;
    return local_14;
  }
LAB_00541ab4:
  (**(code **)(**(int **)(param_1 + 0x2c) + 4))(*(int **)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = 0;
  ExceptionList = local_c;
  return local_14;
}

