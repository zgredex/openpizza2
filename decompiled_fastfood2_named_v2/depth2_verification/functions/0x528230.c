// rea decompile_all
// name: FUN_00528230
// address: 0x528230
// body: available
// range: 0x528230-0x5282b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_00528230(void *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  longlong lVar4;
  
  if (*(int *)((int)param_1 + 0x18) == 0) {
    return 0;
  }
  if (*(int *)((int)param_1 + 0x10) == 0) {
    param_2 = *(uint *)((int)param_1 + 0x14);
    iVar3 = param_3 - param_2;
    if (10000 < iVar3) {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
    *(undefined4 *)((int)param_1 + 0x10) = 0;
  }
  *(int *)((int)param_1 + 0x14) = param_3;
  *(int *)((int)param_1 + 0x1c) = *(int *)((int)param_1 + 0x1c) - iVar3;
  iVar1 = *(int *)((int)param_1 + 4);
  if (iVar1 == 0) {
    param_4 = FUN_005282c0(param_1,param_4,iVar3);
  }
  else if (iVar1 == 1) {
    lVar4 = FUN_005283b0((int)param_1,param_2,param_4,iVar3);
    param_4 = (int)lVar4;
  }
  else if (iVar1 == 2) {
    bVar2 = UI_ScrollChildByVelocity(param_1,param_4,iVar3);
    param_4 = CONCAT31(extraout_var,bVar2);
  }
  if (param_4 == 0) {
    *(undefined4 *)((int)param_1 + 0x18) = 0;
  }
  return param_4;
}

