// rea decompile_all
// name: AI_ComputePath
// address: 0x4f50d0
// body: available
// range: 0x4f50d0-0x4f5255 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 AI_ComputePath(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int *piVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  undefined1 unaff_retaddr;
  int iVar8;
  int in_stack_00003e98;
  int in_stack_00003e9c;
  int in_stack_00003ea0;
  
                    /* Computes an AI movement path across the grid. */
  FUN_0054f110(unaff_retaddr);
  iVar2 = 0;
  param_1 = 0;
  iVar8 = 0;
  if (in_stack_00003e98 == 0) {
    param_2 = 0;
  }
  param_4 = 0;
  if (0 < *(int *)(extraout_ECX + 0x20)) {
    do {
      param_3 = 0;
      if (0 < *(int *)(extraout_ECX + 0x1c)) {
        iVar6 = param_1 * 0xc;
        piVar4 = (int *)(&param_5 + iVar2 * 4);
        iVar2 = iVar8;
        do {
          iVar8 = *(int *)(*(int *)(extraout_ECX + 0x4c) + 8 + iVar6);
          piVar5 = piVar4;
          if (iVar8 != 0) {
            iVar1 = *(int *)(iVar8 + 4);
            bVar7 = iVar1 == 0x34e;
            if ((in_stack_00003e9c != 0) && (iVar1 == 0x352)) {
              bVar7 = true;
            }
            if (((in_stack_00003ea0 != 0) && (iVar1 == 0x355)) || (bVar7)) {
              if ((in_stack_00003e98 != 0) &&
                 ((*(int *)(iVar8 + 0x10) < 0x19 || (param_2 = 1, 0x20 < *(int *)(iVar8 + 0x10)))))
              {
                param_2 = 0;
              }
              if (((*(short *)(iVar8 + 0x24) != -1) && (*(int *)(iVar8 + 0x28) != 0)) &&
                 (param_2 == 0)) {
                piVar5 = piVar4 + 1;
                *piVar4 = *(int *)(extraout_ECX + 0x9c) + *(short *)(iVar8 + 0x24) * 0x28;
                iVar2 = iVar2 + 1;
                if (3999 < iVar2) {
                  FUN_0048e0a0();
                }
              }
            }
          }
          param_1 = param_1 + 1;
          iVar6 = iVar6 + 0xc;
          param_3 = param_3 + 1;
          piVar4 = piVar5;
        } while (param_3 < *(int *)(extraout_ECX + 0x1c));
        iVar8 = iVar2;
      }
      param_4 = param_4 + 1;
    } while (param_4 < *(int *)(extraout_ECX + 0x20));
    if (0 < iVar2) {
      uVar3 = FUN_004034d0(0,iVar2 - 1);
      return *(undefined4 *)(&param_5 + uVar3 * 4);
    }
  }
  return 0;
}

