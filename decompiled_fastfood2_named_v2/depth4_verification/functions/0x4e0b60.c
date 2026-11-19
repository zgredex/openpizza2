// rea decompile_all
// name: FUN_004e0b60
// address: 0x4e0b60
// body: available
// range: 0x4e0b60-0x4e0c3d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004e0b60(void *this,int param_1,float param_2,char param_3,uint param_4)

{
  double dVar1;
  int iVar2;
  void *this_00;
  float fVar3;
  int in_EAX;
  int iVar4;
  longlong lVar5;
  
  if (param_4 == 0xffffffff) {
    param_4 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    in_EAX = DAT_0057c670;
  }
  if (param_3 != '\0') {
    fVar3 = (float)*(double *)((int)this + 0x108) - param_2;
    if (fVar3 < 0.0) {
      return CONCAT22((short)((uint)in_EAX >> 0x10),
                      (ushort)(fVar3 < 0.0) << 8 | (ushort)NAN(fVar3) << 10 |
                      (ushort)(fVar3 == 0.0) << 0xe);
    }
  }
  iVar4 = FUN_004ddce0(this,param_4);
  if (iVar4 != 0) {
    *(double *)((int)this + 0x108) = (double)((float)*(double *)((int)this + 0x108) - param_2);
    *(float *)(iVar4 + 0x78 + param_1 * 4) = param_2 + *(float *)(iVar4 + 0x78 + param_1 * 4);
  }
  iVar4 = *(int *)(DAT_0057c670 + 600);
  if (*(int *)(DAT_0057c670 + 600) == 0) {
    iVar2 = *(int *)((int)this + 0x48);
    iVar4 = FUN_00482820(DAT_0057c670);
    if (iVar4 == iVar2) {
      this_00 = *(void **)(DAT_0057c670 + 0x2d9c);
      iVar4 = DAT_0057c670;
      if (this_00 != (void *)0x0) {
        dVar1 = (double)(param_2 + (float)*(double *)((int)this + 0x108));
        FUN_0054bf50(this_00,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),0);
        iVar4 = 1;
        lVar5 = __ftol();
        iVar4 = Sound_UpdateListener
                          (this_00,*(uint *)((int)this_00 + 0x1b0) - (uint)lVar5,
                           (*(int *)((int)this_00 + 0x1b4) - (int)((ulonglong)lVar5 >> 0x20)) -
                           (uint)(*(uint *)((int)this_00 + 0x1b0) < (uint)lVar5),iVar4);
      }
    }
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}

