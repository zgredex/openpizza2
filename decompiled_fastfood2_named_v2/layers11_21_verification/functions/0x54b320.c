// rea decompile_all
// name: FUN_0054b320
// address: 0x54b320
// body: available
// range: 0x54b320-0x54b383 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0054b320(void *this,int param_1,int param_2)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this_00 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                 (int *)0x0);
  iVar2 = FUN_004d7e90(this_00,param_2);
  iVar1 = *(int *)((int)this + 0x18);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = FUN_004017f0((void *)((int)this + 4),iVar4,(int *)0x0);
      if ((*(int *)(iVar3 + 0x34) == param_1) && (*(int *)(iVar3 + 0x30) == iVar2)) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return 0;
}

