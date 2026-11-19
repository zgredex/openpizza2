// rea decompile_all
// name: FUN_005271d0
// address: 0x5271d0
// body: available
// range: 0x5271d0-0x52724f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005271d0(void *this,int param_1)

{
  int *piVar1;
  LPVOID pvVar2;
  int iVar3;
  LPVOID pvVar4;
  
  pvVar4 = *(LPVOID *)((int)this + 0x82c4);
  pvVar2 = (LPVOID)0x0;
  if (pvVar4 != (LPVOID)0x0) {
    while (*(int *)((int)pvVar4 + 0x104) != param_1) {
      piVar1 = (int *)((int)pvVar4 + 0x10c);
      pvVar2 = pvVar4;
      pvVar4 = (LPVOID)*piVar1;
      if ((LPVOID)*piVar1 == (LPVOID)0x0) {
        return;
      }
    }
    iVar3 = *(int *)((int)pvVar4 + 0x108) + -1;
    *(int *)((int)pvVar4 + 0x108) = iVar3;
    if (iVar3 == 0) {
      if (pvVar2 == (LPVOID)0x0) {
        *(undefined4 *)((int)this + 0x82c4) = *(undefined4 *)((int)pvVar4 + 0x10c);
      }
      else {
        *(undefined4 *)((int)pvVar2 + 0x10c) = *(undefined4 *)((int)pvVar4 + 0x10c);
      }
      pvVar2 = *(LPVOID *)((int)pvVar4 + 0x104);
      if (pvVar2 != (LPVOID)0x0) {
        FUN_005354e0((int)pvVar2);
        FUN_0054dd78(pvVar2);
      }
      FUN_0054dd78(pvVar4);
    }
  }
  return;
}

