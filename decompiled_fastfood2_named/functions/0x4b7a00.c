// rea decompile_all
// name: FUN_004b7a00
// address: 0x4b7a00
// body: available
// range: 0x4b7a00-0x4b7b00 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b7a00(void *param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(*(int *)((int)DAT_0057c670 + 0x9c) + 0x30));
  iVar2 = *(int *)(iVar2 + 0x48);
  FUN_0052fd00(param_1,0x1fae,1000,5000,0);
  DAT_0057d6b0 = *(int *)(*(int *)((int)DAT_0057c670 +
                                  *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x94 +
                         iVar2 * 4);
  bVar1 = DAT_0057d6b0 < 1;
  if (bVar1) {
    DAT_0057d6b0 = 1000;
    FUN_0052fd70(param_1,0x1fae,1000,0);
    DAT_0057d6b4 = 1;
  }
  else {
    DAT_0057d6b4 = 0;
    FUN_0052fd70(param_1,0x1fae,DAT_0057d6b0,0);
  }
  FUN_00531470(param_1,0x1fae,(uint)bVar1);
  FUN_0052f080(param_1,0x1faf,&DAT_005683a4,5000);
  FUN_0052f080(param_1,0x1fad,&DAT_005683a4,1000);
  FUN_0052fdb0(param_1,0x1fae,0x1fac,&DAT_005683a4);
  FUN_0052fce0(param_1,0x1fae,1);
  FUN_004b7430(param_1);
  return;
}

