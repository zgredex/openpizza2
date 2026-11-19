// rea decompile_all
// name: Sprite_ClearBuffers
// address: 0x53a060
// body: available
// range: 0x53a060-0x53a100 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Sprite_ClearBuffers(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_de [14];
  undefined4 local_d0 [25];
  undefined4 auStack_6c [27];
  
  puVar2 = local_d0;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_d0[0] = 0x6c;
  local_d0[1] = 6;
  (**(code **)(*param_1 + 0x58))(param_1,local_d0);
  puVar2 = auStack_6c;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  auStack_6c[0] = 100;
  (**(code **)(*param_1 + 0x14))(param_1,auStack_de + -10,0,auStack_de + -10,0x1000400,auStack_6c);
  return;
}

