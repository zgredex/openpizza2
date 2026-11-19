// rea decompile_all
// name: Company_GenerateNameFromTopProduct
// address: 0x513a90
// body: available
// range: 0x513a90-0x513af6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Company_GenerateNameFromTopProduct(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_EDI;
  int iVar5;
  char local_50 [80];
  
  iVar4 = 0;
  iVar2 = 0;
  piVar3 = (int *)((int)this + 100);
  iVar5 = param_1;
  do {
    if (((iVar2 != 0) && (iVar1 = *piVar3, 0 < iVar1)) && (iVar4 < iVar1)) {
      iVar4 = iVar1;
      iVar5 = iVar2;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 0x56);
  String_Format(local_50,(byte *)(*(int *)(DAT_0057c670 + 0xa8 + iVar5 * 4) + 0x88),unaff_EDI);
  Company_GenerateUniqueName(param_1,this,local_50);
  return;
}

