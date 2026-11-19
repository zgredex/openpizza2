// rea decompile_all
// name: FUN_004867e0
// address: 0x4867e0
// body: available
// range: 0x4867e0-0x48690c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004867e0(void *this,char *param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  
  piVar3 = (int *)((int)this + 0x200);
  iVar5 = 6;
  do {
    if (*piVar3 != 0) {
      Stats_AppendPeriodReport(*piVar3);
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = *(int *)((int)this + 0x34);
  iVar2 = 0;
  if (0 < iVar5) {
    do {
      iVar1 = FUN_004017f0((void *)((int)this + 0x20),iVar2,(int *)0x0);
      if (iVar1 != 0) {
        FUN_004d4480(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  piVar3 = (int *)((int)this + 0x224);
  iVar5 = 6;
  do {
    if (*piVar3 != 0) {
      FUN_004edbc0();
    }
    piVar3 = piVar3 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar2 = 0;
  iVar5 = *(int *)((int)this + 0x18);
  if (0 < iVar5) {
    do {
      this_00 = (void *)FUN_004017f0((void *)((int)this + 4),iVar2,(int *)0x0);
      if (this_00 != (void *)0x0) {
        FUN_004da480(this_00,(int)param_1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar5);
  }
  iVar5 = 6;
  puVar4 = (undefined4 *)((int)this + 0x200);
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      FUN_004de760((void *)*puVar4,param_1);
    }
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 6;
  puVar4 = (undefined4 *)((int)this + 0x200);
  do {
    if ((undefined4 *)*puVar4 != (undefined4 *)0x0) {
      FUN_004dec10((undefined4 *)*puVar4);
    }
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_00486960((int)this);
  FUN_0054a660(DAT_0057c1e0,0xff,(byte *)s_EndofQuarter___d___0056813c,
               (uint)*(ushort *)(*(int *)((int)this + 0x94) + 10));
  if (*(void **)((int)this + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)this + 0x264),-0x1863c,0x23,0);
  }
  return;
}

