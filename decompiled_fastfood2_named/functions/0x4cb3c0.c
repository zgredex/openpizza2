// rea decompile_all
// name: FUN_004cb3c0
// address: 0x4cb3c0
// body: available
// range: 0x4cb3c0-0x4cb47e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cb3c0(void *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = param_2;
  iVar2 = param_2 + -1;
  uVar4 = param_3 & 0xff;
  FUN_005316f0(param_1,param_2 + 0x440 + iVar2,uVar4);
  FUN_005316f0(param_1,param_2 + 0x441 + iVar2,uVar4);
  iVar3 = iVar2 * 8 + 0x454;
  param_2 = 8;
  do {
    FUN_005316f0(param_1,iVar3,uVar4);
    iVar3 = iVar3 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  FUN_005316f0(param_1,iVar2 * 4 + 0x4c0,uVar4);
  FUN_005316f0(param_1,iVar2 * 4 + 0x4c2,uVar4);
  FUN_005316f0(param_1,iVar1 + 0x4db,uVar4);
  FUN_005316f0(param_1,*(int *)(&DAT_0056b2dc + iVar2 * 4),uVar4);
  FUN_005316f0(param_1,*(int *)(&DAT_0056b2f0 + iVar2 * 4),uVar4);
  FUN_005316f0(param_1,*(int *)(&DAT_0056b304 + iVar2 * 4),uVar4);
  return;
}

