// rea decompile_all
// name: FUN_00541ae0
// address: 0x541ae0
// body: available
// range: 0x541ae0-0x541c9f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_00541ae0(void *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  void *this;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055afcb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)((int)param_1 + 0x53) = 0;
  *(char **)((int)param_1 + 0x48) = *(char **)((int)param_1 + 0x44);
  pcVar3 = _strchr(*(char **)((int)param_1 + 0x44),0x2c);
  *(char **)((int)param_1 + 0x4c) = pcVar3;
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
  }
  *(undefined1 *)((int)param_1 + 0x3c) = 1;
  iVar4 = FUN_00541930((int)param_1);
  if (-1 < iVar4) {
    if (*(int *)((int)param_1 + 0x28) == 0) {
      iVar1 = *(int *)((int)param_1 + 0x2c);
      if (*(int *)(iVar1 + 0xc) != 0) {
        local_20 = *(undefined4 *)(iVar1 + 0x14);
        local_1c = *(undefined4 *)(iVar1 + 0x18);
        local_18 = *(undefined4 *)(iVar1 + 0x1c);
        local_14 = *(undefined4 *)(iVar1 + 0x20);
        local_10 = (void *)CONCAT22(local_10._2_2_,*(undefined2 *)(iVar1 + 0x24));
        if (*(short *)(iVar1 + 0x14) != 1) {
          FUN_0053f840((undefined2 *)&local_20);
        }
      }
      (**(code **)(**(int **)((int)param_1 + 0x34) + 4))(*(int **)((int)param_1 + 0x34));
      this = operator_new(0x4c);
      uStack_4 = 0;
      if (this == (void *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        uVar5 = FUN_00541ca0(*(int **)((int)param_1 + 0x34));
        puVar6 = (undefined4 *)(uVar5 | *(uint *)((int)param_1 + 0x74));
        uVar5 = FUN_00541cf0(0,0x3ff00000,(int)&local_20);
        puVar6 = FUN_005406a0(this,*(int **)((int)param_1 + 0x34),&local_20,uVar5,puVar6);
      }
      uStack_4 = 0xffffffff;
      *(undefined4 **)((int)param_1 + 0x28) = puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        (**(code **)(**(int **)((int)param_1 + 0x34) + 8))(*(int **)((int)param_1 + 0x34));
        ExceptionList = local_10;
        return -0x7ff8fff2;
      }
      if (iVar4 < 0) {
        ExceptionList = local_c;
        return iVar4;
      }
      if (*(int *)((int)param_1 + 0x8c) == 0) {
        uVar5 = *(uint *)((int)param_1 + 0x78);
      }
      else {
        uVar5 = *(uint *)((int)param_1 + 0x9c);
      }
      FUN_005410b0(puVar6,uVar5);
      FUN_005411c0(*(int *)((int)param_1 + 0x28));
      (**(code **)(**(int **)((int)param_1 + 0x28) + 0x14))(*(undefined4 *)((int)param_1 + 0x7c));
    }
    iVar4 = FUN_005424b0(param_1,0,*(uint *)(*(int *)((int)param_1 + 0x28) + 0x10) >> 1);
    if (-1 < iVar4) {
      piVar2 = *(int **)(*(int *)((int)param_1 + 0x28) + 0x48);
      (**(code **)(*piVar2 + 0x34))(piVar2,0);
      *(undefined1 *)((int)param_1 + 0x55) = 1;
      *(undefined1 *)((int)param_1 + 0x53) = 1;
    }
  }
  ExceptionList = local_c;
  return iVar4;
}

