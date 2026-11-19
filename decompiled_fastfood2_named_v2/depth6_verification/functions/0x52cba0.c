// rea decompile_all
// name: FUN_0052cba0
// address: 0x52cba0
// body: available
// range: 0x52cba0-0x52cbee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0052cba0(void *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = *param_2;
  if ((*(char *)(iVar3 + (int)param_1) != '}') && (*(char *)(iVar3 + (int)param_1) != '\0')) {
    cVar2 = *(char *)(iVar3 + (int)param_1);
    iVar5 = iVar3;
    while (('/' < cVar2 && (cVar2 < ':'))) {
      iVar1 = iVar5 + 1;
      iVar5 = iVar5 + 1;
      cVar2 = *(char *)(iVar1 + (int)param_1);
    }
    if (iVar5 != iVar3) {
      uVar4 = FUN_0054e157(param_1,(byte *)(iVar3 + (int)param_1));
      *param_2 = iVar5;
      return uVar4;
    }
  }
  return 0xffffffff;
}

