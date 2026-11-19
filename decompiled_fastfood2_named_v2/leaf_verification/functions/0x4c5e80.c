// rea decompile_all
// name: FUN_004c5e80
// address: 0x4c5e80
// body: available
// range: 0x4c5e80-0x4c5fbf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c5e80(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)DAT_0057c670 + DAT_0057dd00 * 4 + 0x224);
  iVar3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar1 + 8));
  iVar2 = *(int *)((int)DAT_0057c670 + 0x90);
  FUN_004a66d0(param_1,0x1f4f,iVar3);
  FUN_0052f9b0(param_1,0x1f4c,iVar3 + 8);
  FUN_0052ff50(param_1,0x1f53,*(int *)(iVar2 + 0x114 + DAT_0057dd00 * 0x168));
  FUN_0052f080(param_1,0x1f56,(byte *)s___2lf_0056b0d4,(int)*(undefined8 *)(iVar3 + 0x108));
  FUN_0052fd70(param_1,0x1f55,(int)*(short *)(iVar2 + 0x128 + DAT_0057dd00 * 0x168),0);
  FUN_0052fd70(param_1,0x1f62,(int)*(short *)(iVar2 + 0x130 + DAT_0057dd00 * 0x168),0);
  FUN_0052f080(param_1,0x1f5e,&DAT_005686f4,DAT_0057dd00);
  FUN_0052f080(param_1,0x1f5f,&DAT_005686f4,*(undefined4 *)(iVar1 + 8));
  if (*(int *)(iVar2 + 300 + DAT_0057dd00 * 0x168) == 0x18) {
    FUN_0052f830(param_1,0x1f5a,s_reset_0056b0cc);
    return;
  }
  FUN_0052f830(param_1,0x1f5a,&DAT_00566cd8);
  return;
}

