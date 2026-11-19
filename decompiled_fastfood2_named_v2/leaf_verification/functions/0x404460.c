// rea decompile_all
// name: FUN_00404460
// address: 0x404460
// body: available
// range: 0x404460-0x4044fb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00404460(void *param_1)

{
  DWORD DVar1;
  uint uVar2;
  CHAR local_104 [260];
  
  FUN_0054dd83(local_104,(byte *)s__sresources__s_00563a50,&DAT_0057c278);
  DVar1 = GetFileAttributesA(local_104);
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) == 0)) {
LAB_004044d2:
    FUN_00401af0(param_1,local_104);
    return 1;
  }
  FUN_0054dd83(local_104,(byte *)s__c__resources__s_00563a3c,(int)DAT_0057c5c4);
  DVar1 = GetFileAttributesA(local_104);
  if (DVar1 != 0xffffffff) {
    uVar2 = DVar1 & 0x8000000f;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
    }
    if (uVar2 == 0) goto LAB_004044d2;
  }
  return 0;
}

