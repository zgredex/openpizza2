// rea decompile_all
// name: Game_ResetLargeState
// address: 0x478db0
// body: available
// range: 0x478db0-0x478ea8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Game_ResetLargeState(void)

{
  int *piVar1;
  void *this;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_res0;
  
                    /* Clears a large game-state block. */
  FUN_0054f110(local_res0);
  puVar3 = (undefined4 *)register0x00000010;
  for (iVar2 = 0x3200; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)((int)this + 0x1718) = 1;
  FUN_004fbae0(*(void **)((int)this + 0x14e0),(undefined4 *)&local_res0);
  FUN_00479120((int)this);
  FUN_004791e0(this);
  FUN_00479290((int)this);
  iVar2 = FUN_004793b0(this,(int)&local_res0);
  FUN_004795e0(this,(int)&local_res0);
  FUN_00479620(this,iVar2,(int)&local_res0);
  FUN_00479960(this,(int)&local_res0);
  FUN_00479a40(this);
  FUN_00479ab0(this);
  FUN_00479ae0((int)this,extraout_EDX);
  FUN_0048e0a0();
  FUN_00479ca0(this,(int)&local_res0);
  FUN_00478eb0((int)this);
  FUN_00478f60((int)this);
  piVar1 = (int *)((int)this + 0x17fc);
  iVar2 = 8;
  do {
    iVar4 = *piVar1 - *(int *)((int)this + 0x1878);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      *piVar1 = 0;
    }
    if (100 < *piVar1) {
      *piVar1 = 100;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

