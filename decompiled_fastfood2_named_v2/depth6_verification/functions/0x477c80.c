// rea decompile_all
// name: FUN_00477c80
// address: 0x477c80
// body: available
// range: 0x477c80-0x477e37 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00477c80(void *this,int param_1,float param_2,int param_3)

{
  void *this_00;
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  
  iVar2 = FUN_00477c20(this,param_3);
  iVar4 = *(int *)((int)this + 0x30);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  if (iVar4 == iVar3) {
    FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x14,-1);
    FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x17,-1);
    lVar6 = __ftol();
    FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x14,(int)lVar6,-1);
    FUN_00502f10(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x17,(int)lVar6,-1);
  }
  if (iVar2 != 0) {
    *(float *)(iVar2 + 0x10 + param_1 * 4) = param_2 + *(float *)(iVar2 + 0x10 + param_1 * 4);
    iVar4 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
    dVar1 = *(double *)(iVar4 + 0x108) + (double)param_2;
    if (999999999.0 < dVar1) {
      dVar1 = 999999999.0;
    }
    *(double *)(iVar4 + 0x108) = dVar1;
    if (0.0 <= dVar1) {
      FUN_004e3be0(iVar4);
    }
  }
  if (param_1 < 9) {
    uVar5 = FUN_00488d90((int)DAT_0057c670);
    iVar4 = uVar5 + param_1 * 9;
    *(float *)((int)this + iVar4 * 4 + 0x2cc) = param_2 + *(float *)((int)this + iVar4 * 4 + 0x2cc);
  }
  if (*(int *)((int)DAT_0057c670 + 600) == 0) {
    iVar4 = FUN_00482820((int)DAT_0057c670);
    if ((iVar4 == *(int *)((int)this + 0x30)) &&
       (this_00 = *(void **)((int)DAT_0057c670 + 0x2d9c), this_00 != (void *)0x0)) {
      iVar4 = 0;
      lVar6 = __ftol();
      FUN_0054bf70(this_00,(uint)lVar6,(int)((ulonglong)lVar6 >> 0x20),iVar4);
      iVar4 = 1;
      lVar6 = __ftol();
      FUN_0054bf70(this_00,*(uint *)((int)this_00 + 0x1b0) + (uint)lVar6,
                   *(int *)((int)this_00 + 0x1b4) + (int)((ulonglong)lVar6 >> 0x20) +
                   (uint)CARRY4(*(uint *)((int)this_00 + 0x1b0),(uint)lVar6),iVar4);
    }
    if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
      FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18648,0x23,0);
    }
  }
  return;
}

