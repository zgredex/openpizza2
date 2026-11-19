// rea decompile_all
// name: FUN_005235b0
// address: 0x5235b0
// body: available
// range: 0x5235b0-0x5237d6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005235b0(undefined4 *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0055a6bc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_0055c778;
  local_4 = 1;
  if (param_1[0x20e7] != 0) {
    FUN_005277d0(param_1,(byte *)(param_1 + 0x20d7));
  }
  FUN_00526e80(param_1,0);
  if ((HWND)param_1[0x20c8] != (HWND)0x0) {
    SetWindowLongA((HWND)param_1[0x20c8],-0x15,0);
  }
  FUN_00527a50((int)param_1);
  iVar2 = 0;
  if (0 < (int)param_1[0x8f]) {
    piVar4 = param_1 + 5;
    do {
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
      }
      *piVar4 = 0;
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar2 < (int)param_1[0x8f]);
  }
  FUN_00527850((int)param_1);
  iVar2 = 0;
  if (0 < (int)param_1[0x20bf]) {
    iVar3 = 0;
    do {
      if (*(int *)(param_1[0x20be] + iVar3 + 0x44) != 0) {
        FUN_0048e0a0();
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x48;
    } while (iVar2 < (int)param_1[0x20bf]);
  }
  if (param_1[0x9e] != 0) {
    param_1[0xa0] = 1;
    iVar2 = param_1[0x9e];
    while (iVar2 != 0) {
      Sleep(0x14);
      iVar2 = param_1[0x9e];
    }
  }
  FUN_005238c0((int)param_1);
  pvVar1 = (LPVOID)param_1[0x20c4];
  if (pvVar1 != (LPVOID)0x0) {
    FUN_0051ea00((int)pvVar1);
    FUN_0054dd78(pvVar1);
  }
  if ((undefined4 *)param_1[0x20eb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x20eb])(1);
  }
  if ((undefined4 *)param_1[0x6f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x6f])(1);
  }
  if ((param_1[0x70] != 0) && (iVar2 = FUN_00539f00(DAT_0057c5c8), iVar2 != 2)) {
    (**(code **)(*(int *)param_1[0x70] + 8))((int *)param_1[0x70]);
  }
  if ((undefined4 *)param_1[0x72] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x72])(1);
  }
  if ((undefined4 *)param_1[0x91] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x91])(1);
  }
  piVar4 = param_1 + 0x94;
  iVar2 = 8;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if ((LPVOID)param_1[0x20be] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0x20be]);
  }
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  if ((undefined4 *)param_1[0x90] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x90])(1);
  }
  FUN_00527250((int)param_1);
  CloseHandle((HANDLE)param_1[0x20d5]);
  local_4 = local_4 & 0xffffff00;
  Array_Destroy(param_1 + 0x20c9);
  local_4 = 0xffffffff;
  FUN_00401300(param_1 + 0x73);
  ExceptionList = pvStack_c;
  return;
}

