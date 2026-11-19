// rea decompile_all
// name: FUN_004fd0f0
// address: 0x4fd0f0
// body: available
// range: 0x4fd0f0-0x4fd184 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004fd0f0(int param_1,void *param_2,void *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00486be0(DAT_0057c670,0);
  iVar1 = *(int *)((int)param_3 + 0x48);
  if ((-1 < iVar1) && (iVar1 < 4)) {
    iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
  }
  if (param_5 == 0) {
    uVar2 = 4;
  }
  else {
    uVar2 = 6;
  }
  FUN_004d77b0(param_2,param_3,uVar2,param_1,(void *)0x1c,iVar1 + 0x818 + param_4 * 4);
  *(undefined4 *)(*(int *)((int)param_2 + 0xfa8) + 0xf4) = 1;
  *(undefined4 *)((int)param_3 + 0x4c) = 0;
  *(undefined4 *)((int)param_3 + 0x50) = 0;
  iVar1 = FUN_00488be0(DAT_0057c670,param_1);
  *(void **)(iVar1 + 0x1d8) = param_3;
  Window_UnlockState((int)DAT_0057c670);
  return;
}

