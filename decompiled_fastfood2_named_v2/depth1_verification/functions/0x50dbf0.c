// rea decompile_all
// name: FUN_0050dbf0
// address: 0x50dbf0
// body: available
// range: 0x50dbf0-0x50dd06 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0050dbf0(int param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a338;
  local_c = ExceptionList;
  iVar4 = 0;
  ExceptionList = &local_c;
  FUN_004013a0(local_28,0);
  this = *(void **)(param_1 + 0xfc);
  local_4 = 0;
  if (0 < *(int *)((int)this + 0x8c)) {
    do {
      iVar1 = Game_MapRecordToGlobal(this,iVar4);
      iVar2 = FUN_0050d750(iVar1);
      if (iVar2 != 0) {
        iVar2 = FUN_0050dbd0(iVar1);
        if ((iVar2 == 0) && (*(int *)(iVar1 + 200) != 0)) {
          if ((*(int *)(param_1 + 0x38) == 0x3b) && (*(int *)(iVar1 + 0x38) == 0x3a)) {
            FUN_004014b0(local_28,iVar1);
          }
          if ((*(int *)(param_1 + 0x38) == 0x3a) && (*(int *)(iVar1 + 0x38) == 0x3b)) {
            FUN_004014b0(local_28,iVar1);
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x8c));
  }
  if (local_14 < 1) {
    local_4 = 0xffffffff;
    FUN_00401480(local_28);
    ExceptionList = local_c;
    return 0;
  }
  piVar5 = (int *)0x0;
  uVar3 = FUN_004034d0(0,local_14 - 1);
  iVar4 = FUN_004017f0(local_28,uVar3,piVar5);
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(iVar4 + 0x164);
  FUN_00401480(local_28);
  ExceptionList = local_c;
  return iVar4;
}

