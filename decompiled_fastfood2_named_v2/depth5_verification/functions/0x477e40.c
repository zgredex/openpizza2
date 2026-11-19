// rea decompile_all
// name: Game_CanAfford
// address: 0x477e40
// body: available
// range: 0x477e40-0x477f4b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Game_CanAfford(void *this,int param_1,float param_2,char param_3,int param_4)

{
  void *this_00;
  double dVar1;
  int iVar2;
  void *pvVar3;
  longlong lVar4;
  
                    /* Checks whether a player can afford a cost. */
  if (param_3 != '\0') {
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
    dVar1 = *(double *)(iVar2 + 0x108) - (double)param_2;
    if (dVar1 < 0.0) {
      return CONCAT22((short)((uint)iVar2 >> 0x10),
                      (ushort)(dVar1 < 0.0) << 8 | (ushort)NAN(dVar1) << 10 |
                      (ushort)(dVar1 == 0.0) << 0xe);
    }
  }
  iVar2 = FUN_00477c20(this,param_4);
  if (iVar2 != 0) {
    *(float *)(iVar2 + 0x78 + param_1 * 4) = param_2 + *(float *)(iVar2 + 0x78 + param_1 * 4);
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
    *(double *)(iVar2 + 0x108) = *(double *)(iVar2 + 0x108) - (double)param_2;
  }
  pvVar3 = *(void **)((int)DAT_0057c670 + 600);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)FUN_00482820((int)DAT_0057c670);
    if (pvVar3 == *(void **)((int)this + 0x30)) {
      this_00 = *(void **)((int)DAT_0057c670 + 0x2d9c);
      pvVar3 = DAT_0057c670;
      if (this_00 != (void *)0x0) {
        iVar2 = 0;
        lVar4 = __ftol();
        FUN_0054bf70(this_00,(uint)lVar4,(int)((ulonglong)lVar4 >> 0x20),iVar2);
        iVar2 = 1;
        lVar4 = __ftol();
        pvVar3 = (void *)FUN_0054bf70(this_00,*(uint *)((int)this_00 + 0x1b0) - (uint)lVar4,
                                      (*(int *)((int)this_00 + 0x1b4) -
                                      (int)((ulonglong)lVar4 >> 0x20)) -
                                      (uint)(*(uint *)((int)this_00 + 0x1b0) < (uint)lVar4),iVar2);
      }
    }
    if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
      pvVar3 = (void *)FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18648,0x23,0);
    }
  }
  return CONCAT31((int3)((uint)pvVar3 >> 8),1);
}

