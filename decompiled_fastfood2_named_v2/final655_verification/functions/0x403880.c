// rea decompile_all
// name: FUN_00403880
// address: 0x403880
// body: available
// range: 0x403880-0x403951 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_00403880(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  pcVar4 = (char *)*param_1;
  iVar6 = 0;
  cVar1 = *pcVar4;
  if (cVar1 != '\0') {
    iVar5 = *param_2 - (int)pcVar4;
    do {
      iVar3 = (int)pcVar4[iVar5];
      iVar2 = (int)cVar1;
      if ((iVar2 == -0x3c) || (iVar2 == -0x1c)) {
        iVar2 = 0x61;
      }
      else if ((iVar2 == -0x2a) || (iVar2 == -10)) {
        iVar2 = 0x6f;
      }
      else if ((iVar2 == -0x24) || (iVar2 == -4)) {
        iVar2 = 0x75;
      }
      if ((iVar3 == -0x3c) || (iVar3 == -0x1c)) {
        iVar3 = 0x61;
      }
      else if ((iVar3 == -0x2a) || (iVar3 == -10)) {
        iVar3 = 0x6f;
      }
      else if ((iVar3 == -0x24) || (iVar3 == -4)) {
        iVar3 = 0x75;
      }
      if ((0x40 < iVar2) && (iVar2 < 0x5b)) {
        iVar2 = iVar2 + 0x20;
      }
      if ((0x40 < iVar3) && (iVar3 < 0x5b)) {
        iVar3 = iVar3 + 0x20;
      }
      if (iVar2 != iVar3) {
        return ((iVar3 <= iVar2) - 1 & 0xfffffffe) + 1;
      }
      cVar1 = pcVar4[1];
      iVar6 = iVar6 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  return -(uint)(*(char *)(*param_2 + iVar6) != '\0');
}

