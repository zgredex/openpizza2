// rea decompile_all
// name: FUN_0052c400
// address: 0x52c400
// body: available
// range: 0x52c400-0x52c461 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0052c400(int param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = 0;
  pcVar4 = *(char **)(param_1 + 0x74);
  if (*pcVar4 == '\0') {
    return 0;
  }
  do {
    cVar2 = *pcVar4;
    pcVar6 = pcVar4;
    while (((cVar2 != '\0' && (cVar2 != '\n')) && (cVar2 != '\r'))) {
      pcVar1 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar1;
    }
    cVar2 = *pcVar6;
    if (cVar2 == '\0') {
      iVar3 = FUN_005355f0(*(void **)(param_1 + 0x54),pcVar4);
      pcVar4 = pcVar6;
    }
    else {
      *pcVar6 = '\0';
      iVar3 = FUN_005355f0(*(void **)(param_1 + 0x54),pcVar4);
      *pcVar6 = cVar2;
      pcVar4 = pcVar6 + 1;
    }
    if (iVar5 < iVar3) {
      iVar5 = iVar3;
    }
  } while (*pcVar4 != '\0');
  return iVar5;
}

