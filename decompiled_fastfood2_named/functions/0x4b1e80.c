// rea decompile_all
// name: FUN_004b1e80
// address: 0x4b1e80
// body: available
// range: 0x4b1e80-0x4b1f3f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b1e80(void *param_1)

{
  void *this;
  int iVar1;
  int *piVar2;
  int iVar3;
  
  this = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),DAT_0056a6d8,(int *)0x0);
  iVar1 = FUN_0047aac0(this,0xffffffff);
  if (7 < iVar1) {
    iVar1 = 7;
  }
  if (DAT_0056a6d4 != -1) {
    piVar2 = (int *)FUN_005313d0(param_1,DAT_0056a6d4 + 0x57d);
    (**(code **)(*piVar2 + 0xc))(1,0,0);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (DAT_0057d688 + iVar3 == DAT_0056a6d0) {
        DAT_0056a6d4 = iVar3;
        piVar2 = (int *)FUN_005313d0(param_1,iVar3 + 0x57d);
        (**(code **)(*piVar2 + 0xc))(1,2,0);
      }
      piVar2 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),DAT_0057d688 + iVar3,(int *)0x0);
      FUN_004b10e0(param_1,iVar3,piVar2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

