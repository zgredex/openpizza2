// rea decompile_all
// name: thunk_FUN_00479db0
// address: 0x4781d0
// body: available
// range: 0x4781d0-0x4781d4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __fastcall thunk_FUN_00479db0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  longlong lVar7;
  float fStack_a4;
  float afStack_a0 [20];
  int aiStack_50 [20];
  
  pfVar4 = afStack_a0;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = 0.0;
    pfVar4 = pfVar4 + 1;
  }
  piVar5 = aiStack_50;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar3 = 0;
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x170c)) {
    do {
      iVar1 = FUN_004017f0((void *)(param_1 + 0x16f8),iVar6,(int *)0x0);
      if (iVar1 != 0) {
        iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x74),*(int *)(iVar1 + 4),(int *)0x0);
        afStack_a0[*(int *)(iVar2 + 8)] =
             (float)*(int *)(iVar1 + 0xc) + afStack_a0[*(int *)(iVar2 + 8)];
        iVar3 = iVar3 + 1;
        aiStack_50[*(int *)(iVar2 + 8)] = aiStack_50[*(int *)(iVar2 + 8)] + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x170c));
    param_2 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        iVar6 = *(int *)((int)aiStack_50 + iVar3 + 4);
        if (iVar6 < 1) {
          *(undefined4 *)((int)afStack_a0 + iVar3 + 4) = 0;
        }
        else {
          *(float *)((int)afStack_a0 + iVar3 + 4) =
               *(float *)((int)afStack_a0 + iVar3 + 4) / (float)iVar6;
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0x2c);
      fStack_a4 = (afStack_a0[3] + afStack_a0[5] + afStack_a0[4] + afStack_a0[2] + afStack_a0[1]) *
                  0.2;
      if (0.0 <= fStack_a4) {
        if (100.0 < fStack_a4) {
          fStack_a4 = 100.0;
        }
        lVar7 = FUN_00403850(fStack_a4);
        return lVar7;
      }
      lVar7 = FUN_00403850(0.0);
      return lVar7;
    }
  }
  return (ulonglong)param_2 << 0x20;
}

