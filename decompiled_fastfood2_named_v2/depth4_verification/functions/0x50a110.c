// rea decompile_all
// name: FUN_0050a110
// address: 0x50a110
// body: available
// range: 0x50a110-0x50a270 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050a110(void *param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  void *this_00;
  int iVar3;
  
  FUN_0050e850(param_1,0xffffffff);
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x20),*(int *)((int)param_1 + 0x50),(int *)0x0);
  this = (void *)FUN_00489820(DAT_0057c670,*(int *)(iVar2 + 0x81c),*(int *)(iVar2 + 0x820));
  if (this == (void *)0x0) {
    FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
    return;
  }
  this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),*(int *)((int)param_1 + 0x10c),
                                 (int *)0x0);
  if ((this_00 != (void *)0x0) && (*(int *)((int)this_00 + 0x38) == 0x1a)) {
    iVar2 = FUN_0047ebc0(this,*(int *)((int)param_1 + 0x10c));
    if (iVar2 != 0) {
      iVar1 = *(int *)((int)this + 0x30);
      iVar3 = FUN_00482820((int)DAT_0057c670);
      if (iVar1 == iVar3) {
        FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x19,1);
        FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x19,-1,-1);
      }
      FUN_00477c80(this,0x16,*(float *)(iVar2 + 0x1c),-1);
      *(undefined4 *)((int)this_00 + 0x4c) = 0;
      *(undefined4 *)((int)this_00 + 0x54) = 0;
      Object_SetState(this_00,4);
      FUN_00507550(this_00,0xffff);
    }
    if ((*(char *)((int)this_00 + 0x104) != '\0') && (*(int *)((int)this_00 + 0xfc) != 0)) {
      iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      FUN_004d2d80(*(void **)((int)this_00 + 0xfc),*(void **)(iVar2 + 0xfa8),1);
    }
  }
  FUN_00507e20(param_1,1,*(int *)((int)this + 0x16f0));
  return;
}

