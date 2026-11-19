// rea decompile_all
// name: Object_InsertSortedByScreenY
// address: 0x4ef110
// body: available
// range: 0x4ef110-0x4ef1b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_InsertSortedByScreenY(void *this,int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_4;
  
  piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x20);
  if (piVar3 == (int *)0x0) {
    *(int **)(*(int *)(param_1 + 8) + 0x20) = param_2;
    param_2[0x1b] = 0;
    return;
  }
  local_4 = (int *)0x0;
  piVar1 = Record_GetScreenSortY(this,piVar3);
  piVar2 = Record_GetScreenSortY(this,param_2);
  if ((int)piVar1 <= (int)piVar2) {
    do {
      local_4 = piVar3;
      piVar3 = (int *)local_4[0x1b];
      if (piVar3 == (int *)0x0) {
        local_4[0x1b] = (int)param_2;
        param_2[0x1b] = 0;
        return;
      }
      piVar1 = Record_GetScreenSortY(this,piVar3);
      piVar2 = Record_GetScreenSortY(this,param_2);
    } while ((int)piVar1 <= (int)piVar2);
  }
  param_2[0x1b] = (int)piVar3;
  if (local_4 == (int *)0x0) {
    *(int **)(*(int *)(param_1 + 8) + 0x20) = param_2;
    return;
  }
  local_4[0x1b] = (int)param_2;
  return;
}

