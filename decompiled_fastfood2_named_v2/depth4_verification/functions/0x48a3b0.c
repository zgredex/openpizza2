// rea decompile_all
// name: FUN_0048a3b0
// address: 0x48a3b0
// body: available
// range: 0x48a3b0-0x48a48d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0048a3b0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558388;
  local_c = ExceptionList;
  iVar5 = 0;
  ExceptionList = &local_c;
  FUN_004013a0(local_28,0);
  local_4 = 0;
  iVar4 = *(int *)(param_1 + 0x30);
  if (0 < *(int *)((int)this + 0x50)) {
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0x3c),iVar5,(int *)0x0);
      iVar2 = FUN_0050dbd0(iVar1);
      if ((((iVar2 == 0) && (*(int *)(iVar1 + 0x30) == iVar4)) && (*(int *)(iVar1 + 0x74) == 0)) &&
         (*(int *)(iVar1 + 0x110) == -1)) {
        FUN_004014b0(local_28,iVar1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)this + 0x50));
  }
  iVar4 = 0;
  if (0 < local_14) {
    do {
      iVar5 = FUN_004017f0(local_28,iVar4,(int *)0x0);
      if (iVar5 == param_1) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < local_14);
  }
  if (iVar4 == local_14 + -1) {
    iVar4 = 0;
  }
  else {
    iVar4 = iVar4 + 1;
  }
  uVar3 = FUN_004017f0(local_28,iVar4,(int *)0x0);
  local_4 = 0xffffffff;
  FUN_00401480(local_28);
  ExceptionList = local_c;
  return uVar3;
}

