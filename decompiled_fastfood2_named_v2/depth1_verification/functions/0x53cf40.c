// rea decompile_all
// name: FUN_0053cf40
// address: 0x53cf40
// body: available
// range: 0x53cf40-0x53d033 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0053cf40(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055adc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_0055c82c;
  local_4 = 0;
  if (*(char *)(param_1 + 0xd) == '\x01') {
    puVar1 = (undefined4 *)param_1[8];
    if (((puVar1 != (undefined4 *)0x0) && (*(short *)((int)puVar1 + 0x206) == -1)) &&
       (puVar1 != (undefined4 *)0x0)) {
      Palette_Free(puVar1);
      FUN_0054dd78(puVar1);
    }
  }
  else {
    iVar2 = 0;
    if (*(char *)(param_1 + 0xd) != '\0') {
      do {
        puVar1 = *(undefined4 **)(param_1[9] + iVar2 * 4);
        if (((puVar1 != (undefined4 *)0x0) && (*(short *)((int)puVar1 + 0x206) == -1)) &&
           (puVar1 != (undefined4 *)0x0)) {
          Palette_Free(puVar1);
          FUN_0054dd78(puVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0xd));
    }
  }
  if ((LPVOID)param_1[0xb] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0xb]);
  }
  if ((LPVOID)param_1[0xc] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0xc]);
  }
  if ((LPVOID)param_1[0xf] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[0xf]);
  }
  if ((LPVOID)param_1[9] != (LPVOID)0x0) {
    FUN_0054dd78((LPVOID)param_1[9]);
  }
  local_4 = 0xffffffff;
  FUN_0053a210(param_1);
  ExceptionList = local_c;
  return;
}

