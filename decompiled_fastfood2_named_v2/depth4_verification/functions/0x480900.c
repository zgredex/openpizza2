// rea decompile_all
// name: FUN_00480900
// address: 0x480900
// body: available
// range: 0x480900-0x480a69 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00480900(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  char *this;
  int *piVar6;
  undefined4 local_28 [5];
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0(local_28,0);
  local_4 = 0;
  bVar1 = FUN_00480880(param_1);
  if ((CONCAT31(extraout_var,bVar1) == 0) && (*(char *)(param_1 + 0x16f5) == '\0')) {
    iVar2 = FUN_004d2ae0(*(void **)(param_1 + 0x16f0),0x1b);
    if (iVar2 < 0x1e) {
      pvVar5 = *(void **)(param_1 + 0x16f0);
      iVar2 = 0;
      if (0 < *(int *)((int)pvVar5 + 0x8c)) {
        do {
          iVar3 = FUN_004d2a60(pvVar5,iVar2);
          if ((*(int *)(iVar3 + 0x30) == 0x1b) && (*(int *)(iVar3 + 0x38) != 0x1f)) {
            FUN_004014b0(local_28,iVar3);
          }
          pvVar5 = *(void **)(param_1 + 0x16f0);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)((int)pvVar5 + 0x8c));
      }
      if (0 < local_14) {
        piVar6 = (int *)0x0;
        uVar4 = FUN_004034d0(0,local_14 - 1);
        iVar2 = FUN_004017f0(local_28,uVar4,piVar6);
        pvVar5 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                      (int *)0x0);
        this = FUN_004d50a0(pvVar5,0x1b,param_1);
        if (*(int *)(iVar2 + 200) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(*(int *)(iVar2 + 200) + 0x20);
        }
        FUN_00505e60(this,1,iVar2);
        Object_SetState(this,0x18);
        if (*(void **)(param_1 + 0x16f0) != (void *)0x0) {
          iVar2 = FUN_004d2ae0(*(void **)(param_1 + 0x16f0),0x20);
          if (0 < iVar2) {
            FUN_00509240((int)this);
          }
        }
      }
      local_4 = 0xffffffff;
      FUN_00401480(local_28);
      ExceptionList = local_c;
      return;
    }
  }
  local_4 = 0xffffffff;
  FUN_00401480(local_28);
  ExceptionList = local_c;
  return;
}

