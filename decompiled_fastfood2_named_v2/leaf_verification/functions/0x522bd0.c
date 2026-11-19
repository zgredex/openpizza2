// rea decompile_all
// name: FUN_00522bd0
// address: 0x522bd0
// body: available
// range: 0x522bd0-0x522cad inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00522bd0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined3 extraout_var_01;
  int extraout_ECX;
  int iVar3;
  
  if (*(int *)(param_1 + 0x88) == -999) {
    iVar3 = 0;
    *(undefined4 *)(param_1 + 0x88) = param_3;
    iVar2 = param_1;
    if (0 < *(int *)(param_1 + 0x80)) {
      do {
        uVar1 = Font_GetCharWidth(*(void **)(param_1 + 0x54),
                                  CONCAT31((int3)((uint)param_2 >> 8),
                                           *(undefined1 *)(iVar3 + *(int *)(param_1 + 0x6c))));
        param_2 = *(int *)(param_1 + 0x88) + CONCAT31(extraout_var,uVar1);
        iVar3 = iVar3 + 1;
        *(int *)(param_1 + 0x88) = param_2;
        iVar2 = extraout_ECX;
      } while (iVar3 < *(int *)(param_1 + 0x80));
    }
    if (*(int *)(param_1 + 0x7c) != 0) {
      iVar2 = *(int *)(param_1 + 0x88);
      *(int *)(param_1 + 0x88) = iVar2 + -1;
      *(int *)(param_1 + 0x90) = iVar2 + 1;
      *(int *)(param_1 + 0x8c) = param_4;
      *(int *)(param_1 + 0x94) = *(int *)(*(int *)(param_1 + 0x54) + 0x9b4) + param_4;
      return;
    }
    uVar1 = Font_GetCharWidth(*(void **)(param_1 + 0x54),
                              CONCAT31((int3)((uint)iVar2 >> 8),
                                       *(undefined1 *)(*(int *)(param_1 + 0x6c) + iVar3)));
    iVar2 = CONCAT31(extraout_var_00,uVar1);
    if (iVar2 == 0) {
      uVar1 = UI_GetFirstEnabledIndex(*(int *)(param_1 + 0x54));
      iVar2 = CONCAT31(extraout_var_01,uVar1);
    }
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x88) + iVar2;
    iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x9b4) + param_4;
    *(int *)(param_1 + 0x8c) = iVar2;
    *(int *)(param_1 + 0x94) = iVar2 + 2;
  }
  return;
}

