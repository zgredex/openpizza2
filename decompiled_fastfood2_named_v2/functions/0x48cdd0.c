// rea decompile_all
// name: FUN_0048cdd0
// address: 0x48cdd0
// body: available
// range: 0x48cdd0-0x48ce62 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0048cdd0(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_8;
  
  puVar5 = param_2;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar3 = 0;
  local_8 = 0;
  if (*(int *)((int)this + 0x50) < 1) {
    return 0;
  }
  do {
    iVar1 = IDMap_Lookup((void *)((int)this + 0x3c),iVar3,(int *)0x0);
    if (*(int *)(iVar1 + 0x30) < 8) {
      piVar4 = (int *)(iVar1 + 0xd4);
      piVar2 = param_2 + *(int *)(iVar1 + 0x30);
      iVar1 = 8;
      do {
        if (*piVar4 == param_1) {
          *piVar2 = *piVar2 + 1;
          local_8 = local_8 + 1;
        }
        piVar4 = piVar4 + 1;
        piVar2 = piVar2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < *(int *)((int)this + 0x50));
  return local_8;
}

