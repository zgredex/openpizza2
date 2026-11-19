// rea decompile_all
// name: FUN_0054b070
// address: 0x54b070
// body: available
// range: 0x54b070-0x54b10b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0054b070(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_24 [9];
  
  piVar2 = local_24;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  iVar5 = 0;
  *param_1 = *(int *)((int)this + 0x20);
  iVar3 = *(int *)((int)this + 0x18);
  if (0 < iVar3) {
    do {
      iVar1 = IDMap_Lookup((void *)((int)this + 4),iVar5,(int *)0x0);
      if (*(int *)(iVar1 + 8) != -1) {
        iVar4 = *(int *)(iVar1 + 8) - *(int *)((int)this + 0x2c);
        if ((-1 < iVar4) && (iVar4 < 9)) {
          local_24[iVar4] = 1;
        }
        iVar1 = *(int *)(iVar1 + 0xc) + *(int *)((int)this + 0x28);
        if (*param_1 < iVar1) {
          *param_1 = iVar1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  iVar3 = 0;
  piVar2 = local_24;
  do {
    if (*piVar2 == 0) {
      return *(int *)((int)this + 0x2c) + iVar3;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 9);
  return -1;
}

