// rea decompile_all
// name: FUN_0052b230
// address: 0x52b230
// body: available
// range: 0x52b230-0x52b375 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0052b230(undefined4 *param_1)

{
  void *this;
  int *piVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055a8a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c7b0;
  local_4 = 0;
  this = *(void **)(param_1[2] + 0x134);
  if ((param_1[0x29] == 1) || (param_1[0x29] == 3)) {
    FUN_00527c80(this,(int)param_1);
  }
  if (param_1[0x2b] != 0) {
    switch(param_1[0x29]) {
    case 0:
      if (*(char *)(param_1 + 0x15) == '\0') {
        if ((undefined4 *)param_1[0x25] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)param_1[0x25])(1);
        }
      }
      else {
        FUN_005277d0(this,(byte *)(param_1 + 0x15));
      }
      break;
    case 1:
      Record_Clear48((void *)param_1[0x15],param_1[0x26]);
      if ((param_1[0x2b] != 0) && ((undefined4 *)param_1[0x15] != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)param_1[0x15])(1);
      }
      break;
    case 2:
      if ((undefined4 *)param_1[0x15] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x15])(1);
      }
      break;
    case 3:
      if (*(int *)param_1[0x2e] != 0) {
        _BinkClose_4(*(int *)param_1[0x2e]);
        *(undefined4 *)param_1[0x2e] = 0;
      }
    }
  }
  if ((LPVOID)param_1[0x28] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0x28]);
  }
  if (param_1[0x2e] != 0) {
    piVar1 = *(int **)(param_1[0x2e] + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    FUN_0054dd78((LPVOID)param_1[0x2e]);
  }
  local_4 = 0xffffffff;
  FUN_00520b10(param_1);
  ExceptionList = pvStack_c;
  return;
}

