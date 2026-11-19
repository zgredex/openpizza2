// rea decompile_all
// name: FUN_0047ca80
// address: 0x47ca80
// body: available
// range: 0x47ca80-0x47cb66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong __fastcall FUN_0047ca80(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int iVar4;
  ulonglong uVar5;
  float local_c;
  int local_8;
  
  iVar4 = 0;
  local_8 = 0;
  local_c = 0.0;
  iVar2 = *(int *)(param_1 + 0x170c);
  if (0 < *(int *)(param_1 + 0x170c)) {
    do {
      iVar2 = FUN_004017f0((void *)(param_1 + 0x16f8),iVar4,(int *)0x0);
      param_2 = extraout_EDX;
      if (iVar2 != 0) {
        cVar1 = Game_GetPlayerByte8(iVar2);
        param_2 = extraout_EDX_00;
        if (cVar1 == param_3) {
          uVar3 = Game_GetRecordByte14(iVar2);
          local_8 = local_8 + 1;
          local_c = (float)(int)uVar3 + local_c;
          param_2 = extraout_EDX_01;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x170c));
    iVar2 = local_8;
    if (0 < local_8) {
      local_c = local_c / (float)local_8;
      if (2.0 < local_c) {
        uVar5 = Math_RoundFloat(2.0);
        return uVar5;
      }
      if (local_c < 0.0) {
        local_c = 0.0;
      }
      uVar5 = Math_RoundFloat(local_c);
      return uVar5;
    }
  }
  return CONCAT44(param_2,iVar2) & 0xffffffffffffff00;
}

