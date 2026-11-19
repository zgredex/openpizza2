// rea decompile_all
// name: Stats_ResetAverages
// address: 0x4805d0
// body: available
// range: 0x4805d0-0x480686 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Stats_ResetAverages(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  puVar5 = (undefined4 *)((int)param_1 + 0x1a08);
                    /* Clears the six-slot statistic accumulator. */
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar3 = *(int *)((int)param_1 + 0x1514);
  iVar6 = 0;
  if (0 < iVar3) {
    do {
      piVar1 = (int *)FUN_004017f0((void *)((int)param_1 + 0x1500),iVar6,(int *)0x0);
      if (*(char *)(*piVar1 + 0x824) == '\0') {
        iVar4 = 9;
        iVar2 = piVar1[1] * 3;
        do {
          *(undefined1 *)((int)param_1 + 0x1a08 + iVar2) = 1;
          iVar2 = iVar2 + 1;
          if (0x17 < iVar2) {
            iVar2 = 0;
          }
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
  }
  if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)(DAT_0057c670 + 0x264),-0x18693,0x23,0);
  }
  if (*(void **)(DAT_0057c670 + 0x25c) != (void *)0x0) {
    FUN_005301c0(*(void **)(DAT_0057c670 + 0x25c),-0x18693,0x23,0);
  }
  FUN_00478880(param_1);
  return;
}

