// rea decompile_all
// name: FUN_004fc7d0
// address: 0x4fc7d0
// body: available
// range: 0x4fc7d0-0x4fc986 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fc7d0(void *this,void *param_1,int param_2)

{
  void *this_00;
  int iVar1;
  void *this_01;
  short *psVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  int local_24;
  int local_20 [8];
  
  this_00 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
  if (*(int *)((int)this + *(int *)((int)this_00 + 0x4c) * 0x168 + 0x114) != 0) {
    iVar1 = FUN_004e2280((int)this_00);
    if ((((0 < iVar1) && (*(int *)((int)param_1 + 0x38) != 2)) &&
        (*(int *)(*(int *)((int)param_1 + 0x16f0) + 0x38) == 0)) &&
       (*(int *)((int)param_1 + 0x2c) == 0)) {
      iVar1 = *(int *)(*(int *)((int)param_1 + 0x16f0) + 0x74);
      if (iVar1 == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = FUN_004e4490(iVar1);
      }
      if ((*(int *)((int)param_1 + 0x38) == 0) || (*(int *)((int)param_1 + 0x38) == 1)) {
        pvVar4 = (void *)0xaa;
      }
      else {
        pvVar4 = param_1;
      }
      this_01 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                     *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      FUN_004d8320(this_01,*(int *)((int)param_1 + 0x16f0),iVar1 + -10);
      iVar1 = FUN_004d8320(this_01,*(int *)((int)param_1 + 0x16f0),(int)pvVar4);
      lVar5 = __ftol();
      if ((int)lVar5 < iVar1) {
        lVar5 = FUN_004d6390(1,*(int *)((int)param_1 + 0x38));
        FUN_004e0b60(this_00,2,(float)(int)lVar5,'\0',0xffffffff);
        Game_MarkObjectsDirtyForState(param_1,5);
        return 1;
      }
      if (param_2 != 0) {
        iVar1 = 0;
        psVar2 = (short *)(param_2 + 0x1a);
        iVar3 = 8;
        do {
          iVar1 = iVar1 + *psVar2;
          psVar2 = psVar2 + 0x1a;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        if (8 < iVar1) {
          iVar1 = FUN_004f7b90((int)param_1,&local_24,local_20,2);
          if ((1 < iVar1) && (29999 < local_24)) {
            lVar5 = FUN_004d6390(1,*(int *)((int)param_1 + 0x38));
            FUN_004e0b60(this_00,2,(float)(int)lVar5,'\0',0xffffffff);
            Game_MarkObjectsDirtyForState(param_1,5);
          }
        }
      }
    }
  }
  return 1;
}

