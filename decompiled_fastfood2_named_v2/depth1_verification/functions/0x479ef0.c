// rea decompile_all
// name: Game_InitStatBaselines
// address: 0x479ef0
// body: available
// range: 0x479ef0-0x479ff9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_InitStatBaselines(void *this,int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int aiStack_40 [8];
  int aiStack_20 [8];
  
                    /* Depth-1 proposal batch 3/4. */
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x34),(int *)0x0);
  iVar1 = *(int *)((int)this + 0x14d8);
  if (iVar1 == -1) {
    piVar3 = aiStack_20 + param_1;
    *piVar3 = 0;
  }
  else {
    piVar3 = aiStack_20 + param_1;
    if (iVar1 == 8) {
      *piVar3 = *(int *)(iVar2 + 0x1e0 + param_1 * 4);
    }
    else {
      *piVar3 = *(int *)(iVar2 + (param_1 + 0x38 + iVar1 * 8) * 4);
    }
    FUN_00477100(piVar3);
  }
  if ((param_1 < 0) || ((3 < param_1 && (param_1 != 7)))) {
    iVar1 = *(int *)((int)this + 0x186c);
    if (3 < iVar1) {
      piVar4 = aiStack_40 + param_1;
      *piVar4 = 0;
      goto LAB_00479fbb;
    }
    if (iVar1 != 3) {
      if (iVar1 == 2) {
        piVar4 = aiStack_40 + param_1;
        *piVar4 = 0x46;
        goto LAB_00479fbb;
      }
      goto LAB_00479fb1;
    }
    piVar4 = aiStack_40 + param_1;
  }
  else {
    if (1 < *(int *)((int)this + 0x186c)) {
LAB_00479fb1:
      piVar4 = aiStack_40 + param_1;
      *piVar4 = 100;
      goto LAB_00479fbb;
    }
    piVar4 = aiStack_40 + param_1;
    if (*(int *)((int)this + 0x186c) == 1) {
      *piVar4 = 0x46;
      goto LAB_00479fbb;
    }
  }
  *piVar4 = 0x1e;
LAB_00479fbb:
  FUN_00477100(piVar4);
  if (param_2 == '\0') {
    *(int *)((int)this + param_1 * 4 + 0x181c) = (*piVar4 + *piVar3) / 2;
    return;
  }
  *(int *)((int)this + param_1 * 4 + 0x181c) = *piVar3;
  return;
}

