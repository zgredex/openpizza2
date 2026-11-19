// rea decompile_all
// name: FUN_004f0c60
// address: 0x4f0c60
// body: available
// range: 0x4f0c60-0x4f0cbb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004f0c60(void *this,int *param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  int *local_4;
  
  local_4 = this;
  Object_GetBufferPair
            (this,(int)param_1,(int *)&local_4,(int *)&param_1,(undefined4 *)0x0,(undefined4 *)0x0);
  iVar1 = 0;
  if (0 < *param_1) {
    puVar2 = (ushort *)(*local_4 + 2);
    do {
      if (*puVar2 == param_2) {
        return *local_4 + iVar1 * 0x28;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x14;
    } while (iVar1 < *param_1);
  }
  return 0;
}

