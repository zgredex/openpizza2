// rea decompile_all
// name: FUN_00487310
// address: 0x487310
// body: available
// range: 0x487310-0x48751f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00487310(int param_1)

{
  undefined4 *puVar1;
  void *this;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_4;
  
  iStack_4 = param_1;
  FUN_00401320(*(int *)(param_1 + 0x240));
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  if (*(undefined4 **)(param_1 + 0x300) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x300))(1);
    *(undefined4 *)(param_1 + 0x300) = 0;
  }
  FUN_004872b0(param_1);
  FUN_00401340(*(int *)(param_1 + 0x240));
  UI_DestroyBriefingList((void *)(param_1 + 0x304));
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x360) = 0xffffffff;
  FUN_004830e0(param_1);
  DAT_0057cda0 = 0;
  piVar4 = (int *)(param_1 + 0x224);
  iVar2 = 6;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(int *)(param_1 + 0x50);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0((void *)(param_1 + 0x3c),iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00401440(param_1 + 0x3c);
  piVar4 = (int *)(param_1 + 0x200);
  iVar2 = 6;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0((void *)(param_1 + 4),iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00401440(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0x6c);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0((void *)(param_1 + 0x58),iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00401440(param_1 + 0x58);
  iVar2 = *(int *)(param_1 + 0x34);
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      puVar1 = (undefined4 *)FUN_004017f0((void *)(param_1 + 0x20),iVar3,(int *)0x0);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00401440(param_1 + 0x20);
  FUN_00401440(DAT_0057c5cc + 0x2c3f8);
  this = (void *)FUN_00528040(DAT_0057c5e0,*(int *)(param_1 + 0x2dac),(int *)0x0);
  if (this != (void *)0x0) {
    iVar2 = FUN_005312e0((int)this);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      FUN_005312f0(this,iVar2,&iStack_4);
      if (iStack_4 != 99999) {
        FUN_005311a0(this,iStack_4);
      }
    }
    iVar2 = FUN_00531cf0(this,99999);
    if (iVar2 == 0) {
      return;
    }
    FUN_00521380(iVar2);
    *(undefined4 *)((int)this + 0xe0) = 1;
  }
  *(undefined4 *)(param_1 + 0x1508) = 1;
  if (*(undefined4 **)(param_1 + 0x300) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x300))(1);
    *(undefined4 *)(param_1 + 0x300) = 0;
  }
  return;
}

