// rea decompile_all
// name: FUN_004bd340
// address: 0x4bd340
// body: available
// range: 0x4bd340-0x4bd446 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bd340(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  FUN_005499f0(DAT_0057ba0c,0x17,0,'\x01');
  DAT_0057d6fc = *(undefined4 *)(DAT_0057c670 + 0x21c);
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar2 = FUN_004ddcc0((int)this);
  iVar1 = *(int *)(iVar2 + 0x68);
  iVar2 = *(int *)(iVar2 + 0x50);
  FUN_0052f080(param_1,0x1f76,(byte *)s__s__d_00568964,DAT_00581044);
  puVar3 = FUN_004e25b0(this,0x17,0);
  FUN_0052f080(param_1,0x1f68,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x17,1);
  FUN_0052f080(param_1,0x1f67,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(this,0x17,2);
  FUN_0052f080(param_1,0x1f54,&DAT_005686f4,puVar3);
  FUN_0052f080(param_1,0x1f74,&DAT_005683a4,(((iVar1 + iVar2) * -0x1e + 100) * 500) / 100);
  FUN_004bd230(param_1);
  return;
}

