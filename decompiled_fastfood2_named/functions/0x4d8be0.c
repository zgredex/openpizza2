// rea decompile_all
// name: FUN_004d8be0
// address: 0x4d8be0
// body: available
// range: 0x4d8be0-0x4d8c78 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004d8be0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_004f0cc0(*(void **)((int)this + 0xfa8),1,*(int *)(param_1 + 0x54));
  iVar4 = 0;
  param_1 = 0;
  iVar3 = 10000000;
  iVar1 = 0;
  if (0 < *(int *)((int)this + 0xfc0)) {
    do {
      iVar1 = IDMap_Lookup((void *)((int)this + 0xfac),iVar4,(int *)0x0);
      if ((*(int *)(iVar1 + 4) == 2) && (*(int *)(iVar1 + 0x54) != -1)) {
        FUN_004f0cc0(*(void **)((int)this + 0xfa8),1,*(int *)(iVar1 + 0x54));
        iVar2 = FUN_004f14a0();
        if (iVar2 < iVar3) {
          iVar3 = iVar2;
          param_1 = iVar1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0xfc0));
    iVar1 = param_1;
  }
  return iVar1;
}

