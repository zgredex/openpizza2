// rea decompile_all
// name: FUN_004e0c40
// address: 0x4e0c40
// body: available
// range: 0x4e0c40-0x4e0de9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e0c40(void *this,int param_1,float param_2,uint param_3,char param_4)

{
  void *this_00;
  float fVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  if (param_3 == 0xffffffff) {
    iVar3 = *(int *)((int)this + 0x48);
    param_3 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    iVar2 = FUN_00482820(DAT_0057c670);
    if ((iVar3 == iVar2) && (param_4 == '\0')) {
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x14,-1);
      UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x17,-1);
      lVar4 = __ftol();
      FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x14,(int)lVar4,-1);
      FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x17,(int)lVar4,-1);
    }
  }
  iVar3 = Game_FindRecordByField4(this,param_3);
  if (iVar3 != 0) {
    fVar1 = param_2 + (float)*(double *)((int)this + 0x108);
    *(double *)((int)this + 0x108) = (double)fVar1;
    if (1e+09 < fVar1) {
      *(undefined4 *)((int)this + 0x108) = 0xff800000;
      *(undefined4 *)((int)this + 0x10c) = 0x41cdcd64;
    }
    *(float *)(iVar3 + 0x10 + param_1 * 4) = param_2 + *(float *)(iVar3 + 0x10 + param_1 * 4);
    if (0.0 <= *(double *)((int)this + 0x108)) {
      FUN_004e3be0((int)this);
    }
  }
  if (*(int *)(DAT_0057c670 + 600) == 0) {
    iVar3 = *(int *)((int)this + 0x48);
    iVar2 = FUN_00482820(DAT_0057c670);
    if ((iVar2 == iVar3) && (this_00 = *(void **)(DAT_0057c670 + 0x2d9c), this_00 != (void *)0x0)) {
      iVar3 = 0;
      lVar4 = __ftol();
      FUN_0054bf70(this_00,(uint)lVar4,(int)((ulonglong)lVar4 >> 0x20),iVar3);
      iVar3 = 1;
      lVar4 = __ftol();
      FUN_0054bf70(this_00,*(uint *)((int)this_00 + 0x1b0) + (uint)lVar4,
                   *(int *)((int)this_00 + 0x1b4) + (int)((ulonglong)lVar4 >> 0x20) +
                   (uint)CARRY4(*(uint *)((int)this_00 + 0x1b0),(uint)lVar4),iVar3);
    }
    if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
      FUN_005301c0(*(void **)(DAT_0057c670 + 0x264),-0x18648,0x23,0);
    }
  }
  return;
}

