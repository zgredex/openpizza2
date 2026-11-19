// rea decompile_all
// name: FUN_0050bf50
// address: 0x50bf50
// body: available
// range: 0x50bf50-0x50c0e3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0050bf50(void *this,undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_74;
  undefined4 local_70 [5];
  int local_5c;
  undefined4 local_54 [18];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a318;
  local_c = ExceptionList;
  iVar5 = 0;
  ExceptionList = &local_c;
  FUN_004013a0(local_70,0);
  local_4 = 0;
  local_54[0] = 2;
  local_54[1] = 3;
  local_54[2] = 0;
  local_54[3] = 1;
  local_54[4] = 6;
  local_54[5] = 7;
  local_54[6] = 4;
  local_54[7] = 5;
  iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),param_2,(int *)0x0);
  if (*(int *)(iVar1 + 200) != 0) {
    iVar1 = MapObject_ComputeBlitRect(iVar1);
    FUN_00401440((int)local_70);
    puVar4 = local_54;
    do {
      iVar2 = FUN_004f3e10(*(void **)((int)this + 0xc4),iVar1,iVar5);
      iVar2 = FUN_004f3e10(*(void **)((int)this + 0xc4),iVar2,iVar5);
      if ((*(int *)(*(int *)(iVar2 + 8) + 0x28) != 0) &&
         (*(short *)(*(int *)(iVar2 + 8) + 0x24) != -1)) {
        local_74 = FUN_004014b0(local_70,iVar2);
        FUN_004018c0(local_70,&local_74);
        local_54[local_74 + 8] = *puVar4;
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar5 < 8);
    if (0 < local_5c) {
      uVar3 = FUN_004034d0(0,local_5c - 1);
      iVar1 = FUN_004017f0(local_70,uVar3,(int *)0x0);
      iVar1 = FUN_004f0cc0(*(void **)((int)this + 0xc4),1,
                           (int)*(short *)(*(int *)(iVar1 + 8) + 0x24));
      local_4 = 0xffffffff;
      *param_3 = local_54[uVar3 + 8];
      FUN_00401480(local_70);
      ExceptionList = local_c;
      return iVar1;
    }
  }
  local_4 = 0xffffffff;
  FUN_00401480(local_70);
  ExceptionList = local_c;
  return 0;
}

