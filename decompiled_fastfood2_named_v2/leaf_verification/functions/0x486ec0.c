// rea decompile_all
// name: FUN_00486ec0
// address: 0x486ec0
// body: available
// range: 0x486ec0-0x486f13 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00486ec0(void *this,int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = param_1 + -1;
  if (iVar1 != -1) {
    do {
      bVar3 = param_1 < 0;
      param_1 = iVar1;
      if (SBORROW4(iVar1,-1) != bVar3) {
        param_1 = 5;
      }
      iVar1 = Game_GetPlayerBySlot(this,param_1);
      if ((iVar1 != 0) &&
         ((param_2 != '\0' ||
          (iVar1 = *(int *)(iVar1 + 0x48), iVar2 = Game_GetCurrentPlayerCompanyName((int)this),
          iVar1 != iVar2)))) {
        return param_1;
      }
      iVar1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return -1;
}

