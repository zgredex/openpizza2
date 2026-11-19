// rea decompile_all
// name: Game_CountObjectsByType
// address: 0x47aac0
// body: available
// range: 0x47aac0-0x47ab1a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_CountObjectsByType(void *this,uint param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x1514)) {
    do {
      piVar1 = (int *)IDMap_Lookup((void *)((int)this + 0x1500),iVar3,(int *)0x0);
      if ((param_1 == *(byte *)(*piVar1 + 0x824)) || (param_1 == 0xffffffff)) {
        local_4 = local_4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)this + 0x1514));
    iVar2 = local_4;
  }
  return iVar2;
}

