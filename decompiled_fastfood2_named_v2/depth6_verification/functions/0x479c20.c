// rea decompile_all
// name: FUN_00479c20
// address: 0x479c20
// body: available
// range: 0x479c20-0x479c97 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_00479c20(void *param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)((int)param_1 + 0x34),(int *)0x0);
  bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  if (bVar1 == 3 || bVar1 < 3) {
    cVar3 = *(char *)(iVar4 + 0xa4 + (uint)bVar1 * 4);
  }
  else {
    cVar3 = '\0';
  }
  iVar4 = (int)cVar3;
  if (iVar4 < 0x10) {
    iVar5 = FUN_0047ccd0(param_1,6);
    iVar2 = *(int *)((int)param_1 + 0x38);
    if ((-1 < iVar2) && (iVar2 < 3)) {
      iVar4 = iVar4 + *(int *)(&DAT_005675ac + iVar2 * 4) * iVar5;
    }
    if (iVar4 < 0x10) {
      return 1;
    }
  }
  return 0;
}

