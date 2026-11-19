// rea decompile_all
// name: FUN_004d2d80
// address: 0x4d2d80
// body: available
// range: 0x4d2d80-0x4d2e01 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d2d80(void *this,void *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  FUN_00401320(*(int *)(DAT_0057c670 + 0x240));
  puVar1 = (uint *)(*(int *)((int)param_1 + 0x4c) + *(int *)((int)this + 0x24) * 0xc);
  if (puVar1 != (uint *)0x0) {
    uVar2 = *(uint *)(puVar1[2] + 0x1c);
    if (uVar2 == 0xffffffff) {
      FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
      return;
    }
    *(uint *)(puVar1[2] + 0x1c) = ~param_2 & uVar2;
    if (*(int *)(puVar1[2] + 0x1c) == 0) {
      *(undefined4 *)(puVar1[2] + 0x1c) = 0xffffffff;
    }
    Map_RenderObject(param_1,puVar1,1);
  }
  FUN_00401340(*(int *)(DAT_0057c670 + 0x240));
  return;
}

