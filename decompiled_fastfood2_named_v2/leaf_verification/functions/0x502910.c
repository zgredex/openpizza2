// rea decompile_all
// name: FUN_00502910
// address: 0x502910
// body: available
// range: 0x502910-0x502988 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00502910(int param_1)

{
  uint uVar1;
  uint uVar2;
  void *this;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  uVar1 = *(uint *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uVar2 = *(uint *)(uVar1 + 0x15c);
  uVar4 = uVar1;
  if (0 < (int)uVar2) {
    do {
      this = (void *)IDMap_Lookup((void *)(uVar1 + 0x148),iVar5,(int *)0x0);
      iVar6 = 0;
      do {
        iVar3 = FUN_00478320(this,iVar6);
        if (param_1 < iVar3) {
          return CONCAT31((int3)((uint)iVar3 >> 8),1);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
      iVar5 = iVar5 + 1;
      uVar4 = uVar2;
    } while (iVar5 < (int)uVar2);
  }
  return uVar4 & 0xffffff00;
}

