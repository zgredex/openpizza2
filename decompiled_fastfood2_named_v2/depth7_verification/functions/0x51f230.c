// rea decompile_all
// name: FUN_0051f230
// address: 0x51f230
// body: available
// range: 0x51f230-0x51f2a5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0051f230(undefined4 *param_1)

{
  void *this;
  int iVar1;
  byte *pbVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055a558;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_0055c704;
  local_4 = 0;
  pbVar2 = (byte *)(param_1 + 0x15);
  iVar1 = 4;
  this = *(void **)(param_1[2] + 0x134);
  do {
    if (*(int *)(pbVar2 + 0x40) != 0) {
      FUN_005277d0(this,pbVar2);
    }
    pbVar2 = pbVar2 + 0x44;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  local_4 = 0xffffffff;
  UI_Child_Destroy(param_1);
  ExceptionList = local_c;
  return;
}

